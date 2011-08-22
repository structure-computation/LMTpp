# -*- coding: utf-8 -*-
interval_var_inter = [
[0,1],
]


degree = 5

l0 = 1 - var_inter[0] 

# l'indéxation des noeuds est celle de METIL
interpolation["nodal"] = ( 5 * l0 ) * ( 5 * l0 - 1 ) * ( 5 * l0 - 2 ) * ( 5 * l0 - 3 ) * ( 5 * l0 - 4 )/ 120 * val[0] + ( 5 * l0 ) * ( 5 * l0 - 1 ) * ( 5 * l0 - 2 ) * ( 5 * l0 - 3 ) * ( 5 * var_inter[0] )/ 24 * val[1] + ( 5 * l0 ) * ( 5 * l0 - 1 ) * ( 5 * l0 - 2 ) * ( 5 * var_inter[0] ) * ( 5 * var_inter[0] - 1 )/ 12 * val[2] + ( 5 * l0 ) * ( 5 * l0 - 1 ) * ( 5 * var_inter[0] ) * ( 5 * var_inter[0] - 1 ) * ( 5 * var_inter[0] - 2 )/ 12 * val[3] + ( 5 * l0 ) * ( 5 * var_inter[0] ) * ( 5 * var_inter[0] - 1 ) * ( 5 * var_inter[0] - 2 ) * ( 5 * var_inter[0] - 3 )/ 24 * val[4] + ( 5 * var_inter[0] ) * ( 5 * var_inter[0] - 1 ) * ( 5 * var_inter[0] - 2 ) * ( 5 * var_inter[0] - 3 ) * ( 5 * var_inter[0] - 4 )/ 120 * val[5]
