from LMT.formal_lf.variable import Variable
from LMT.include.codegen import *
import os, math, sys, string

class Element:
    def __init__(self,name_elem,dim,incpaths=['.','LMT/formulations','formulations'],name_file=None):
      """ Formal element """
      if not name_file:
        name_file = 'element_'+name_elem+'.py'
        for inc in [""]+incpaths:
            if inc: inc += "/"
            if os.access( inc+name_file, os.F_OK ):
                name_file = inc+name_file
                break
        else:
            raise NameError, 'impossible to find %s in %s'%(name_file,incpaths)

      

      val = [symbol('val['+str(i)+']') for i in range(256)]
      dict_e = {
        "Variable" : Variable,
        "nb_var_inter" : 0,
        "nb_nodes" : 0,
        "gauss_points" : {},
        "children_nb_if_sub_integration" : [],
        "children" : [],
        "var_inter" : [symbol('var_inter['+str(i)+']','\eta_{'+str(i)+'}') for i in range(5)],
        "val" : val,
        "interpolation" : {'global':val[0],'gauss':val[0],'Flat_Interpolation':val[0],'elementary':val[0],'skin_elementary':val[0],\
            'elementary_mul_nb_nodes':val[0],'elementary_mul_nb_nodes_of_each_children_elem':val[0]},
        "dim" : dim,
        "max_dim" : 3,
        "has_make_structured" : False,
        "has_extrapolation" : False,
        "authorized_permutations" : [],
        "can_directly_be_represented_by" : "",
        "Flat_Interpolation_gauss_points" : {},
      }
      execfile( name_file, globals(), dict_e )
      
      self.name = name_elem
      self.name_file = name_file
      for n,i in dict_e.items():
        setattr( self, n, i )
      self.nb_nodes = len(self.permutation)
      self.nb_var_inter = len(self.interval_var_inter)
      self.var_inter = self.var_inter[:self.nb_var_inter]

      self.std_map = {
        "dim":self.dim,
        "name_elem":self.name,
        "nb_var_inter":len(self.interval_var_inter),
        "nb_nodes":self.nb_nodes,
      }
      # position
      self.positions = []
      self.normals = []
      self.subs_positions_local_method = {}
      for i in range(self.nb_nodes):
        position = ExVector(self.dim)
        normal = ExVector(self.dim)
        for d in range(self.dim):
          sp = symbol( "elem.pos(%i)[%i]"%(i,d), "P_{%i,%i}"%(i,d) )
          position[d] = sp
          normal[d] = symbol( "elem.normal(%i)[%i]"%(i,d), "N_{%i,%i}"%(i,d) )
          self.subs_positions_local_method[ sp ] = symbol( "pos(%i)[%i]"%(i,d), "P_{%i,%i}"%(i,d) )
        self.positions.append( position )
        self.normals.append( normal )
          
      self.jacobian_is_calculated = False

    def pos(self):
      """ Calcul la fonction position(var_inter) """
      res = ExVector(self.dim)
      for d in range(self.dim):
        s = {}
        for i in range(self.nb_nodes):
          s[ self.val[i] ] = self.positions[i][d]
        res[d] = self.interpolation['nodal'].subs(EM(s))
      return res

    def analytical_integration( self, expr, order = 5, mul_by_jac = True ):
        res = expr
        if mul_by_jac:
            res *= self.det_jacobian()
        for i in range( self.nb_var_inter-1, -1, -1 ):
            beg = self.interval_var_inter[i][0]
            end = self.interval_var_inter[i][1]
            if type(beg) is float or type(beg) is int: beg = number(beg)
            if type(end) is float or type(end) is int: end = number(end)
            res = integration( res, self.var_inter[i], beg, end, order )
        return res

    def integration( self, expr, order, mul_by_jac = True ):
      if type(expr) is float or type(expr) is int: expr = number(expr)
      if mul_by_jac:
        expr *= self.det_jacobian()
      res = 0.0
      k = min( filter(lambda x:x>=order,self.gauss_points.keys()) )
      for w,p in self.gauss_points[k]:
          mp = {}
          for k,v in p.items():
              if type(v) is float or type(v) is int: mp[k] = number(v)
              else: mp[k] = v
          res += w * expr.subs(EM(mp))
      return res

    def Flat_Interpolation_integration(self, expr, mul_by_jac = True ):
      if type(expr) is float or type(expr) is int: expr = number(expr)
      if mul_by_jac:
        expr *= self.det_jacobian()
      res = 0.0
      for w,p in self.Flat_Interpolation_gauss_points:
          mp = {}
          for k,v in p.items():
              if type(v) is float or type(v) is int: mp[k] = number(v)
              else: mp[k] = v
          res += w * expr.subs(EM(mp))
      return res

    def jacobian(self):
      self.calculate_jacobian()
      return self.jac[0]

    def inverse_jacobian(self):
      self.calculate_jacobian()
      return self.inv_jac

    def det_jacobian(self):
      self.calculate_jacobian()
      return self.det_jac

    def calculate_jacobian(self):
      if self.jacobian_is_calculated: return
      self.jacobian_is_calculated = True
      # first case : dim==nb_var_inter -> no soucy
      coord = self.pos()

      res,coord_res = ExMatrix(self.nb_var_inter,self.nb_var_inter), []
      if self.nb_var_inter==self.dim:
        for j in range(self.nb_var_inter):
          cr,rr = [],[]
          for i in range(self.dim):
            res[j,i] = coord[i].diff(self.var_inter[j]) # j,i
            cr.append(number(i==j))
          coord_res.append(vector(cr))
        #res = res.transpose()
        self.jac = res,coord_res
        self.det_jac = res.determinant()
        self.inv_jac = res.inverse()

        return

      # firstly, we have to find a base
      for vi in self.var_inter:
        cr = ExVector(self.dim)
        for i in range(self.dim): cr[i] = coord[i].diff(vi) 
        # orthogonalization
        for c in coord_res:
          cr -= c * dot( c, cr )
        coord_res.append( cr / norm(cr) )

      # secondly, we can differentiate
      # calcul du tampon_jacobien dans le repere obtenu
      # i est le number de la coordinate curviligne (s,t,...)
      # j est le number de la variable d'interpolation
      # k est le number de la coordinate dans le cartesian (x,y,...)
      # print "coord",coord
      for i in range(self.nb_var_inter):
        for j in range(self.nb_var_inter):
          for k in range(self.dim):
            res[j,i] += coord[k].diff(self.var_inter[j]) * coord_res[i][k];

      self.jac = res,coord_res
      self.det_jac = res.determinant()
      self.inv_jac = res.inverse()
      return

    def grad(self,v):
      """ """
      self.calculate_jacobian()
      if isinstance(v,ExVector):
        res = ExMatrix(v.size(),self.nb_var_inter)
        for k in range(v.size()):
          for j in range(self.nb_var_inter):
            for i in range(self.nb_var_inter):
              res[k,j] += v[k].diff(self.var_inter[i])*self.inv_jac[j,i]
        return res
      res = ExVector(self.nb_var_inter)
      for j in range(self.nb_var_inter):
        tmp = 0
        for i in range(self.nb_var_inter):
          tmp += v.diff(self.var_inter[i])*self.inv_jac[j,i];
        res[j] = tmp
      return res

    def grad_sym(self,v):
      """ """      
      m = self.grad(v)
      if isinstance(m,ExVector):
          return m
      n = max( m.nb_rows(), m.nb_cols() )
      nm = ExMatrix(n,n)
      for i in range(n):
        for j in range(n):
          #  nm[i,j] = (m[i,j]+m[j,i])*0.5
          if i<m.nb_rows() and j<m.nb_cols(): m_ij = m[i,j]
          else: m_ij = 0    
          if j<m.nb_rows() and i<m.nb_cols(): m_ji = m[j,i]
          else: m_ji = 0
    
          if i==j: nm[i,j] = m_ij
          else: nm[i,j] = (m_ij+m_ji)*0.5
