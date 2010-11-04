# -*- coding: utf-8 -*-
X = Variable( unknown=True, nb_der=2, default_value='1.0', unit='1' )

#supplementary_order_for_time_integration = 3
left_time_integration = 0
right_time_integration = 1


#
def formulation():
    x,xe = X.expr,X.test

    return ( x.diff(time) + x ) * xe * dN
    #return dot(x+x.diff(time), xe) * dV
    #print Y.expr.subs( e.var_inter[0], 0 )
    #return dot( Y.expr+Y.expr.diff(time), Y.test ) * dN
    # return ( x.diff(time) + x ) * xe * dV

