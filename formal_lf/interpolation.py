import sys 
class Interpolation:
  def __init__(self, nb_nodal, nb_elementary, nb_global, in_vec=False, nb_skin_elementary=0 ):
    self.nb_nodal = nb_nodal
    self.nb_elementary = nb_elementary
    self.nb_global = nb_global
    self.in_vec = in_vec
    self.nb_skin_elementary = nb_skin_elementary

std_interpolations = {
    "nodal"      : lambda e : Interpolation( nb_nodal = 1, nb_elementary = 0, nb_global = 0 ),
    "nodal_3"    : lambda e : Interpolation( nb_nodal = 1, nb_elementary = 0, nb_global = 0 ),
    "elementary" : lambda e : Interpolation( nb_nodal = 0, nb_elementary = 1, nb_global = 0 ),
    "global"     : lambda e : Interpolation( nb_nodal = 0, nb_elementary = 0, nb_global = 1 ),
    "bubble"     : lambda e : Interpolation( nb_nodal = 1, nb_elementary = 1, nb_global = 0 ),
    "der_nodal"  : lambda e : Interpolation( nb_nodal = 0, nb_elementary = e.get_nb_var("der_nodal"), nb_global = 0, in_vec=True ),
    "gauss"      : lambda e : Interpolation( nb_nodal = 0, nb_elementary = e.get_nb_var("gauss"), nb_global = 0, in_vec=True ),
    "skin_elementary" : lambda e : Interpolation( nb_nodal = 0, nb_elementary = 0, nb_global = 0, nb_skin_elementary=1 ),
    "elementary_mul_nb_nodes" : lambda e : Interpolation( nb_nodal = 0, nb_elementary = e.nb_nodes, nb_global = 0, in_vec=True ),
    "elementary_mul_nb_nodes_of_each_children_elem" : \
        lambda e : Interpolation( nb_nodal = 0, nb_elementary = e.sum_nb_nodes_of_each_children(), nb_global = 0, in_vec=True ),
}

for i in range( 1, 10 ):
    std_interpolations[ "P+"+str(i-1) ] = lambda e : Interpolation( nb_nodal = 0, nb_elementary = i*(i+1)/2, nb_global = 0, in_vec=True )
    