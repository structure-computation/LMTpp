X = Variable( unknown=True, nb_der=2, default_value='1.0', unit='1' )

supplementary_order_for_time_integration = 3
left_time_integration = -sqrt(2)/2
right_time_integration = sqrt(2)/2
#left_time_integration = -0.61513
#right_time_integration = 0.648463

assume_symmetric_matrix = False
order_integration = 10

#
def formulation():
    x,xe = X.expr,X.test
    return ( x.diff(time).diff(time) + x ) * xe * dN # .subs(time,0) x.diff(time).diff(time)
