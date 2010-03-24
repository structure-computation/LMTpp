dep = Variable( unknown=True, nb_dim=[dim], nb_der=1, default_value='0.0', unit='m' )
pressure = Variable( nb_der=1, default_value='380e6*0', unit='Pa' )

f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0', unit='N/m^3' )
f_surf = Variable( interpolation='skin_elementary', nb_dim=[dim], default_value='0.0', unit='N' )

elastic_modulus = Variable( interpolation='global', default_value='14.4e9', unit='N/m^2' ) # 
poisson_ratio = Variable( interpolation='global', default_value='0.2', unit='1' ) # 
coeff_biot = Variable( interpolation='global', default_value='0.78', unit='1' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
tr_epsilon = Variable( interpolation='der_nodal', default_value='0', unit='1', nb_der=1 )

#
def formulation():
  epsilon = grad_sym_col(dep.expr)
  epstest = grad_sym_col(dep.test)
  
  sigma = mul( hooke_matrix(elastic_modulus.expr,poisson_ratio.expr,dim) ,epsilon )
  
  res = sum([ sigma[i] * epstest[i] * (1+(i>=dim)) for i in range(epsilon.size())])
  res -= coeff_biot.expr * pressure.expr * sum([ epstest[i] for i in range(dim) ])

  return res * dV + dot( f_surf.expr, dep.test ) * dS

def apply_on_elements_after_solve(unk_subs): # return a string
    H = hooke_matrix(elastic_modulus.expr,poisson_ratio.expr,dim)
    epsilon = grad_sym_col(dep.expr)
    tr_epsilon = sum([ epsilon[i] for i in range(dim) ])
    der1_tr_epsilon = tr_epsilon.diff(time)
    der2_tr_epsilon = der1_tr_epsilon.diff(time)
    sigma = mul( H, epsilon )

    my_subs = unk_subs
    my_subs[ time ] = time_steps[0]
    for vi in e.var_inter: my_subs[vi] = number(0.5)
    
    sigma = sigma.subs(EM(my_subs))
    tr_epsilon = tr_epsilon.subs(EM(my_subs))
    der1_tr_epsilon = der1_tr_epsilon.subs(EM(my_subs))
    der2_tr_epsilon = der2_tr_epsilon.subs(EM(my_subs))
    
    cw = Write_code('T')
    cw.add( tr_epsilon, 'elem.tr_epsilon[0]', Write_code.Set )
    cw.add( der1_tr_epsilon, 'elem.der1_tr_epsilon[0]', Write_code.Set )
    #cw.add( der2_tr_epsilon, 'elem.der2_tr_epsilon[0]', Write_code.Set )
    for i in range(dim*(dim+1)/2):
        cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
    return cw.to_string()
    