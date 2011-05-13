# -*- coding: utf-8 -*-
interval_var_inter = [
[0,1],
]


degree = 8

l0 = 1 - var_inter[0] 

# l'indéxation des noeuds est celle de METIL
interpolation["nodal"] = ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * l0 - 3 ) * ( 8 * l0 - 4 ) * ( 8 * l0 - 5 ) * ( 8 * l0 - 6 ) * ( 8 * l0 - 7 )/ 40320 * val[0] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * l0 - 3 ) * ( 8 * l0 - 4 ) * ( 8 * l0 - 5 ) * ( 8 * l0 - 6 ) * ( 8 * var_inter[0] )/ 5040 * val[1] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * l0 - 3 ) * ( 8 * l0 - 4 ) * ( 8 * l0 - 5 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 )/ 1440 * val[2] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * l0 - 3 ) * ( 8 * l0 - 4 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 )/ 720 * val[3] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * l0 - 3 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 ) * ( 8 * var_inter[0] - 3 )/ 576 * val[4] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * l0 - 2 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 ) * ( 8 * var_inter[0] - 3 ) * ( 8 * var_inter[0] - 4 )/ 720 * val[5] + ( 8 * l0 ) * ( 8 * l0 - 1 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 ) * ( 8 * var_inter[0] - 3 ) * ( 8 * var_inter[0] - 4 ) * ( 8 * var_inter[0] - 5 )/ 1440 * val[6] + ( 8 * l0 ) * ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 ) * ( 8 * var_inter[0] - 3 ) * ( 8 * var_inter[0] - 4 ) * ( 8 * var_inter[0] - 5 ) * ( 8 * var_inter[0] - 6 )/ 5040 * val[7] + ( 8 * var_inter[0] ) * ( 8 * var_inter[0] - 1 ) * ( 8 * var_inter[0] - 2 ) * ( 8 * var_inter[0] - 3 ) * ( 8 * var_inter[0] - 4 ) * ( 8 * var_inter[0] - 5 ) * ( 8 * var_inter[0] - 6 ) * ( 8 * var_inter[0] - 7 )/ 40320 * val[8]
