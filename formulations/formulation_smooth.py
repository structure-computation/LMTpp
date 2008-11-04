dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
normal = Variable( nb_dim=[dim], default_value='0.0', unit='m' )

#use_test_functions = False
assume_symmetric_matrix = False

#
def formulation():
    ## jacobian
    #jac = ExMatrix( e.nb_var_inter, e.dim )
    #for j in range(e.nb_var_inter):
        #for i in range(e.dim):
            #jac[j,i] = ( pos.expr[i] + dep.expr[i] ).diff( e.var_inter[j] )
    #inv_jac = jac.inverse()
    
    ## energy
    #res = 0
    #for d in range( e.nb_var_inter ):
        #tmp = 0
        #for i in range( e.nb_var_inter ):
            #tmp += s.diff( e.var_inter[i] ) * inv_jac[j,i]
        #res += tmp ** 2
    #res = e.analytical_integration( res, 4 )
    
    ##
    #m = ExMatrix( e.nb_nodes, e.nb_nodes )
    #for i in range( e.nb_nodes ):
        #for j in range( e.nb_nodes ):
            #m[i,j] = res.diff( s.expr_on_node[i] ).diff( s.expr_on_node[j] )
    #eig_vec = m.find_eigen_values_sym()
    #eig_cmp = m.diag().sum() * 1e-6
    
    ##
    #d = 0
    #for i in range( e.nb_nodes ):
        #for j in range( i+1, e.nb_nodes ):
            #d += ( eig_vec[j] - eig_vec[i] )**2 # * heaviside( eig_vec[i] - eig_cmp ) * heaviside( eig_vec[j] - eig_cmp )
            
    #return d * dE
    
    de = ExVector( e.nb_nodes )
    dt = ExVector( e.nb_nodes )
    for i in range( e.nb_nodes ):
        j = ( i + 1 ) % e.nb_nodes
        de[ i ] = norm( pos.expr_on_node[i] + dep.expr_on_node[i] - pos.expr_on_node[j] - dep.expr_on_node[j] )
        dt[ i ] = norm( pos.expr_on_node[i] + dep.test_on_node[i] - pos.expr_on_node[j] - dep.test_on_node[j] )
    me = de.sum() / de.size()
    mt = dt.sum() / dt.size()
    
    res = 0
    for i in range( e.nb_nodes ):
        res += ( me - de[i] ) * ( mt - dt[i] )

    return res * dE
    
    