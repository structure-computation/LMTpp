# -*- coding: utf-8 -*-
interval_var_inter = [
[0,1],
]


degree = 6

l0 = 1 - var_inter[0] 

# l'indéxation des noeuds est celle de METIL
interpolation["nodal"] = ( 6 * l0 ) * ( 6 * l0 - 1 ) * ( 6 * l0 - 2 ) * ( 6 * l0 - 3 ) * ( 6 * l0 - 4 ) * ( 6 * l0 - 5 )/ 720 * val[0] + ( 6 * l0 ) * ( 6 * l0 - 1 ) * ( 6 * l0 - 2 ) * ( 6 * l0 - 3 ) * ( 6 * l0 - 4 ) * ( 6 * var_inter[0] )/ 120 * val[1] + ( 6 * l0 ) * ( 6 * l0 - 1 ) * ( 6 * l0 - 2 ) * ( 6 * l0 - 3 ) * ( 6 * var_inter[0] ) * ( 6 * var_inter[0] - 1 )/ 48 * val[2] + ( 6 * l0 ) * ( 6 * l0 - 1 ) * ( 6 * l0 - 2 ) * ( 6 * var_inter[0] ) * ( 6 * var_inter[0] - 1 ) * ( 6 * var_inter[0] - 2 )/ 36 * val[3] + ( 6 * l0 ) * ( 6 * l0 - 1 ) * ( 6 * var_inter[0] ) * ( 6 * var_inter[0] - 1 ) * ( 6 * var_inter[0] - 2 ) * ( 6 * var_inter[0] - 3 )/ 48 * val[4] + ( 6 * l0 ) * ( 6 * var_inter[0] ) * ( 6 * var_inter[0] - 1 ) * ( 6 * var_inter[0] - 2 ) * ( 6 * var_inter[0] - 3 ) * ( 6 * var_inter[0] - 4 )/ 120 * val[5] + ( 6 * var_inter[0] ) * ( 6 * var_inter[0] - 1 ) * ( 6 * var_inter[0] - 2 ) * ( 6 * var_inter[0] - 3 ) * ( 6 * var_inter[0] - 4 ) * ( 6 * var_inter[0] - 5 )/ 720 * val[6]
