f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )
density = Variable( interpolation='global', default_value='1', unit='kg/m^3' )
elastic_modulus_1 = Variable( interpolation='global', default_value='157e3', unit='N/mm^2')
elastic_modulus_2 = Variable( interpolation='global', default_value='80e3', unit='N/mm^2' )
elastic_modulus_3 = Variable( interpolation='global', default_value='80e3' , unit='N/mm^2')
poisson_ratio_12 = Variable( interpolation='global', default_value='0.33' , unit='')
poisson_ratio_13 = Variable( interpolation='global', default_value='0.33' , unit='')
poisson_ratio_23 = Variable( interpolation='global', default_value='0.33' , unit='')
shear_modulus_12 = Variable( interpolation='global', default_value='50e3' , unit='N/mm^2')
shear_modulus_13 = Variable( interpolation='global', default_value='50e3' , unit='N/mm^2')
shear_modulus_23 = Variable( interpolation='global', default_value='50e3', unit='N/mm^2' )
#type_stress = Variable( interpolation='global', default_value='plane stress', unit='' )
deltaT = Variable( interpolation='global', default_value='0', unit='degC' )
alpha_1 = Variable( interpolation='global', default_value='0', unit='' )
alpha_2 = Variable( interpolation='global', default_value='0', unit='' )
alpha_3 = Variable( interpolation='global', default_value='0', unit='' )
v1 = Variable( interpolation='global', nb_dim=[3], default_value='1.0, 0.0, 0.0', unit='' )
v2 = Variable( interpolation='global', nb_dim=[3], default_value='0.0, 1.0, 0.0', unit='' )

dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='mm' )
dep_sv = Variable( nb_dim=[dim], default_value='0.0', unit='mm' )

f_nodal = Variable( nb_dim=[dim], default_value='0.0', unit='N' )
f_surf = Variable( interpolation='skin_elementary', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^2' ) # force surfacique

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/mm^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='' )
ener = Variable( interpolation='elementary', default_value='0', unit='N*mm' )

use_asm = True

def formulation():
    epsilon = grad_sym_col(dep.expr)
    epstest = grad_sym_col(dep.test)
    K,sigth,P = hooke_orthotrope_th(
        elastic_modulus_1.expr,elastic_modulus_2.expr,elastic_modulus_3.expr,
        poisson_ratio_12.expr,poisson_ratio_13.expr,poisson_ratio_23.expr,
        shear_modulus_12.expr,shear_modulus_13.expr,shear_modulus_23.expr,v1.expr,v2.expr,alpha_1.expr,alpha_2.expr,alpha_3.expr,dim,'plane strain'
    )
    
    sigma = mul(K,epsilon) - sigth * deltaT.expr
    
    #res = density.expr * dot( dep.expr.diff(time).diff(time) - f_vol.expr, dep.test )
    res=0
    for i in range(dim): res += sigma[i] * epstest[i]
    for i in range(dim,epsilon.size()): res += 2 * sigma[i] * epstest[i]
            
    return res * dV - dot( f_nodal.expr, dep.test ) * dN - dot( f_surf.expr, dep.test ) * dS

def apply_on_elements_after_solve(unk_subs): # return a string
    epsilon = grad_sym_col(dep.expr)
    K,sigth,P = hooke_orthotrope_th(
        elastic_modulus_1.expr,elastic_modulus_2.expr,elastic_modulus_3.expr,
        poisson_ratio_12.expr,poisson_ratio_13.expr,poisson_ratio_23.expr,
        shear_modulus_12.expr,shear_modulus_13.expr,shear_modulus_23.expr,v1.expr,v2.expr,alpha_1.expr,alpha_2.expr,alpha_3.expr,dim,'plane strain'
    )
    
    sigma = mul(K,epsilon) - sigth*deltaT.expr
    #sigma = grad_sym_col(dep.expr)
    
    ener=0
    for i in range(dim): ener += sigma[i] * epsilon[i]
    for i in range(dim,epsilon.size()): ener += 2. * sigma[i] * epsilon[i]
    ener = e.integration( ener, 2 )/2
    #my_subs = unk_subs
    #my_subs[ time ] = time_steps[0]
    #for vi in e.var_inter: my_subs[vi] = number(0.5)
    
    #sigma = sigma.subs(EM(my_subs))
    #epsilon = epsilon.subs(EM(my_subs))
    
    #print sigma[0]
    cw = Write_code('T')
    #for i in range(dim*(dim+1)/2):
        #cw.add( epsilon[i], 'elem.epsilon[0]['+str(i)+']', Write_code.Set )
        #cw.add( sigma[i], 'elem.sigma[0]['+str(i)+']', Write_code.Set )
    cw.add( sigma[0], 'elem.sigma[0][0]', Write_code.Set )
    #cw.add( ener, 'elem.ener', Write_code.Set )  
    sys.stderr.write("pouetmaster\n")
    res = cw.to_string()
    sys.stderr.write("end pouetmaster\n")
    return res

