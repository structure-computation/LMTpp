# -*- coding: utf-8 -*-
X = Variable( unknown=True, default_value='1.0', nb_der=1, unit='1' )

order_integration = 5
 
#
def formulation():
    #x,xe = X.expr,X.test
    #x2  = ( 1 - e.var_inter[0] ) * X.expr_on_node[0] + e.var_inter[0] * X.expr_on_node[1]
    #xe2 = ( 1 - e.var_inter[0] ) * X.test_on_node[0] + e.var_inter[0] * X.test_on_node[1]
    #x2  = ( 1 - e.var_inter[0] ) * X.expr_on_node[0] + e.var_inter[0] * X.expr_on_node[1]
    x  = (1-e.var_inter[0]-e.var_inter[1]) * X.expr_on_node[0] + \
           e.var_inter[0]                  * X.expr_on_node[1] + \
           e.var_inter[1]                  * X.expr_on_node[2]
    xe = (1-e.var_inter[0]-e.var_inter[1]) * X.test_on_node[0] + \
           e.var_inter[0]                  * X.test_on_node[1] + \
           e.var_inter[1]                  * X.test_on_node[2]
    sys.stderr.write( str( X.test_on_node[2] ) )
    return x * xe * dV

