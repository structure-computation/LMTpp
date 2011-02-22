# -*- coding: utf-8 -*-
f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )
elastic_modulus = Variable( interpolation='global', default_value='210e9', unit='N/m^2' ) #
poisson_ratio = Variable( interpolation='global', default_value='0.33', unit='1' ) # 
density = Variable( interpolation='global', default_value='7800', unit='kg/m^3' ) # 

dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )
tr_epsilon = Variable( interpolation='der_nodal', default_value='0', unit='1' )

f_nodal = Variable( nb_dim=[dim], nb_der=0, default_value='0.0,'*(dim-1)+'0.0', unit='N' )

# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    sigma = mat_sym_to_vec_col( options['behavior_law']( formulation_instance ) )
    epstest = grad_sym_col(dep.test)
  
    res = density.expr * dot( f_vol.expr, dep.test )
    for i in range(dim): res += sigma[i] * epstest[i]
    for i in range(dim,epstest.size()): res += 2 * sigma[i] * epstest[i]
  
    return res * dV + dot( f_nodal.expr, dep.test ) * dN
