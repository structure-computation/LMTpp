# supplementary_order_for_time_integration = 4

f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )
elastic_modulus = Variable( interpolation='global', default_value='210e9', unit='N/m^2' ) #
poisson_ratio = Variable( interpolation='global', default_value='0.33', unit='1' ) # 
density = Variable( interpolation='global', default_value='7800', unit='kg/m^3' ) # 

dep = Variable( unknown=True, nb_dim=[dim], nb_der=0, default_value='0.0', unit='m' )
temperature = Variable( default_value='0.0', unit='K' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )
tr_epsilon = Variable( interpolation='der_nodal', default_value='0', unit='1' )

f_nodal = Variable( nb_dim=[dim], nb_der=0, default_value='0.0,'*(dim-1)+'0.0', unit='N' )
f_surf = Variable( interpolation='skin_elementary', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^2' )
p = Variable( interpolation='skin_elementary', default_value='0.0', unit='N/m^2' )

d      = Variable( interpolation='elementary', default_value='0', unit='1' ) # 
d_evol = Variable( interpolation='elementary', default_value='0', unit='1' ) # 
d_pond = Variable( interpolation='elementary', default_value='0', unit='1' ) # 
d_sum  = Variable( interpolation='elementary', default_value='0', unit='1' ) # 


#assume_symmetric_matrix = False
integration_totale = False
# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    E = elastic_modulus.expr # * ( 2 + cos( pos.expr[0] ) )
    epsilon = grad_sym_col(dep.expr)
    epstest = grad_sym_col(dep.test)
    H = hooke_isotrope( E * ( 1 - d ), poisson_ratio.expr, dim, options['behavior_simplification'] )[0]
    sigma = mul( H, epsilon )
    
    res = density.expr * dot( dep.expr.diff(time).diff(time) - f_vol.expr, dep.test )
    res += trace_sym_col( sigma, epstest )
    
    return res * dV + dot( f_nodal.expr, dep.test ) * dN - dot( f_surf.expr, dep.test ) * dS - dot( p.expr * dS_normal, dep.test ) * dS



# --------------------------------------------------------------------------------------------------------------------------------
def apply_on_elements_after_solve(unk_subs): # return a string
    E = elastic_modulus.expr # * ( 1 + heavyside( fibres_matrice_level_set.expr ) )
    epsilon = grad_sym_col(dep.expr)
    tr_epsilon = sum([ epsilon[i] for i in range(dim) ])
    sigma = mul( hooke_isotrope( E * ( 1 - d ), poisson_ratio.expr,  dim, options['behavior_simplification'] )[0] , epsilon )
  
    my_subs = unk_subs
    my_subs[ time ] = time_steps[0]
    for vi in e.var_inter: my_subs[vi] = number(0.5)

    sigma = sigma.subs(EM(my_subs))
    epsilon = epsilon.subs(EM(my_subs))
    tr_epsilon = tr_epsilon.subs(EM(my_subs))

    cw = Write_code('T')
    #cw.add( e.integration( trace_sym_col( sigma, epsilon ), 2 ), 'f.m->integration_ener', Write_code.Add )
    #cw.add( tr_epsilon, 'elem.tr_epsilon', Write_code.Set )
    for i in range(dim*(dim+1)/2):
        cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i], 'elem.epsilon[0]['+str(i)+']', Write_code.Set )
        
        
    d_evol = 1e3 * abs( e.mean( dot( epsilon, epsilon ), 2 ) )
    cw.add( d_evol, 'elem.d_evol', Write_code.Set )
    
    return cw.to_string()
