from variable import *
from interpolation import *
from calculate_matrix import *
from contact import *
from LMT.include.codegen import *
import os,sys,string
import extrapolation
from element import *
from material_help import *
from fluid_help import *
import gauss_integration

class Formulation:
  def __init__( self, name_form, dim, nb_form=0, incpaths=['.','LMT/formulations'],options={}, name_file=None ):
    if not name_file:
        name_file = 'formulation_'+name_form+'.py'
        for inc in [""]+incpaths:
            if inc: inc += "/"
            if os.access( inc+name_file, os.F_OK ):
                name_file = inc+name_file
                break
        else:
            txt = 'impossible to find %s in %s'%(name_file,[""]+incpaths)
            raise NameError, txt

    def IS_contact_formulation(): return number(0)
    def elem_contact_formulation(ve): return number(0)
    def apply_on_elements_after_solve(unk_subs): return ""
    
    self.ind = {
      "Variable" : Variable,
      "allow_surtension_coefficient" : False,
      "make_expensive_simplifications" : False,
      "important_variation_of_volume" : False,
      "integration_totale" : True,
      "time_integration" : "gauss",
      "left_time_integration" : -sqrt(2) / 2,
      "right_time_integration" : sqrt(2) / 2,
      "supplementary_order_for_time_integration" : 0,
      "assume_linear_system" : True,
      "assume_non_linear" : False,
      "dont_want_to_add_KUn" : False,
      "use_test_functions" : True,
      "assume_symmetric_matrix" : True,
      "need_skin_assembly" : False,
      "dim" : dim,
      "nb_form" : nb_form,
      # variables
      "pos" : Variable(unit='m',nb_dim=[dim]),
      "is_on_skin" : Variable(unit='',default_value='0'),
      #"is_in_contact" : Variable(unit='',default_value='0'),
      # variables associated with solids
      "is_pos" : ISVariable( unit='m', nb_dim=[dim], default_value=('(T_pos)0.0,'*dim)[:-1] ),
      "is_rotation" : ISVariable( unit='deg', nb_dim=[dim-(dim==2)], default_value=('(T_pos)0.0,'*(dim-(dim==2)))[:-1] ),
      #
      "auto_contact" : False,
      "matrix_will_be_definite_positive" : True,
      "Interpolations" : std_interpolations,
      "order_integration" : 2,
      "IS_contact_formulation" : IS_contact_formulation,
      "elem_contact_formulation" : elem_contact_formulation,
      'hooke_isotrope_th' : hooke_isotrope_th,
      'hooke_orthotrope_th' : hooke_orthotrope_th,
      'apply_on_elements_after_solve' : apply_on_elements_after_solve,
      'apply_on_elements_after_solve_2' : apply_on_elements_after_solve,
      'apply_on_elements_after_solve_3' : apply_on_elements_after_solve,
      'apply_on_elements_after_solve_4' : apply_on_elements_after_solve,
      'apply_on_elements_after_solve_5' : apply_on_elements_after_solve,
      'apply_on_elements_after_solve_6' : apply_on_elements_after_solve,
      'options' : options,
    }
    execfile( name_file, globals(), self.ind )

    self.name = name_form
    self.name_file = name_file
    self.incpaths = incpaths
    self.ponderation = symbol("ponderation")
    for n,i in self.ind.items():
      setattr( self, n, i )

  def get_variables(self):
    res = {}
    for name_var,var in self.__dict__.items():
      if isinstance(var,Variable):
        res[name_var] = var
    return res
      
  def get_is_variables(self):
    res = {}
    for name_var,var in self.__dict__.items():
      if isinstance(var,ISVariable):
        res[name_var] = var
    return res
      
  def set_variable_expressions(self,e):
    for name_var,var in self.get_variables().items():
      var.set_expr( name_var, self.Interpolations[ var.interpolation ](e), e )
    for name_var,var in self.get_is_variables().items():
      var.set_expr( name_var )

  def write_nb__unknowns(self,f,t,skin,t_tot,TE,e=None):
    nb_unknowns = 0
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var:
        #print name_var,var.nb_elements()
        nb_unknowns += var.nb_elements() * getattr(self.Interpolations[var.interpolation](e),'nb_'+t)
    f.write( '  \n' )
    f.write( '  static const unsigned nb_%s_unknowns = %d;\n'%(t_tot,nb_unknowns) )
      
  def write_set__unknowns(self,f,t,skin,t_tot,TE,partial_ts,e=None):
    f.write( '  template<class TE,class TTs,class Tvec>\n' )
    ts = ',T partial_ts' * partial_ts
    f.write( '  inline static void set_%s_unknowns(TE &%s,const TTs &f,const Tvec &vecs,unsigned indice%s) {\n'%(t_tot,TE,ts) )
    cpt_vec = 0
    cw = Write_code('T')
    sym_partial_ts = symbol( 'partial_ts' )
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var:
        nb_unknowns = getattr(self.Interpolations[var.interpolation](e),'nb_'+t)
        for i in range(nb_unknowns):
          def pd2(d,cpt_vec):
            if partial_ts:
              s = { extrapolation.time : sym_partial_ts }
            else:
              s = { extrapolation.time : extrapolation.time_steps[0] }
            extr = var.extr()
            for o in range(extr.order+1):
              s[ extrapolation.symbols[o] ] = symbol( 'vecs['+str(o)+'][indice+'+str(cpt_vec)+']' )
            ex = extr.form()
            for num_der in range(var.nb_der+1):
              cw.add( ex.subs(EM(s)), var.name_set_unknown(t,num_der,d), Write_code.Set )
              ex = ex.diff( extrapolation.time )
          if len(var.nb_dim):
            for d in range(var.nb_dim[0]):
              pd2(d,cpt_vec)
              cpt_vec += 1
          else:
            pd2(-1,cpt_vec)
            cpt_vec += 1
    f.write( cw.to_string() )
      
    f.write( '  }\n' )
      
  def write_get_initial_conditions(self,f,t,skin,t_tot,TE,e=None):
    f.write( '  template<class TE,class TTs,class Tvec>\n' )
    f.write( '  inline static void get_%s_initial_conditions(const TE &%s,const TTs &f,Tvec &vecs,unsigned indice) {\n'%(t_tot,TE) )
    cpt_vec = 0
    cw = Write_code('T')
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var:
        for i in range(getattr(self.Interpolations[var.interpolation](e),'nb_'+t)):
          def pd1(d,cpt_vec,t):
            ex = 0
            fact = 1
            extr = var.extr()
            for num_der in range(extr.order+1):
              ex += fact * symbol(var.name_set_unknown(t,num_der,d))
              fact *= extrapolation.time
            t = 0
            for n in range(5):
              cw.add( ex.subs( extrapolation.time,t ), 'vecs['+str(n)+'][indice+'+str(cpt_vec)+']', Write_code.Set )
              t -= extrapolation.time_steps[n]
          if len(var.nb_dim):
            for d in range(var.nb_dim[0]):
              pd1(d,cpt_vec,t)
              cpt_vec += 1
          else:
            pd1(-1,cpt_vec,t)
            cpt_vec += 1
    f.write( cw.to_string() )
    f.write( '  }\n' )
  
  def write_set_old_vec(self,f,t,skin,t_tot,TE,e=None):
    f.write( '  template<class TE,class TTs,class Tvecs,class Tvec>\n' )
    f.write( '  inline static void set_old_vec_%s(const TE &%s,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {\n'%(t_tot,TE) )
    cpt_vec = 0
    cw = Write_code('T')
    max_error = 0
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var: 
        nb_unknowns = getattr(self.Interpolations[var.interpolation](e),'nb_'+t)
        extr = var.extr()
        for i in range(nb_unknowns):
          def pd2(d,cpt_vec,old_ex=0):
            s = { extrapolation.time : extrapolation.time_steps[0] }
            #s[ extrapolation.time_steps[0] ] = extrapolation.time_steps[1]
            s[ extrapolation.symbols[0] ] = symbol( 'vecs[1][indice+%i]'%cpt_vec )
            for o in range(1,extr.order+1):
              #s[ extrapolation.time_steps[o] ] = extrapolation.time_steps[o+1]
              s[ extrapolation.symbols[o] ] = symbol( 'vecs[%i][indice+%i]'%(o+1,cpt_vec) )
            ex = extr.form().subs(EM(s))
            cw.add( ex, 'old_vec[indice+%i]'%cpt_vec, Write_code.Set )
          if len(var.nb_dim):
            for d in range(var.nb_dim[0]):
              pd2(d,cpt_vec)
              cpt_vec += 1
          else:
            pd2(-1,cpt_vec)
            cpt_vec += 1
    f.write( cw.to_string() )
    f.write( '  }\n' )
  
  def write_max_error(self,f,t,skin,t_tot,TE,e=None):
    f.write( '  template<class TE,class TTs,class Tvec>\n' )
    f.write( '  inline static T max_%s_error(const TE &%s,const TTs &f,const Tvec &vecs,int indice) {\n'%(t_tot,TE) )
    cpt_vec = 0
    cw = Write_code('T')
    max_error = 0
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var: 
        nb_unknowns = getattr(self.Interpolations[var.interpolation](e),'nb_'+t)
        extr = var.extr()
        for i in range(nb_unknowns):
          def pd2(d,cpt_vec,old_ex=0):
            s = { extrapolation.time : extrapolation.time_steps[0]+extrapolation.time_steps[1] }
            s[ extrapolation.time_steps[0] ] = extrapolation.time_steps[1]
            s[ extrapolation.symbols[0] ] = symbol( 'vecs[1][indice+'+str(cpt_vec)+']' )
            for o in range(1,extr.order+1):
              s[ extrapolation.time_steps[o] ] = extrapolation.time_steps[o+1]
              s[ extrapolation.symbols[o] ] = symbol( 'vecs['+str(o+1)+'][indice+'+str(cpt_vec)+']' )
            ex = extr.form().subs(EM(s))
            return abs( ex - symbol( 'vecs[0][indice+'+str(cpt_vec)+']' ) )
          if len(var.nb_dim):
            for d in range(var.nb_dim[0]):
              if max_error==0: max_error = pd2(d,cpt_vec)
              else:            max_error = max( pd2(d,cpt_vec), max_error )
              cpt_vec += 1
          else:
            if max_error==0: max_error = pd2(-1,cpt_vec)
            else:            max_error = max( pd2(-1,cpt_vec), max_error )
            cpt_vec += 1
    cw.add( max_error , 'proute', Write_code.Return )
    f.write( cw.to_string() )
    f.write( '  }\n' )
  
  def write_carac_for_t(self,f,t,skin,e=None):
    t_tot = 'skin_'*skin+t
    TE = {'nodal':'node','elementary':'elem','global':'mesh'}[ t ]
    #
    self.write_nb__unknowns(f,t,skin,t_tot,TE,e)
    # set__unknowns
    self.write_set__unknowns(f,t,skin,t_tot,TE,False,e)
    self.write_set__unknowns(f,t,skin,t_tot,TE,True,e)
    #
    self.write_get_initial_conditions(f,t,skin,t_tot,TE,e)
    #
    self.write_max_error(f,t,skin,t_tot,TE,e)
    self.write_set_old_vec(f,t,skin,t_tot,TE,e)
    
  def write_carac(self,f,e,matrices,contact_matrices):
    ifndef_carac = ( self.name+"_"+str(self.dim)+"_num_"+str(self.nb_form)+"_CARAC_H" ).upper()
    f.write( '#ifndef %s\n'%(ifndef_carac) )
    f.write( '#define %s\n'%(ifndef_carac) )
    #f.write( '#include "formulation/formulation.h"\n' )
    f.write( '#ifndef STRUCT_%s\n'%(self.name.upper()) )
    f.write( '#define STRUCT_%s\n'%(self.name.upper()) )
    f.write( 'struct %s {\n'%(self.name) )
    f.write( '  static const char *name() { return "%s"; }\n'%(self.name) )
    f.write( '};\n' )
    f.write( '#endif // %s\n'%(self.name.upper()) )
    f.write( '\n' )

    f.write( 'template<class P_T>\n' )
    f.write( 'class CaracFormulation<%s,%i,P_T>  {\n'%(self.name,self.dim) )
    f.write( 'public:\n' )
    f.write( '  typedef P_T T;\n' )
    f.write( '  static const char *name() { return "%s"; }\n'%(self.name) )
    f.write( '  static const bool matrix_will_be_definite_positive=%s;\n'%(['false','true'][self.matrix_will_be_definite_positive]) )
    has_not_N_matrix = matrices['N']['M'].is_null() and matrices['N']['V'].is_null()
    f.write( '  static const bool has_nodal_matrix = %s;\n'%( ['true','false'][has_not_N_matrix] ) )
    has_not_ISC_matrix = contact_matrices['N']['M'].is_null() and contact_matrices['N']['V'].is_null()
    f.write( '  static const bool has_IS_contact_matrix=%s;\n'%( ['true','false'][has_not_ISC_matrix] ) )
    f.write( '  static const bool need_skin_assembly=%s;\n'%(['false','true'][self.need_skin_assembly]) )
    f.write( '  typedef Norm1_is_inf Name_convergence_criterium;\n' )
    f.write( '  static const unsigned nb_vectors = 4;\n' )
    f.write( '  static const unsigned nb_matrices = 1;\n' )
    f.write( '  static const unsigned auto_contact = %s;\n'%(['false','true'][self.auto_contact]) )
    f.write( '  static const bool friction_coeff_is_a_nodal_variable = 0;\n' )
    f.write( '  static const unsigned offset_of_pos_unknown=3;\n' )
    f.write( '  static const unsigned pos_is_an_unknown = %s;\n'%(['false','true'][self.pos.unknown]) )

    # is_unknown
    all_unk = []
    num_in_vec_unk = []
    cpt = 0
    for name_var,var in self.get_variables().items():
      if var.unknown:
          all_unk.append( 's=="'+name_var+'"' )
          num_in_vec_unk.append( cpt )
          cpt += var.nb_elements()
    if all_unk:
        f.write( '  static bool is_unknown(const std::string &s) { return ('+string.join(all_unk,' || ')+'); }\n' )
        f.write( '  static unsigned num_in_vec_unknown(const std::string &s) {' )
        for a,n in zip(num_in_vec_unk,all_unk):
            f.write( ' if ( '+n+' )return '+str(a)+';' )
        f.write( ' return 0;' )
        f.write( '  }\n' )
    else:
        f.write( '  static bool is_unknown(const std::string &s) { return false; }\n' )
        f.write( '  static unsigned num_in_vec_unknown(const std::string &s) { return 0; }\n' )
        
    f.write( '  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {\n' )
    f.write( '      static const bool symm = '+str(int(self.assume_symmetric_matrix))+';\n' )
    f.write( '      static const bool herm = false;\n' )
    f.write( '      static const bool diag = false;\n' )
    f.write( '  };\n' )
    f.write( '  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {\n' )
    f.write( '      static const bool symm = '+str(int(self.assume_symmetric_matrix))+';\n' )
    f.write( '      static const bool herm = false;\n' )
    f.write( '      static const bool diag = false;\n' )
    f.write( '  };\n' )

    for skin in [False,True]:
      for t in ['nodal','global']:
        self.write_carac_for_t(f,t,skin)

    f.write( '};\n' )
    f.write( '#endif // %s\n'%(ifndef_carac) )

  def get_unknown_symbols(self,volumic,skin=False):
    """ res will contain unknown symbols """
    res = []
    res_test = []
    num_var = 0
    for name_var,var in self.get_variables().items():
      if var.unknown and skin==var.skin_var:
        for t,n,n2,v in var.symbols:
          if volumic or t or n==0: res.append( (t,n,num_var,n2,v) )
        for t,n,n2,v in var.test_symbols:
          if volumic or t or n==0: res_test.append( (t,n,num_var,n2,v) )
        num_var += 1
    res.sort()
    res_test.sort()
    
    indices,offsets = [], []
    cpt_indice,cpt_offset = -1,0
    old_ne = (0,-1)
    unk_subs = {}
    for n,ne,num_var,ne2,s in res:
      if (n,ne)!=old_ne:
        cpt_indice += 1
        cpt_offset = 0
      else:
        cpt_offset += 1
      indices.append( cpt_indice )
      offsets.append( cpt_offset )
      old_ne = (n,ne)
      
      for i in range(0,len(s)):
        unk_subs[ s[i] ] = symbol( 'f.vectors[%i][indices[%i]+%i]' % (i,cpt_indice,cpt_offset) )
      #unk_subs[ s[0] ] = symbol( 'f.old_vec[indices[%i]+%i]' % (cpt_indice,cpt_offset) )
      
    res = map(lambda a:unk_subs[a[4][0]],res)
    res_test = map(lambda a:a[4][0],res_test)
    return res,res_test,indices,offsets,unk_subs


  def play_with_dS_part( self, dS_part, e, res, dS_normal ):
    """ play with children elements (*dS) """
    unknown_symbols, unknown_test_symbols, indices, offsets, unk_subs = self.get_unknown_symbols(True)
    for cpt_child in range(len( e.children )):
        ct = e.children[cpt_child]
        c  = e.children_inst[cpt_child]
        # pos var_inter
        subs_vi = {}
        for i in range(len(e.var_inter)): subs_vi[ e.var_inter[i] ] = ct['var'][i]
        local_ds = dS_part.subs(EM(subs_vi))
        subs_vi = {}
        for i in range(len(c.var_inter)): subs_vi[ e.var_inter[i] ] = c.var_inter[i]
        if dS_part:
            n = c.normal()
            for i in range(e.dim):
                subs_vi[dS_normal[i]] = n[i]
        local_ds = local_ds.subs(EM(subs_vi))
        
        local_ds = c.integration( local_ds, self.order_integration ).subs(EM(unk_subs))

        # pos substitution
        subs_pos = {}
        for d in range(c.dim):
          for i in range(c.nb_nodes):
            subs_pos[ c.positions[i][d] ] = e.positions[ ct['nodes'][i] ][d]

        local_ds = local_ds.subs(EM( subs_pos ))

        # subs children_is_on_skin
        subs_cs = {}
        print len( e.children_is_on_skin )
        print e.name
        for i in range(len( e.children )):
            subs_cs[ e.children_is_on_skin[ i ] ] = number( cpt_child == i )
        local_ds = local_ds.subs(EM( subs_cs ))
        
        SN = 'S'+str(cpt_child)

        res[SN] = calculate_matrix( local_ds, unknown_symbols, unknown_test_symbols, {}, self.allow_surtension_coefficient, self.assume_non_linear, test=self.use_test_functions, 
            dont_want_to_add_KUn = self.dont_want_to_add_KUn )

        res[SN]['i'] = indices
        res[SN]['o'] = offsets
        
        cpt_child += 1
                                
  def calculate_matrices(self,e):
    res = {}
    dV,dE,dS,dN = symbol('dV'),symbol('dE'),symbol('dS'),symbol('dN')
    dS_normal = ExVector(e.dim)
    for i in range( e.dim ):
        dS_normal[ i ] = symbol('dS_normal['+str(i)+']')
    dSubInter = symbol('dSubInter')
    # modification of globals
    old_glob = {}
    new_var = self.get_variables().items() + [
      ('time',extrapolation.time),
      ('time_steps',extrapolation.time_steps),
      ('dim',self.dim),
      ('dV',dV),
      ('dE',dE),
      ('dN',dN),
      ('dS',dS),
      ('dS_normal',dS_normal),
      ('dSubInter',dSubInter),
      ('e',e),
      ('div',e.div),
      ('grad',e.grad),
      ('grad_sym',e.grad_sym),
      ('grad_sym_col',e.grad_sym_col),
      ('green_lagrange',e.green_lagrange),
      ('green_lagrange_col',e.green_lagrange_col),
      ('options', self.options),
    ]
    # global variables
    class VariablesFormulation:
      pass
    vi = VariablesFormulation()
    for name_var,var in new_var:
      setattr( vi, name_var, var )
    new_var.append( ('formulation_instance', vi ) )
      
    for name_var,var in new_var:
      if name_var in globals(): old_glob[name_var] = globals()[name_var]
      globals()[name_var] = var
    
    # element children 
    setattr( e, "children_inst", [] )
    setattr( e, "children_is_on_skin", [] )
    cpt = 0
    for ct in e.children:
        e.children_inst.append( Element( ct['name'], self.dim, self.incpaths ) )
        e.children_is_on_skin.append( symbol("child_is_on_skin[%i]"%cpt) )
        cpt += 1
    
    # max_nb_der
    max_nb_der = 0
    for name_var,var in self.get_variables().items():
        if var.unknown: max_nb_der = max( max_nb_der, var.nb_der )
    # call of formulation
    form = self.formulation()
    form = gauss_integration.gauss_integration(form,max_nb_der+self.supplementary_order_for_time_integration, \
                                               extrapolation.time, \
                                               extrapolation.time_steps[1]*self.left_time_integration, \
                                               extrapolation.time_steps[0]*self.right_time_integration) # integration sur le temps
    
    unknown_symbols, unknown_test_symbols, indices, offsets, unk_subs = self.get_unknown_symbols(True)
    form_after_solve = self.apply_on_elements_after_solve(unk_subs)
    form_after_solve_2 = self.apply_on_elements_after_solve_2(unk_subs)
    form_after_solve_3 = self.apply_on_elements_after_solve_3(unk_subs)
    form_after_solve_4 = self.apply_on_elements_after_solve_4(unk_subs)
    form_after_solve_5 = self.apply_on_elements_after_solve_5(unk_subs)
    form_after_solve_6 = self.apply_on_elements_after_solve_6(unk_subs)
    
    # surfacic part
    dS_part = form.diff(dS)
    self.play_with_dS_part( dS_part, e, res, dS_normal )
    #sys.stderr.write( form.to_string() )

    form = form.subs( dS, 0 )
    # nodal part
    unknown_symbols, unknown_test_symbols, indices, offsets, unk_subs = self.get_unknown_symbols(False)
    #print '1'
    dN_part = form.diff(dN)
    #print '2'
    dN_part = dN_part.subs(EM( dict(zip(e.var_inter+unk_subs.keys(),[number(0)]*len(e.var_inter)+unk_subs.values())) ))
    #print '3'
    res['N'] = calculate_matrix( dN_part, unknown_symbols, unknown_test_symbols, {}, self.allow_surtension_coefficient, self.assume_non_linear, test=self.use_test_functions, 
            dont_want_to_add_KUn = self.dont_want_to_add_KUn )
    res['N']['i'] = indices
    res['N']['o'] = offsets
    form = form.subs( dN, 0 )
    
    # volumic part
    #print "dV"
    unknown_symbols, unknown_test_symbols, indices, offsets, unk_subs = self.get_unknown_symbols(True)
    if self.integration_totale:
        dV_part = e.integration( form.diff(dV), self.order_integration ).subs(EM(unk_subs))
    else:
        dV_part = form.diff(dV).subs(EM(unk_subs))*e.det_jacobian() * self.ponderation
    form = form.subs( dV, 0 )

    # dSubInter
    dV_part += e.sub_integration( form.diff(dSubInter), self.order_integration ).subs(EM(unk_subs))

    #
    nb_pts_gauss_if_not_integration_totale = 1.0
    if not self.integration_totale:
        k = min( filter(lambda x:x>=self.order_integration,e.gauss_points.keys()) )
        nb_pts_gauss_if_not_integration_totale = len( e.gauss_points[k] )
    
    dV_part += form.diff(dE).subs(EM(unk_subs)) / nb_pts_gauss_if_not_integration_totale
    form = form.subs( dE, 0 )
    res['V'] = calculate_matrix( dV_part, unknown_symbols, unknown_test_symbols, {}, self.allow_surtension_coefficient, self.assume_non_linear, test=self.use_test_functions, 
            dont_want_to_add_KUn = self.dont_want_to_add_KUn )
    res['V']['i'] = indices
    res['V']['o'] = offsets
    
    # reconstitution of globals
    for name_var,var in new_var: del globals()[name_var]
    for n,i in old_glob.items(): globals()[n] = i
    res['unknown_symbols'] = unknown_symbols
    
    return res, [form_after_solve,form_after_solve_2,form_after_solve_3,form_after_solve_4,form_after_solve_5,form_after_solve_6]
  
  def contact_pos_is(self,imp_node):
    if self.dim==3:   angle = norm(self.is_rotation.expr)
    elif self.dim==2: angle = self.is_rotation.expr[0]
    else: angle = 0.0

    
    sa=sin(angle);
    ca=cos(angle);
    if self.dim==3:
      normal = self.is_rotation.expr / (angle+eqz(angle))
      n0=normal[0]*sa;
      n1=normal[1]*sa;
      n2=normal[2]*sa;
      mat = matrix([
        [ ca,  -n2, n1  ],
        [ n2,  ca,  -n0 ],
        [ -n1, n0,  ca  ],
      ])
      for i in range(self.dim):
        for j in range(self.dim):
          mat[i,j] += normal[i]*normal[j]*(1.0-ca)
    elif self.dim==2:
      mat = matrix([
        [ ca, -sa ],
        [ sa, ca  ],
      ])
    elif self.dim==1:
      mat = matrix( [[1.0]] )    
      
    res = vector([0.0]*self.dim)
    for i in range(self.dim):
      for j in range(self.dim):
        res[i] += mat[i,j] * imp_node[j]
    return res + self.is_pos.expr

  def calculate_contact_matrices(self,e):
    res = {}
    # modification of globals
    old_glob = {}
    imp_node = [symbol('cd.imp_node[%i]'%i) for i in range(self.dim)]
    new_var = self.get_variables().items() + self.get_is_variables().items() + [
      ('time',extrapolation.time),
      ('time_steps',extrapolation.time_steps),
      ('e',e),
      ('grad',e.grad),
      ('grad_sym',e.grad_sym),
      ('grad_sym_col',e.grad_sym_col),
      ('contact_pos',self.contact_pos_is(imp_node)),
      ('imp_node', imp_node ),
      ('contact_normal', vector([symbol('cd.pen.normal[%s]'%i) for i in range(self.dim)]) ),
    ]
    for name_var,var in new_var:
      if name_var in globals(): old_glob[name_var] = globals()[name_var]
      globals()[name_var] = var
    # max_nb_der
    max_nb_der = 0
    for name_var,var in self.get_variables().items():
      if var.unknown: max_nb_der = max( max_nb_der, var.nb_der )
      
    # call of formulation for implicit shapes
    unknown_symbols, unknown_test_symbols, indices, offsets, unk_subs = self.get_unknown_symbols(False)
    dN_subs = dict(zip(e.var_inter,[number(0)]*len(e.var_inter)))
    form = self.IS_contact_formulation().subs(EM(unk_subs)).subs(EM(dN_subs))
    form = gauss_integration.gauss_integration(form,max_nb_der+self.supplementary_order_for_time_integration, \
           extrapolation.time,0,extrapolation.time_steps[0] * 2.0 )
    res['N'] = calculate_matrix( form, unknown_symbols, unknown_test_symbols, {}, self.allow_surtension_coefficient, self.assume_non_linear, test=self.use_test_functions, 
            dont_want_to_add_KUn = self.dont_want_to_add_KUn )
    res['N']['i'] = indices
    res['N']['o'] = offsets
    
    # call of formulation for elements
    add_unknown_symbols, add_unknown_test_symbols, add_indices, add_offsets, add_unk_subs = self.get_unknown_symbols(True)
    ve = new_var
    form = self.elem_contact_formulation(ve).subs(EM(add_unk_subs))
    form = gauss_integration.gauss_integration(form,max_nb_der+self.supplementary_order_for_time_integration, \
           extrapolation.time,0,extrapolation.time_steps[0] * 2.0)
    res['V'] = calculate_matrix( form, add_unknown_symbols, add_unknown_test_symbols, {}, self.allow_surtension_coefficient, self.assume_non_linear, test=self.use_test_functions, 
            dont_want_to_add_KUn = self.dont_want_to_add_KUn )
    res['V']['i'] = indices
    res['V']['o'] = offsets
    
    # reconstitution of globals
    for name_var,var in new_var: del globals()[name_var]
    for n,i in old_glob.items(): globals()[n] = i
    res['unknown_symbols'] = unknown_symbols
    return res

  def write_carac_for_element(self,f,e,matrices,contact_matrices,form_after_solve):
    f.write( 'class %s;\n'%e.name )
    f.write( 'template<unsigned A,class B,class C> class Node;\n' )
    f.write( 'template<class A,class B,class C,class D,unsigned E> class Element;\n' )
    f.write( '\n' )
    f.write( '// Carac for ...\n' )
    f.write( 'template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>\n' )
    f.write( 'class CaracFormulationForElement<%s,Element<%s,DefaultBehavior,Node<%i,P_T_pos,P_ND>,TED,nim>,TM,T> {\n'%(self.name,e.name,self.dim) )
    f.write( 'public:\n' )
    f.write( '    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {\n' )
    f.write( '        static const bool symm = '+['false','true'][self.assume_symmetric_matrix]+';\n' )
    f.write( '        static const bool herm = false;\n' )
    f.write( '        static const bool diag = false;\n' )
    non_linear_system = 0
    for s in matrices['unknown_symbols']:
        non_linear_system |= matrices['V']['M'].depends_on( s )
        for nc in range(len(e.children)):
            non_linear_system |= matrices['S'+str(nc)]['M'].depends_on( s )
        non_linear_system |= matrices['N']['M'].depends_on( s )
        non_linear_system |= contact_matrices['N']['M'].depends_on( s )
    # TODO...
    non_linear_system = not self.assume_linear_system
    f.write( '        static const bool linear = %s;\n'%( ['true','false'][ non_linear_system ] ) )
    f.write( '    };\n' )
    
    has_not_V_matrix = matrices['V']['M'].is_null() and matrices['V']['V'].is_null()
    has_not_S_matrix = True
    for nc in range(len(e.children)):
        has_not_S_matrix &= matrices['S'+str(nc)]['M'].is_null() and matrices['S'+str(nc)]['V'].is_null()
            
    f.write( '    static const bool has_elementary_matrix = %s;\n'%( ['true','false'][has_not_V_matrix] ) )
    f.write( '    static const bool has_skin_elementary_matrix = %s;\n'%( ['true','false'][has_not_S_matrix] ) )

    f.write( '    template<class TE,class TF> static void after_solve(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[0] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )
    f.write( '    template<class TE,class TF> static void after_solve_2(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[1] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )
    f.write( '    template<class TE,class TF> static void after_solve_3(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[2] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )
    f.write( '    template<class TE,class TF> static void after_solve_4(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[3] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )
    f.write( '    template<class TE,class TF> static void after_solve_5(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[4] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )   
    f.write( '    template<class TE,class TF> static void after_solve_6(TE &elem,TF &f,const unsigned *indices) {\n' )
    f.write( '      #define PNODE(N) (*elem.node(N))\n' )
    f.write( form_after_solve[5] + '\n' )
    f.write( '      #undef PNODE\n' )
    f.write( '    }\n' )   
        
    for skin in [False,True]:
      self.write_carac_for_t(f,'elementary',skin,e)
    
    f.write( '};\n' )
    f.write( '\n' )

  def write_matrix(self,f,T,assemble_mat,assemble_vec,symmetric,matrices,e):
    f.write( '// \n' )
    BU = ',unsigned symmetric_version'*(assemble_mat==False)
    if T=='V':
      f.write( 'template<class TM,class T,bool wont_add_nz,class T_pos,class ND,class ED,unsigned nim'+BU+'>\n' )
      if self.integration_totale:
          f.write( 'void add_elem_matrix(\n' )
      else:
          f.write( 'void add_local_elem_matrix(T ponderation,const T *var_inter,\n' )
      f.write( '      Formulation<TM,%s,DefaultBehavior,T,wont_add_nz> &f,\n' % self.name )
      f.write( '      const Number<%s> &matrix_is_sym,\n'%( ['false','true','symmetric_version'][symmetric+(assemble_mat==False)] ) )
      f.write( '      const Number<%s> &assemble_mat,\n'%( ['false','true'][assemble_mat] ) )
      f.write( '      const Number<%s> &assemble_vec,\n'%( ['false','true'][assemble_vec] ) )
      f.write( '      const Element<%s,DefaultBehavior,Node<%i,T_pos,ND>,ED,nim> &elem,\n'%(e.name,self.dim) )
      f.write( '      const unsigned *indices) {\n' )
      f.write( '  #define PNODE(N) (*elem.node(N))\n' )
    
    elif T[0]=='S':
      num_child = string.atoi(T[1:])
      f.write( 'template<class TM,class T,bool wont_add_nz,class T_pos,class ND,class ED,unsigned nim,class ED2,unsigned nim2'+BU+'>\n' )
      f.write( 'void add_skin_elem_matrix(\n' )
      f.write( '      Formulation<TM,%s,DefaultBehavior,T,wont_add_nz> &f,\n' % self.name )
      f.write( '      const Number<%s> &matrix_is_sym,\n'%( ['false','true','symmetric_version'][symmetric+(assemble_mat==False)] ) )
      f.write( '      const Number<%s> &assemble_mat,\n'%( ['false','true'][assemble_mat] ) )
      f.write( '      const Number<%s> &assemble_vec,\n'%( ['false','true'][assemble_vec] ) )
      f.write( '      const Element<%s,DefaultBehavior,Node<%i,T_pos,ND>,ED,nim> &elem,\n'%(e.name,self.dim) )
      f.write( '      const Element<%s,DefaultBehavior,Node<%i,T_pos,ND>,ED2,nim2> &skin_elem,\n'%(e.children[num_child]['name'],self.dim) )
      f.write( '      const Number<%s> &num_child,\n'%(num_child) )
      f.write( '      const unsigned *indices) {\n' )
      f.write( '  #define PNODE(N) (*elem.node(N))\n' )
      
    elif T=='N':
      txt = 'ADD_NODAL_MATRIX_%s_%s_%s_%s' % ( self.name, ['false','true','symmetric_version'][symmetric+(assemble_mat==False)], \
            ['false','true'][assemble_mat], ['false','true'][assemble_vec] )
      f.write( '#ifndef '+txt+'\n' )
      f.write( '#define '+txt+'\n' )
      f.write( 'template<class TM,class T,bool wont_add_nz'+BU+'>\n' )
      f.write( 'void add_nodal_matrix(\n' )
      f.write( '      Formulation<TM,%s,DefaultBehavior,T,wont_add_nz> &f,\n' % self.name )
      f.write( '      const typename TM::TNode &node,\n' )
      f.write( '      const Number<%s> &matrix_is_sym,\n'%( ['false','true','symmetric_version'][symmetric+(assemble_mat==False)] ) )
      f.write( '      const Number<%s> &assemble_mat,\n'%( ['false','true'][assemble_mat] ) )
      f.write( '      const Number<%s> &assemble_vec,\n'%( ['false','true'][assemble_vec] ) )
      f.write( '      const unsigned *indices) {\n' )
      f.write( '  #define PNODE(N) node\n' )

    write_matrix( f, matrices[T]['M'], matrices[T]['V'], symmetric, matrices[T]['i'], matrices[T]['o'], assemble_mat, assemble_vec )
    f.write( '  #undef PNODE\n' )
    f.write( '}\n' )

    if T=='N': f.write( '#endif\n' )

  def write( self, e, f=sys.stdout ):
    if isinstance(e,str): e = Element(e,self.dim)
    f.write( '/// @author hugo LECLERC\n' )
    ifndef = self.name.upper()
    for i in range(len(ifndef)):
      if ifndef[i]=='/' or ifndef[i]==',' or ifndef[i]=='.': ifndef = ifndef[:i]+'_'+ifndef[i+1:]
    #f.write( '#ifndef %s\n'%(ifndef) )
    #f.write( '#define %s\n'%(ifndef) )
    f.write( '\n' )
    f.write( '#include "formulation/formulation.h"\n' )
    f.write( 'namespace LMT {\n' )

    # elem and nodal matrices
    self.set_variable_expressions(e)
    matrices,form_after_solve = self.calculate_matrices(e)

    contact_matrices = self.calculate_contact_matrices(e)

    self.write_carac(f,e,matrices,contact_matrices)
    self.write_carac_for_element(f,e,matrices,contact_matrices,form_after_solve)

    for T in ['V','N']+['S'+str(i) for i in range(len(e.children))]:
        for assemble_mat in [True,False]:
            for assemble_vec in [True,False]:
                for symmetric in [False,True][(assemble_mat==False):]:
                    self.write_matrix(f,T,assemble_mat,assemble_vec,symmetric,matrices,e)
    # contact matrices
    #     sub_elems = []
    #     for c in e.children:
    #       if not c['name'] in sub_elems: sub_elems.append( c['name'] )
    #     for name_child in sub_elems:
    #       child = Element( name_child, self.dim, self.incpaths )
    #       for update_only_vec in [True,False]:
    #         for symmetric in [False,True][update_only_vec:]:
    #           self.write_contact_matrix(f,'V',update_only_vec,symmetric,contact_matrices,child)
    #     for update_only_vec in [True,False]:
    #       for symmetric in [False,True][update_only_vec:]:
    #         self.write_contact_matrix(f,'N',update_only_vec,symmetric,contact_matrices,'')


    f.write( '} // namespace LMT\n' )
    f.write( '\n' )
    #f.write( '#endif // %s\n'%(ifndef) )

#   def write_contact_matrix(self,f,T,update_only_vec,symmetric,matrices,e):
#     f.write( '// \n' )
#     BU = ',bool symmetric_version' * update_only_vec
#     if T=='V':
#       f.write( '#ifndef ADD_CONTACT_ELEMENTARY_MATRIX_%s_%s_%i_%i_%i_%i\n'%(e.name,self.name,self.dim,self.nb_form,symmetric,update_only_vec) )
#       f.write( '#define ADD_CONTACT_ELEMENTARY_MATRIX_%s_%s_%i_%i_%i_%i\n'%(e.name,self.name,self.dim,self.nb_form,symmetric,update_only_vec) )
#       f.write( 'template<class T,class TM,class Tnode,class T_pos,class ND,class ED,class TSys,class TTs%s,class CD>\n'%BU )
#       f.write( 'void add_contact_elementary_matrix(\n' )
#       f.write( '      %s<T> f,\n'%(self.name) )
#       f.write( '      Matrix_is_symmetric<%s> mis,\n'%( ['false','true','symmetric_version'][symmetric+update_only_vec] ) )
#       f.write( '      Update_only_vec<%s> uov,\n'%( ['false','true'][update_only_vec] ) )
#       f.write( '      Number<%i> nfo,\n'%self.nb_form )
#       f.write( '      const TM &mesh,\n' )
#       f.write( '      const Tnode &node,\n' )
#       f.write( '      const Element<%s,Node<T_pos,%i,ND>,ED> &elem,\n'%(e.name,self.dim) )
#       f.write( '      TSys &syst,\n' )
#       f.write( '      const unsigned *indices,\n' )
#       f.write( '      T surtension_coefficient,\n' )
#       f.write( '      const CD &cd,\n' )
#       f.write( '      T time,\n' )
#       f.write( '      const TTs &time_steps) {\n' )
#       f.write( '  #define PNODE(N) (*elem.node(N))\n' )
#     elif T=='N':
#       f.write( '#ifndef  ADD_CONTACT_NODAL_MATRIX_%s_%i_%i_%i_%i\n'%(self.name,self.dim,self.nb_form,symmetric,update_only_vec) )
#       f.write( '#define  ADD_CONTACT_NODAL_MATRIX_%s_%i_%i_%i_%i\n'%(self.name,self.dim,self.nb_form,symmetric,update_only_vec) )
#       f.write( 'template<class T,class TM,class Tnode,class TTs,class CD,class TSys%s>\n'%BU )
#       f.write( 'void add_contact_nodal_matrix(\n' )
#       f.write( '      %s<T> f,\n'%self.name )
#       f.write( '      Matrix_is_symmetric<%s> mis,\n'%( ['false','true','symmetric_version'][symmetric+update_only_vec] ) )
#       f.write( '      Update_only_vec<%s> uov,\n'%( ['false','true'][update_only_vec] ) )
#       f.write( '      Number<%i> nfo,\n'%self.nb_form )
#       f.write( '      const TM &mesh,\n' )
#       f.write( '      const Tnode &node,\n' )
#       f.write( '      TSys &syst,\n' )
#       f.write( '      const unsigned *indices,\n' )
#       f.write( '      T surtension_coefficient,\n' )
#       f.write( '      const CD &cd,\n' )
#       f.write( '      T time,\n' )
#       f.write( '      const TTs &time_steps) {\n' )
#       f.write( '  #define PNODE(N) node\n' )
#     write_matrix( f, matrices[T]['M'], matrices[T]['V'], symmetric, matrices[T]['i'], matrices[T]['o'], update_only_vec )
#     f.write( '  #undef PNODE\n' )
#     f.write( '}\n' )
#     f.write( '#endif\n' )
