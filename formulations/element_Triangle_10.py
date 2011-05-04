# -*- coding: utf-8 -*-
interval_var_inter = [
[0,1],
[0,1-var_inter[0]],
]


degree = 3

l0 = 1 - var_inter[0] - var_inter[1] 

# l'indéxation des noeuds est celle de METIL
interpolation["nodal"] = ( 3 * l0 ) * ( 3 * l0 - 1 ) * ( 3 * l0 - 2 )/ 6 * val[0] + ( 3 * l0 ) * ( 3 * l0 - 1 ) * ( 3 * var_inter[0] )/ 2 * val[1] + ( 3 * l0 ) * ( 3 * var_inter[0] ) * ( 3 * var_inter[0] - 1 )/ 2 * val[2] + ( 3 * var_inter[0] ) * ( 3 * var_inter[0] - 1 ) * ( 3 * var_inter[0] - 2 )/ 6 * val[3] + ( 3 * l0 ) * ( 3 * l0 - 1 ) * ( 3 * var_inter[1] )/ 2 * val[4] + ( 3 * l0 ) * ( 3 * var_inter[0] ) * ( 3 * var_inter[1] ) * val[5] + ( 3 * var_inter[0] ) * ( 3 * var_inter[0] - 1 ) * ( 3 * var_inter[1] )/ 2 * val[6] + ( 3 * l0 ) * ( 3 * var_inter[1] ) * ( 3 * var_inter[1] - 1 )/ 2 * val[7] + ( 3 * var_inter[0] ) * ( 3 * var_inter[1] ) * ( 3 * var_inter[1] - 1 )/ 2 * val[8] + ( 3 * var_inter[1] ) * ( 3 * var_inter[1] - 1 ) * ( 3 * var_inter[1] - 2 )/ 6 * val[9]
