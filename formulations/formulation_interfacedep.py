dep = Variable( unknown=True, nb_dim=[dim], nb_der=2, default_value='0.0', unit='m' )
pressure = Variable( nb_der=2, default_value='0.0', unit='Pa' )

f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )
elastic_modulus = Variable( interpolation='global', default_value='14.4e9', unit='N/m^2' ) # 
poisson_ratio = Variable( interpolation='global', default_value='0.2', unit='1' ) # 
density = Variable( interpolation='global', default_value='7800', unit='kg/m^3' ) # 
coeff_biot = Variable( interpolation='global', default_value='0.78', unit='1' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1', nb_der=2 )

#
def formulation():
  epsilon = grad_sym_col(dep.expr)
  epstest = grad_sym_col(dep.test)
  
  sigma = mul( hooke_matrix(elastic_modulus.expr,poisson_ratio.expr,dim) ,epsilon )
  
  res = sum([ sigma[i] * epstest[i] * (1+(i>dim)) for i in range(epsilon.size())])
         
  trepstest = sum([ epstest[i] for i in range(dim) ])
  res -= coeff_biot.expr * pressure.expr * trepstest
  
  return res * dV + density * dot(dep.expr,dep.test) * dS

def apply_on_elements_after_solve(): # return a string
    H = hooke_matrix(elastic_modulus.expr,poisson_ratio.expr,dim)
    epsilon = grad_sym_col(dep.expr)
    sigma = mul( H, epsilon )
    
    sigma = sigma.subs(time,time_steps[0])
    for vi in e.var_inter: sigma = sigma.subs(vi,0)
    
    epsilon = epsilon.subs(time,time_steps[0])
    for vi in e.var_inter: epsilon = epsilon.subs(vi,0)
    
    cw = Write_code('T')
    for i in range(dim*(dim+1)/2):
        cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i], 'elem.epsilon[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i].diff(time), 'elem.der1_epsilon[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i].diff(time).diff(time), 'elem.der2_epsilon[0]['+str(i)+']', Write_code.Set )
    return cw.to_string()

