# -*- coding: utf-8 -*-
import extrapolation, sys
from include.codegen import *

class Variable:
  """ Class to manage Variables (unknowns or not, nodal, elementary or global) """
  def __init__(self,unit,interpolation="nodal",unknown=False,nb_dim=[],nb_der=0,skin_var=False,default_value="",extr=extrapolation.Pol_extr,sup_nb_der=0,T="",dont_use_caracdm = False, sym = False, id_dependant = 0):
    self.interpolation = interpolation
    self.interpolation_gauss_order = interpolation
    self.nb_dim = nb_dim
    self.nb_der = nb_der
    self.skin_var = skin_var
    self.unknown = unknown
    self.default_value = default_value
    self.sup_nb_der = sup_nb_der
    self.extrapolation = extr
    self.T = T
    self.unit = unit
    self.dont_use_caracdm = dont_use_caracdm
    self.sym = sym
    self.id_dependant = id_dependant

  def extr(self,test_expr=False): return self.extrapolation( (self.nb_der+self.sup_nb_der)*(not test_expr) )
    
  def type_to_str(self,in_vec,vec_size):
        if len(self.T): res = self.T
        elif len(self.nb_dim)==1: res = "Vec<Tpos,"+str(self.nb_dim[0])+">"
        elif len(self.nb_dim)==2: 
              if self.sym:
                #if self.nb_dim[1]!=self.nb_dim[0]: probleme
                res = "Mat<Tpos,Sym<"+str(self.nb_dim[0])+"> >"
              else:
                res = "Mat<Tpos,Gen<"+str(self.nb_dim[0])+","+str(self.nb_dim[1])+"> >"
        else: res = "Tpos"
        
        if in_vec: res = 'Vec<' + res + ',' + str( vec_size ) + '>'
        #id_dependant, a redimensinner (dynamique)
        for id_ in range(self.id_dependant): res = 'Vec<' + res + ' >'
        return res

  def nb_elements(self):
        res = 1
        for i in self.nb_dim: res *= i
        return res

  def join(self, obj):
        self.nb_der = max( self.nb_der, obj.nb_der )
        obj.nb_der = max( self.nb_der, obj.nb_der )

  def get_scalar_expr(self,name_var,interpolation,element,num_element,symbols,test_expr=False):
    """ Fill gnagna.expr for all gnagna in variables """
    map_sym = {}
    cpt = 0
    def append_s(beg,v,t,num_elem,num_t,in_vec):
      """ t is type of var -> nodal, elem, ... """
      ts = {'nodal':0,'elementary':1,'global':2,'skin_elementary':3}[t]
      # get a new symbol
      def s_sec_part(beg,i):
        vec_access = ''
        #sys.stderr.write( interpolation )
        #sys.stderr.write( t )
        for id_ in range(self.id_dependant):
          vec_access += '[f.id['+str(id_)+']]'
        if in_vec:
            vec_access += '['+str( num_t )+']'
        if len(self.nb_dim) == 1:
            vec_access += '['+str(num_element[0])+']'
        elif len(self.nb_dim) == 2:
            vec_access += '('+str(num_element[0])+','+str(num_element[1])+')'
        # normal
        st = beg+'.'
        if self.unknown:
          st += ('old'+str(i)+'_')*(i!=0) + name_var
        else:
          st += ('der'+str(i)+'_')*(i!=0) + name_var
        st += vec_access
        # LaTeX
        st_tex = name_var
        st_tex += ('_{'+str(num_element)+'}') * (len(self.nb_dim)!=0)
        st_tex += ('^{('+str(i)+')}')*(i!=0)
        st_tex += '['+str(num_elem)+']'
        return symbol( st, st_tex )
      loc_sym = []
      if self.unknown:
        res = {}
        extra = self.extr(test_expr)
        for i in range(extra.order+1):
          s = s_sec_part(beg,i)
          res[ extrapolation.symbols[i] ] = s
          loc_sym.append( s )
        map_sym[ v ] = extra.form().subs(EM( res ))
      elif test_expr==False:
        res = s_sec_part(beg,0)
        loc_sym.append( res )
        fact = 1.0
        for i in range(1,self.nb_der*(not test_expr)+1):
          fact *= i
          s = s_sec_part(beg,i)
          POW = 1
          for ii in range(i): POW *= extrapolation.time
          res += s * POW * (1.0/fact)
          loc_sym.append( s )
        map_sym[ v ] = res
      symbols.append( (ts, num_elem, num_element, loc_sym) )
    for t,t_alt in zip(['nodal','elementary','global','skin_elementary'],['mega pouet','elem','(*f.m)','skin_elem']):
      setattr(self,t+'_symbol',[])
      nb_of_t = getattr(interpolation,'nb_'+t)
      for num_t in range(nb_of_t):
        if t=='nodal':
          for i in range(element.nb_nodes):
            append_s( 'PNODE('+str(i)+')', element.val[cpt], t, i, num_t, interpolation.in_vec )
            cpt += 1
        else:
          append_s( t_alt, element.val[cpt], t, 0, num_t, interpolation.in_vec )
          cpt += 1

    return element.interpolation[self.interpolation_gauss_order].subs(EM( map_sym ))

  def set_expr(self,name_var,interpolation,element):
    self.element = element
    self.name = name_var
    self.interpolation_inst = interpolation
    self.symbols = []
    if len(self.nb_dim) == 2:
        self.sub_expr = []
        self.expr = ExMatrix(self.nb_dim[0],self.nb_dim[1])
        if self.sym:
          for i in range(self.nb_dim[0]):
            self.expr[i,i] = self.get_scalar_expr(self.name,interpolation,element,[i,i],self.symbols)
            for j in range(i+1,self.nb_dim[1]):
                self.expr[i,j] = self.get_scalar_expr(self.name,interpolation,element,[i,j],self.symbols)
                self.expr[j,i] = self.expr[i,j]
                self.sub_expr.append( self.expr[i,j] )
                self.sub_expr.append( self.expr[j,i] )
        else:
          for i in range(self.nb_dim[0]):
            for j in range(self.nb_dim[1]):
                self.expr[i,j] = self.get_scalar_expr(self.name,interpolation,element,[i,j],self.symbols)
                self.sub_expr.append( self.expr[i,j] )

        md = len(self.symbols) / self.nb_elements()
      
        self.expr_on_node = []
        for i in range(md):
            tmp = ExVector(self.nb_dim[0])
            for d in range(self.nb_dim[0]):
                tmp[d] = self.symbols[i+md*d][3][0]
            self.expr_on_node.append( tmp )
    elif len(self.nb_dim) == 1:
        self.sub_expr = []
        self.expr = ExVector(self.nb_elements())
        for i in range(self.nb_elements()):
            self.expr[i] = self.get_scalar_expr(self.name,interpolation,element,[i],self.symbols)
            self.sub_expr.append( self.expr[i] )

        #print self.nb_elements()
        #print len(self.symbols)
        md = len(self.symbols) / self.nb_elements()
      
        self.expr_on_node = []
        for i in range(md):
            tmp = ExVector(self.nb_dim[0])
            for d in range(self.nb_dim[0]): tmp[d] = self.symbols[i+md*d][3][0]
            self.expr_on_node.append( tmp )
    else:
        self.expr = self.get_scalar_expr(self.name,interpolation,element,[0],self.symbols)
        self.sub_expr = [ self.expr ]
    
        md = len(self.symbols) / self.nb_elements()
        self.expr_on_node = []
        for i in range(md):
            self.expr_on_node.append( self.symbols[i][3][0] )

    #to create the old value of the unknown #################################################
    if self.unknown:
      res =  []
      for t,n,n2,v in self.symbols:
          res.append( (t,n,0,n2,v) )
      res.sort()
      indices,offsets = [], []
      cpt_indice,cpt_offset = -1,0
      old_ne = (0,-1)
      old_unk_subs = {}
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
          old_unk_subs[ s[i] ] = symbol( 'vectors[%i][indices[%i]+%i]' % (i,cpt_indice,cpt_offset) )
      self.old_expr = self.expr.subs(EM(old_unk_subs))
    #################################################

    # test symbols
    self.test_symbols = []
    if len(self.nb_dim) == 2:
        self.sub_test_expr = []
        self.test = ExMatrix(self.nb_dim[0],self.nb_dim[1])
        for i in range(self.nb_dim[0]):
            for j in range(self.nb_dim[1]):
                self.test[i,j] = self.get_scalar_expr( "T"+self.name, interpolation, element, [i,j], self.test_symbols, True )
                self.sub_test_expr.append( self.test[i,j] )
        #print self.nb_elements()
        #print len(self.test_symbols)
        md = len(self.test_symbols) / self.nb_elements()
      
        if len(self.test_symbols[0][3]):
            self.test_on_node = []
            for i in range(md):
                tmp = ExVector(self.nb_dim[0])
                for d in range(self.nb_dim[0]):
                    tmp[d] = self.test_symbols[i+md*d][3][0]
                self.test_on_node.append( tmp )
    elif len(self.nb_dim):
        self.sub_test_expr = []
        self.test = ExVector(self.nb_elements())
        for i in range(self.nb_elements()):
            self.test[i] = self.get_scalar_expr( "T"+self.name, interpolation, element, [i], self.test_symbols, True )
            self.sub_test_expr.append( self.test[i] )
        #print self.nb_elements()
        #print len(self.test_symbols)
        md = len(self.test_symbols) / self.nb_elements()
      
        if len(self.test_symbols[0][3]):
            self.test_on_node = []
            for i in range(md):
                tmp = ExVector(self.nb_dim[0])
                for d in range(self.nb_dim[0]):
                    tmp[d] = self.test_symbols[i+md*d][3][0]
                self.test_on_node.append( tmp )
    else:
      self.test = self.get_scalar_expr( "test_"+self.name, interpolation, element, [0], self.test_symbols, True )
      self.sub_test_expr = [ self.test ]
    
      md = len(self.symbols) / self.nb_elements()
      self.test_on_node = []
      if self.unknown:
          for i in range(md):
              self.test_on_node.append( self.test_symbols[i][3][0] )
    return self.test

  def name_set_unknown(self,t,num_der,d):
    TE = {'nodal':'node','elementary':'elem','global':'(*f.m)','skin_elementary':'skin_elem'}[ t ]
    der = ('der'+str(num_der)+'_') * (num_der!=0)
    res = TE+'.'+der+self.name + ('['+str(d)+']')*(d>=0)
    return res

  def __add__(self,other):  return self.expr + other
  def __radd__(self,other): return other + self.expr
  def __sub__(self,other):  return self.expr - other
  def __rsub__(self,other): return other - self.expr
  def __mul__(self,other):  return self.expr * other
  def __rmul__(self,other): return other * self.expr
  def __div__(self,other):  return self.expr / other
  def __rdiv__(self,other): return other / self.expr
  def __pow__(self,other):  return pow(self.expr,other)
  def __rpow__(self,other): return pow(other,self.expr)
  def __neg__(self): return - self.expr
  def diff(self,x): return self.expr.diff(x)
  def subs(self,x): return self.expr.subs(x)

  
  
  
