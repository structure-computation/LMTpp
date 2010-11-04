# -*- coding: utf-8 -*-
X = Variable( unknown=True, default_value='1.0', unit='1', interpolation='elementary' )

#
def formulation():
    x,xe = X.expr,X.test
    return ( x**2 - 2 ) * xe * dV
    