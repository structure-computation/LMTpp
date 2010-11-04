# -*- coding: utf-8 -*-
elastic_modulus = Variable( interpolation='global', default_value='210e9', unit='N/m^2' ) #
poisson_ratio = Variable( interpolation='global', default_value='0.33', unit='1' ) # 
density = Variable( interpolation='global', default_value='7800', unit='kg/m^3' ) # 

U = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
V = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
W = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
lambd = Variable( unknown=True, default_value='0.0', unit='1' )

Ud = Variable( nb_dim=[dim], default_value='0.0', unit='m' )
Ud_valid = Variable( default_value='0.0', unit='m' )

f_nodal = Variable( nb_dim=[dim], nb_der=0, default_value='0.0,'*(dim-1)+'0.0', unit='N' )
f_surf = Variable( interpolation='skin_elementary', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^2' )
f_vol = Variable( interpolation='global', nb_dim=[dim], default_value='0.0,'*(dim-1)+'0.0', unit='N/m^3' )

gamma = Variable( interpolation='global', default_value='0.5', unit='1' )
r = Variable( interpolation='global', default_value='0.5', unit='1' )
omega = Variable( interpolation='global', default_value='187', unit='Hz' )

use_test_functions = False

# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    def norme_sigma( expr, K ):
        return trace_sym_col( expr, mul( K.inverse(), expr ) ) * dV
    def norme_gamma( expr, K ):
        return 1 / ( density.expr * omega.expr ** 2 ) * dot( expr, expr ) * dV
    def norme_G( expr, K ):
        return elastic_modulus.expr * dot( expr, expr ) * dN
    
    K = hooke_isotrope_th( elastic_modulus.expr, poisson_ratio.expr,  dim, 0., options['behavior_simplification'] )[0]
    #
    epsilon_V = grad_sym_col(V.expr)
    epsilon_U = grad_sym_col(U.expr)
    sigma_V = mul( K, epsilon_V )
    sigma_U = mul( K, epsilon_U )
    
    gamma_w = density.expr * omega.expr * W.expr
    gamma_u = density.expr * omega.expr * U.expr
    
    res = gamma * norme_sigma( sigma_V - sigma_U, K )
    res += (1-gamma) * norme_gamma( gamma_w - gamma_u, K )
    res += Ud_valid.expr * r.expr / ( 1 - r.expr ) * norme_G( U.expr - Ud.expr, K )
        
    return res
    
    