class ISVariable:
  """ Class to manage Variables on solids """
  
  def __init__(self,unit,nb_dim=[],nb_der=0,default_value="",T=""):
    self.interpolation = "global"
    self.nb_dim = nb_dim
    self.nb_der = nb_der
    self.default_value = default_value
    self.T = T
    self.unit = unit

  def type_to_str(self,in_vec,vec_size):
    if len(self.T): res = self.T
    elif len(self.nb_dim)==1: res = "Vec<Tpos,"+str(self.nb_dim[0])+">"
    elif len(self.nb_dim)==2: res = "Mat<Tpos,Gen<"+str(self.nb_dim[0])+","+str(self.nb_dim[1])+"> >"
    else: res = "Tpos"
    
    if in_vec: res = 'Vec<' + res + ',' + str( vec_size ) + '>'
    return res

  def nb_elements(self):
    res = 1
    for i in self.nb_dim: res *= i
    return res

  def get_scalar_expr(self,name_var,num_element,symbols):
    """ Fill gnagna.expr for all gnagna in variables """
    if len(self.nb_dim)==0: # scalar
      res = symbol( 'cd.data->%s'%name_var )
      symbols.append( res )
      return res
    res = symbol( 'cd.data->%s[%i]'%(name_var,num_element) )
    symbols.append( res )
    return res

  def set_expr(self,name_var):
    self.name = name_var
    self.symbols = []
    if len(self.nb_dim):
      self.sub_expr = [ self.get_scalar_expr(self.name,i,self.symbols) for i in range(self.nb_elements()) ]
      self.expr = ExVector(len(self.sub_expr))
      for i in range(len(self.sub_expr)): self.expr[i] = self.sub_expr[i]
    else:
      self.expr = self.get_scalar_expr(self.name,0,self.symbols)
      self.sub_expr = [ self.expr ]
    

  def join(self, obj):
    self.nb_der = max( self.nb_der, obj.nb_der )
    obj.nb_der = max( self.nb_der, obj.nb_der )
