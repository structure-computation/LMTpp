# -*- coding: utf-8 -*-
dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
dep_sens = Variable( nb_dim=[dim], default_value='0.0', unit='m' )

lum = Variable( unknown=True, default_value='1.0', unit='1' )

normal = Variable( nb_dim=[dim], default_value='0.0', unit='1' )

epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )

# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    H, epsth = hooke_isotrope(1,0,dim,'plane stress')
    return dot( mul( H, grad_sym_col( dep.expr ) ), grad_sym_col( dep.expr ) ) * dV

def apply_on_elements_after_solve(unk_subs):
    epsilon = grad_sym_col(dep.expr)
    #tr_epsilon = sum([ epsilon[i] for i in range(dim) ])
    #sigma = mul( hooke_isotrope( E, poisson_ratio.expr,  dim, options['behavior_simplification'] )[0] , epsilon )
  
    my_subs = unk_subs
    my_subs[ time ] = time_steps[0]
    for vi in e.var_inter: my_subs[vi] = number(0.5)

    #sigma = sigma.subs(EM(my_subs))
    epsilon = epsilon.subs(EM(my_subs))
    #tr_epsilon = tr_epsilon.subs(EM(my_subs))

    cw = Write_code('T')
    #cw.add( e.integration( trace_sym_col( sigma, epsilon ), 2 ), 'f.m->integration_ener', Write_code.Add )
    #cw.add( tr_epsilon, 'elem.tr_epsilon', Write_code.Set )
    for i in range(dim*(dim+1)/2):
        #cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i], 'elem.epsilon[0]['+str(i)+']', Write_code.Set )
        
    return cw.to_string()




