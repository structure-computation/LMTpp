interval_var_inter = [
  [0,1],
  [0,1],
]

#
#  3 .. 7 .. 6 .. 2
#  .              .
#  0 .. 4 .. 5 .. 1
#

children = [
  {'name':'Bar_4', 'nodes':[0, 4, 5, 1], 'var':[var_inter[0],number(0)]},
  {'name':'Bar_4', 'nodes':[2, 6, 7, 3], 'var':[1-var_inter[0],number(1)]},
  {'name':'Bar', 'nodes':[1, 2], 'var':[number(1),var_inter[0]]},
  {'name':'Bar', 'nodes':[3, 0], 'var':[number(0),1-var_inter[0]]},
]

permutation = [ 3, 2, 1, 0, 7, 6, 5, 4 ]
degree = 4

n11  =                (1.0/3.0-var_inter[0]) * (2.0/3.0-var_inter[0]) * (1-var_inter[0]) * 4.5
n12  = var_inter[0]                          * (2.0/3.0-var_inter[0]) * (1-var_inter[0]) * 13.5
n13  = var_inter[0] * (1.0/3.0-var_inter[0])                          * (1-var_inter[0]) * (-13.5)
n14  = var_inter[0] * (1.0/3.0-var_inter[0]) * (2.0/3.0-var_inter[0])                    * 4.5

n21  = 1-var_inter[1]
n22  =   var_inter[1]

interpolation['nodal'] =  n11 * n21 * val[0] + \
                          n12 * n21 * val[4] + \
                          n13 * n21 * val[5] + \
                          n14 * n21 * val[1] + \
                          n11 * n22 * val[3] + \
                          n12 * n22 * val[7] + \
                          n13 * n22 * val[6] + \
                          n14 * n22 * val[2]


interpolation["der_nodal"] = val[0]

quality = 1
# ---------------------------------------------------------------------------------
# gauss_points[2] = [
#   ( 1.0/3.0, { var_inter[0] : (1.0+sqrt(2.0/3.0))/2.0, var_inter[1] : 0.0 } ),
#   ( 1.0/3.0, { var_inter[0] : (1.0-sqrt(1.0/6.0))/2.0, var_inter[1] : (1.0+sqrt(1.0/2.0))/2.0 } ),
#   ( 1.0/3.0, { var_inter[0] : (1.0-sqrt(1.0/6.0))/2.0, var_inter[1] : (1.0-sqrt(1.0/2.0))/2.0 } ),
# ]
# 
#gauss_points[3] = [
  #( 1.0/4.0, { var_inter[0] : (1.0+sqrt(1.0/3.0))/2.0, var_inter[1] : (1+sqrt(1.0/3.0))/2.0 } ),
  #( 1.0/4.0, { var_inter[0] : (1.0-sqrt(1.0/3.0))/2.0, var_inter[1] : (1+sqrt(1.0/3.0))/2.0 } ),
  #( 1.0/4.0, { var_inter[0] : (1.0+sqrt(1.0/3.0))/2.0, var_inter[1] : (1-sqrt(1.0/3.0))/2.0 } ),
  #( 1.0/4.0, { var_inter[0] : (1.0-sqrt(1.0/3.0))/2.0, var_inter[1] : (1-sqrt(1.0/3.0))/2.0 } ),
#]
a = sqrt(3.0/5.0)
gauss_points[5] = [
  ( 8.0/18.0*8.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0  )/2.0 } ),
  ( 5.0/18.0*8.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0  )/2.0 } ),
  ( 5.0/18.0*8.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0  )/2.0 } ),
  ( 8.0/18.0*5.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0-a)/2.0 } ),
  ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0-a)/2.0 } ),
  ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0-a)/2.0 } ),
  ( 8.0/18.0*5.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0+a)/2.0 } ),
  ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0+a)/2.0 } ),
  ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0+a)/2.0 } ),
]

# r = sqrt(7.0/15.0); s = sqrt((7.0+sqrt(24.0))/15.0); t = sqrt((7-sqrt(24.0))/15.0)
# gauss_points[5] = [
#   ( 2.0/7.0,    { var_inter[0] : 1.0/2.0,     var_inter[1] : 1.0/2.0 } ),
#   ( 25.0/168.0, { var_inter[0] : (1.0-r)/2.0, var_inter[1] : (1.0-r)/2.0 } ),
#   ( 25.0/168.0, { var_inter[0] : (1.0+r)/2.0, var_inter[1] : (1.0+r)/2.0 } ),
#   ( 5.0/48.0,   { var_inter[0] : (1.0+s)/2.0, var_inter[1] : (1.0-t)/2.0 } ),
#   ( 5.0/48.0,   { var_inter[0] : (1.0-s)/2.0, var_inter[1] : (1.0+t)/2.0 } ),
#   ( 5.0/48.0,   { var_inter[0] : (1.0+t)/2.0, var_inter[1] : (1.0-s)/2.0 } ),
#   ( 5.0/48.0,   { var_inter[0] : (1.0-t)/2.0, var_inter[1] : (1.0+s)/2.0 } ),
# ]
