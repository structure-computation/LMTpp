# supplementary_order_for_time_integration = 4

f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )
elastic_modulus = Variable( interpolation='global', default_value='210e9', unit='N/m^2' ) #
poisson_ratio = Variable( interpolation='global', default_value='0.33', unit='1' ) # 
density = Variable( interpolation='global', default_value='7800', unit='kg/m^3' ) # 

dep = Variable( unknown=True, nb_dim=[dim], nb_der=0, default_value='0.0', unit='m' )
temperature = Variable( default_value='0.0', unit='K' )

fibres_matrice_level_set = Variable( default_value='1', unit='1' ) # 

toto= Variable( nb_dim = [2,2], unit='1' ) # 

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )
tr_epsilon = Variable( interpolation='der_nodal', default_value='0', unit='1' )

#epsilon_moy = Variable( interpolation='global', unknown=True, default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )
#wanted_epsilon_moy = Variable( interpolation='global', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1' )
# salut

f_nodal = Variable( nb_dim=[dim], nb_der=0, default_value='0.0,'*(dim-1)+'0.0', unit='N' )
f_surf = Variable( interpolation='skin_elementary', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^2' )
p = Variable( interpolation='skin_elementary', default_value='0.0', unit='N/m^2' )

integration_truc = Variable( interpolation='global', default_value='0', unit='kg/m^3' ) # 

#assume_symmetric_matrix = False
integration_totale = False
# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    #
    #dep_inf = dep.expr.subs( e.var_inter[dim-1], 0 )
    #dep_sup = dep.expr.subs( e.var_inter[dim-1], 1 )
    #X = pos.expr.diff( e.var_inter[0] )
    #if dim == 3:
        #Y = pos.expr.diff( e.var_inter[1] )
        #normale = vect_prod( X, Y )
    #else:
        #normale = [ -X[1], X[0] ]
    #dJ = length( normale )
    #normale /= norm( normale )
    #salto_de_u = dot( dep_sup - dep_inf, normale )
    #return e.integration( res, 2, False ) * dJ * dEheavyside( fibres_matrice_level_set.expr )
    E = elastic_modulus.expr # * ( 2 + cos( pos.expr[0] ) )
    epsilon = grad_sym_col(dep.expr)
    #epsilno_p = grad_sym_col(dep.expr).diff(time)
    epstest = grad_sym_col(dep.test)
    sigma = mul( hooke_isotrope_th( E, poisson_ratio.expr,  dim, 0., options['behavior_simplification'] )[0] , epsilon )
        
    res = density.expr * dot( dep.expr.diff(time).diff(time) - f_vol.expr * 0, dep.test )
    for i in range(dim): res += sigma[i] * epstest[i]
    for i in range(dim,epsilon.size()): res += 2 * sigma[i] * epstest[i]
    #res.display_graphviz()
    
    #res += dot( epsilon_moy.expr - epsilon, epsilon_moy.test - epstest ) * elastic_modulus.expr * 1e5
    #res += dot( epsilon_moy.expr - wanted_epsilon_moy.expr, epsilon_moy.test ) * elastic_modulus.expr * 1e5
    
    return res * dV + dot( f_nodal.expr, dep.test ) * dN - dot( f_surf.expr, dep.test ) * dS - dot( p.expr * dS_normal, dep.test ) * dS


# --------------------------------------------------------------------------------------------------------------------------------
def apply_on_elements_after_solve(unk_subs): # return a string
    E = elastic_modulus.expr # * ( 1 + heavyside( fibres_matrice_level_set.expr ) )
    epsilon = grad_sym_col(dep.expr)
    tr_epsilon = sum([ epsilon[i] for i in range(dim) ])
    sigma = mul( hooke_isotrope_th( E, poisson_ratio.expr,  dim, 0., options['behavior_simplification'] )[0] , epsilon )
  
    my_subs = unk_subs
    my_subs[ time ] = time_steps[0]
    for vi in e.var_inter: my_subs[vi] = number(0.33)

    sigma = sigma.subs(EM(my_subs))
    epsilon = epsilon.subs(EM(my_subs))
    tr_epsilon = tr_epsilon.subs(EM(my_subs))

    cw = Write_code('T')
    #cw.add( e.integration( trace_sym_col( sigma, epsilon ), 2 ), 'f.m->integration_ener', Write_code.Add )
    #cw.add( tr_epsilon, 'elem.tr_epsilon', Write_code.Set )
    for i in range(dim*(dim+1)/2):
        cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
        cw.add( epsilon[i], 'elem.epsilon[0]['+str(i)+']', Write_code.Set )
    return cw.to_string()

#def apply_on_elements_after_solve_2(unk_subs): # return a string
    #epsilon = grad_sym_col(dep.expr)
    #sigma = mul( hooke_isotrope_th( elastic_modulus.expr, poisson_ratio.expr,  dim, 0., options['behavior_simplification'] )[0], epsilon )
    #sigma_mat = vec_col_to_mat_sym( sigma )
    
    ##sigma[0].display_graphviz()
    ##print unk_subs
    ###print sigma[0]
    ##pouet
    #normal = e.normal()
    
    #cw = Write_code('T')
    #cw.add( e.integration( mul( sigma_mat, e.normal() ), 0 ), 'f.m->integration_truc', Write_code.Add )
    #return cw.to_string()



