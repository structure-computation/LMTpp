# -*- coding: utf-8 -*-
interval_var_inter = [
[0,1],
[0,1-var_inter[0]],
]


degree = 4

l0 = 1 - var_inter[0] - var_inter[1] 

# l'indéxation des noeuds est celle de METIL
interpolation["nodal"] = ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * l0 - 2 ) * ( 4 * l0 - 3 )/ 24 * val[0] + ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * l0 - 2 ) * ( 4 * var_inter[0] )/ 6 * val[1] + ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 )/ 4 * val[2] + ( 4 * l0 ) * ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 ) * ( 4 * var_inter[0] - 2 )/ 6 * val[3] + ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 ) * ( 4 * var_inter[0] - 2 ) * ( 4 * var_inter[0] - 3 )/ 24 * val[4] + ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * l0 - 2 ) * ( 4 * var_inter[1] )/ 6 * val[5] + ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * var_inter[0] ) * ( 4 * var_inter[1] )/ 2 * val[6] + ( 4 * l0 ) * ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 ) * ( 4 * var_inter[1] )/ 2 * val[7] + ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 ) * ( 4 * var_inter[0] - 2 ) * ( 4 * var_inter[1] )/ 6 * val[8] + ( 4 * l0 ) * ( 4 * l0 - 1 ) * ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 )/ 4 * val[9] + ( 4 * l0 ) * ( 4 * var_inter[0] ) * ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 )/ 2 * val[10] + ( 4 * var_inter[0] ) * ( 4 * var_inter[0] - 1 ) * ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 )/ 4 * val[11] + ( 4 * l0 ) * ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 ) * ( 4 * var_inter[1] - 2 )/ 6 * val[12] + ( 4 * var_inter[0] ) * ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 ) * ( 4 * var_inter[1] - 2 )/ 6 * val[13] + ( 4 * var_inter[1] ) * ( 4 * var_inter[1] - 1 ) * ( 4 * var_inter[1] - 2 ) * ( 4 * var_inter[1] - 3 )/ 24 * val[14]