#       m = self.grad(v)
#       if isinstance(m,ExVector): return m
#       nm = ExMatrix(m.nb_rows(),m.nb_cols())
#       for i in range(m.nb_rows()):
#         for j in range(m.nb_cols()):
#           if i==j: nm[i,j] = m[i,j]
#           else: nm[i,j] = (m[i,j]+m[j,i])*0.5
      return nm
          
    def grad_sym_col(self,v): return mat_sym_to_vec_col(self.grad_sym(v))
    
    def green_lagrange(self,expr):
      """ """
      res = self.grad(expr)
      tmp = ExMatrix(self.nb_var_inter,self.nb_var_inter)
      for i in range(self.nb_var_inter):
        for j in range(self.nb_var_inter):
          tmp[i,j] = ( res[i,j] + res[j,i] ) * 0.5
      for i in range(self.nb_var_inter):
        for j in range(self.nb_var_inter):
          for k in range(self.nb_var_inter):
            tmp[i,j] += res[k,i] * res[k,j] * 0.5
      return tmp
      
    def green_lagrange_col(self,v): return mat_sym_to_vec_col(self.green_lagrange(v))
    
    def div(self,v):
      if isinstance( v, ExMatrix ):    #etienne
        if (v.nb_cols() != self.nb_var_inter or v.nb_rows() != self.nb_var_inter) :
           print 'Error : div available only if v.nb_cols() = self.nb_var_inter and v.nb_rows() = self.nb_var_inter '
           return 0
        res=ExVector(v.nb_rows())
        for i in range(v.nb_rows()): res[i] += self.div(v.row(i))
        return res
      if isinstance( v, ExVector ):
        if v.size() != self.nb_var_inter:
            print 'Error : div available only if v.size() != self.nb_var_inter'
            return 0
        g = self.grad(v)
        res = 0
        for i in range(v.size()): res += g[i,i]
        return res
      raise 'for now, div works only with vectors'
    
    def write(self,f=sys.stdout):
      def l(s): f.write( s+'\n'%self.std_map )

      f.write( '/// Specialization of Element<...> for %(name_elem)s\n'%self.std_map )
      f.write( '/// @author hugo LECLERC\n' )
      f.write( 'template<class P_T_pos,class P_ND,class ED>\n' )
      f.write( 'class Element<%(name_elem)s,Node<P_T_pos,%(dim)i,P_ND>,ED> : public Element<void,Node<P_T_pos,%(dim)i,P_ND>,ED> {\n'%self.std_map )
      f.write( 'public:\n' )
      f.write( '  typedef Node<P_T_pos,%(dim)i,P_ND> Tnode;\n'%self.std_map )
      f.write( '  typedef Element<%(name_elem)s,Tnode,ED> Tclass;\n'%self.std_map )
      f.write( '  typedef Element<void,Tnode,ED> Tvoid_class;\n' )
      f.write( '  typedef %(name_elem)s Class_type;\n'%self.std_map )
      f.write( '  typedef Element_ancestor<Tnode,ED> EA;\n' )
      f.write( '  typedef typename EA::Pvec Pvec;\n' )
      f.write( '  static const unsigned dim=%(dim)i;\n'%self.std_map )
      f.write( '  static const unsigned _nb_var_inter=%(nb_var_inter)i;\n'%self.std_map )
      f.write( '  static const unsigned _nb_nodes=%(nb_nodes)i;\n'%self.std_map )
      f.write( '  static const unsigned _nb_skin_elems=%i;\n'%len(self.children) )
      f.write( '  static const char *const _name() { return "%(name_elem)s"; }\n'%self.std_map )
      f.write( '  virtual const char *name() const { return _name(); }\n' )
      f.write( '  virtual unsigned nb_nodes() const { return _nb_nodes; }\n' )
      f.write( '  virtual unsigned nb_var_inter() const { return _nb_var_inter; }\n' )
      f.write( '  virtual unsigned nb_skin_elems() const { return _nb_skin_elems; }\n' )
      f.write( '  virtual P_T_pos measure_virtual() const { return measure(); }\n' )
      f.write( '  virtual P_T_pos quality_virtual() const { return quality(); }\n' )
      f.write( '  virtual void ref_new_skin_elem(int i,int *refs,unsigned &nb_nodes_skin) const {\n' )
      f.write( '    switch (i) {\n' )
      for num,i in zip(range(len(self.children)),self.children):
        f.write( '     case ('+str(num)+'):' )
        f.write( ' nb_nodes_skin = %i;' % len(i['nodes']) )
        for cnt,j in zip(range(len(i['nodes'])),i['nodes']):
          f.write( ' refs['+str(cnt)+'] = ref_nodes['+str(j)+'];' )
        f.write( ' break;\n' )
      f.write( '    }\n' )
      f.write( '  }\n' )
      f.write( '  virtual EA *new_skin_elem(int i) const {\n' )
      f.write( '    switch (i) {\n' )
      for num,i in zip(range(len(self.children)),self.children):
        f.write( '     case ('+str(num)+'): return new Element<'+i['name']+',Tnode,ED>;\n' )
      f.write( '    }\n' )
      f.write( '    return NULL;\n' )
      f.write( '  }\n' )
      f.write( '  virtual void permute_nodes(int *res) {' )
      for num,i in zip(range(len(self.permutation)),self.permutation):
        f.write( ' res['+str(num)+'] = ref_nodes['+str(i)+'];' )
      f.write( '  }\n' )
      f.write( '  Element() {}\n' )
      f.write( '  Element(const Xml_node &node):Tvoid_class(node,2) { DMOp::read_xml(node,data); }\n' )
      f.write( '  template<class TV,class TI> TV interpolation(const TV *val,const TI *var_inter) const {\n' )
      Write_code(f,nb_spaces=4,T='TV').add( self.interpolation['nodal'], res ).write()
      f.write( '    return res;\n' )
      f.write( '  }\n' )
      f.write( '  template<class TI> Pvec interpolation_pos(const TI *var_inter) const {\n' )
      f.write( '    Pvec res;\n' )
      cw = Write_code(f,nb_spaces=4,T='P_T_pos')
      for d in range(self.dim):
        l = {}
        for num,v in zip(range(len(self.val)),self.val):
          l[v] = symbol('pos(%i)[%i]'%(d,num))
        cw.add( 'res['+str(d)+']', self.interpolation['nodal'].subs(EM(l)), method="set" )
      cw.write()
      f.write( '    return res;\n' )
      f.write( '  }\n' )
      self.write_normal_funcs(f)
      self.write_local_coords_funcs(f)
      can_directly_be_represented_by = self.can_directly_be_represented_by or self.std_map['name_elem']
      f.write( '  static const char *can_directly_be_represented_by() { return "%s"; }\n' % can_directly_be_represented_by )
      f.write( '  /// evaluation of the quality of the element \n' )
      f.write( '  P_T_pos quality() const {\n' )
      f.write( '    using namespace std;\n' )
      if isinstance(self.quality,PyOp):
        Write_code(f,nb_spaces=4,T='P_T_pos').add( '', self.quality.subs(EM( self.subs_positions_local_method )), 'return' ).write()
      else:
        Write_code(f,nb_spaces=4,T='P_T_pos').add( '', self.quality, 'return' ).write()
      f.write( '  }\n' )
      f.write( '  /// volume if var_inter==3, surface if ==2, ... \n' )
      f.write( '  P_T_pos measure() const {\n' )
      f.write( '    using namespace std;\n' )
      mes = simplify( abs(self.integration(self.det_jacobian(),self.nb_nodes-1)) )
      # print mes
      #mes = simplify_expand(mes)
      Write_code(f,nb_spaces=4,T='P_T_pos').add( '', mes.subs(EM( self.subs_positions_local_method )), 'return' ).write()
      f.write( '  }\n' )
      f.write( '};\n' )
      f.write( '\n' )

    def write_local_coords_funcs(self,f):
      # modification of globals
      old_glob = {}
      new_var = [
        (self,'e'),
        (self.positions,'positions'),
      ]
      for var,name_var in new_var:
        if name_var in globals(): old_glob[name_var] = globals()[name_var]
        globals()[name_var] = var
        
      # get_local_coordinates
      f.write( '  virtual void get_local_coordinates(P_T_pos *coords,const Pvec &point) const {\n' )
      point = vector( [symbol('point[%i]'%i) for i in range(self.dim)] )
      loc_coo = self.local_coordinates(point)
      cw = Write_code(f,nb_spaces=4,T='P_T_pos')
      for i in range(loc_coo.size()):
        cw.add( 'coords[%i]'%i, simplify(loc_coo[i]).subs(EM( self.subs_positions_local_method )), 'set' )
      cw.write()
      f.write( '  }\n' )
      
      # get_point_from_local_coordinates
      f.write( '  virtual void get_point_from_local_coordinates(const P_T_pos *coords,Pvec &point) const {\n' )
      coords = vector( [symbol('coords[%i]'%i) for i in range(loc_coo.size())] )
      coo_to_point = self.pos_using_local_coordinates(coords)
      cw = Write_code(f,nb_spaces=4,T='P_T_pos')
      for i in range(self.dim):
        cw.add( 'point[%i]'%i, simplify(coo_to_point[i]).subs(EM( self.subs_positions_local_method )), 'set' )
      cw.write()
      f.write( '  }\n' )
    
      # reconstitution of globals
      for var,name_var in new_var: del globals()[name_var]
      for n,i in old_glob.items(): globals()[n] = i

    def normal(self):
      assert self.dim==self.nb_var_inter+1
      self.calculate_jacobian()
      if self.dim==2:
        return vector( [ -self.jac[1][0][1], self.jac[1][0][0] ] )
      if self.dim==3:
        return vectorial_product( self.jac[1][0], self.jac[1][1] )
      return vector([0.0])
      
    def write_normal_funcs(self,f):
      if self.dim!=self.nb_var_inter+1: return 
      f.write( "  virtual Pvec sample_normal_virtual() const { return sample_normal(); }\n" )
      f.write( "  Pvec sample_normal() const {\n" )
      f.write( "    Pvec res;\n" )

      sbs = {}
      for i in range(self.nb_nodes):
        for d in range(self.dim):
          sbs[ self.positions[i][d] ] = symbol( "pos(%i)[%i]"%(i,d) );
      n = self.normal().subs(EM(sbs))
          
      cw = Write_code(f,nb_spaces=4,T='P_T_pos')
      for i in range(self.dim):
        cw.add( 'res[%i]'%i, n[i], 'set' )
      cw.write()
      
      f.write( "    return res;\n" )
      f.write( "  }\n" )

    def get_nb_var(self, name ):
      ex = self.interpolation[name]
      for i in range(len( self.val )):
            if not ex.diff( self.val[i] ):
                return i
      return 0

    def get_nb_var_der_nodal(self):
      ex = self.interpolation["der_nodal"]
      for i in range(len( self.val )):
        if not ex.diff( self.val[i] ): return i
      return 0


    def get_proj_on_particular_child_element( self, field, child_info, child ):
      """ recupere la projection du champs field sur l'element decrit peau par child_info """
      subs_vi = {}
      for i in range(len(self.var_inter)): subs_vi[ self.var_inter[i] ] = child_info['var'][i]
      field = field.subs(EM(subs_vi))
      subs_vi = {}
      for i in range(len(child.var_inter)): subs_vi[ self.var_inter[i] ] = child.var_inter[i]
      field = field.subs(EM(subs_vi))

      # pos substitution
      subs_pos = {}
      for d in range(child.dim):
        for i in range(child.nb_nodes):
          subs_pos[ child.positions[i][d] ] = self.positions[ child_info['nodes'][i] ][d]
      field = field.subs(EM( subs_pos ))
      return field

    # 
    def sum_nb_nodes_of_each_children( self ):
      """ """
      res = 0
      for c in self.children:
          res += len( c['nodes'] )
      return res

    # 
    def sub_integration( self, val, order ):
        res = Ex(0)
        for num_child in self.children_nb_if_sub_integration:
            child_info = self.children[num_child]
            child = Element( child_info['name'], self.dim )
            proj = self.get_proj_on_particular_child_element( val, child_info, child )
            res += child.integration( proj, order )
        return res

    #
    def get_interpolation( self, name, values, dim ):
        res = ExVector(dim)
        for d in range(dim):
            s = {}
            for i in range(self.nb_nodes):
                s[ self.val[i] ] = values[i][d]
            res[d] = self.interpolation[name].subs(EM(s))
        return res
            
    #
    def mean( self, expr, order = 0 ):
        if type(expr)==ExVector:
            res = ExVector( expr.size() )
            for i in range( expr.size() ):
                res[i] = self.mean( expr[i] , order)
            return res
        else:
            if order:
                return self.integration( expr, order, False ) / self.integration( number(1), 0, False )
            return self.analytical_integration( expr, False ) / self.analytical_integration( number(1), False )
    
    #
    def measure( self ):
        return self.integration( number(1), 2 )
        
    #
    def get_value_on_node_number( self, expr, node_number ):
        #print dict( zip( self.var_inter, map( number, self.var_inter_of_node_number[ node_number ]+number() ) ) )
        return expr.subs( EM( dict( zip( self.var_inter, map( number, self.var_inter_of_node_number[ node_number ] ) ) ) ) )
        
        
        
