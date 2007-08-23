can_directly_be_represented_by = 'Quad_8'

interval_var_inter = [
  [0,1],
  [0,1],
]

children = [
  {'name':'Bar_3', 'nodes':[0, 1, 4], 'var':[var_inter[0],number(0)]},
  {'name':'Bar_3', 'nodes':[1, 2, 5], 'var':[number(1),var_inter[0]]},
  {'name':'Bar_3', 'nodes':[2, 3, 6], 'var':[1-var_inter[0],number(1)]},
  {'name':'Bar_3', 'nodes':[3, 0, 7], 'var':[number(0),1-var_inter[0]]},
]

permutation = [ 0, 7, 3, 6, 2, 5, 1, 4 ]

#  3    6    2
#  x----x----x
#  |         |
# 7|         x5
#  |         |
#  x----x----x
#  0    4    1

X = 2 * var_inter[0] - 1
Y = 2 * var_inter[1] - 1
                     
interpolation["nodal"] =   1./4. *  (1-X) * (1-Y)* (-X - Y -1) * val[0] + \
                           1./4. *  (1+X) * (1-Y)* ( X - Y -1) * val[1] + \
                           1./4. *  (1+X) * (1+Y)* ( X + Y -1) * val[2] + \
                           1./4. *  (1-X) * (1+Y)* (-X + Y -1) * val[3] + \
                           1./2. * (1- X*X) * (1-Y) * val[4] + \
                           1./2. * (1- Y*Y) * (1+X) * val[5] + \
                           1./2. * (1- X*X) * (1+Y) * val[6] + \
                           1./2. * (1- Y*Y) * (1-X) * val[7] 
  
# ni = (1-var_inter[0]) * (1-var_inter[1]) * var_inter[0] * var_inter[1] * 16
# interpolation["bubble"] = (1-var_inter[0]) * (1-var_inter[1]) * (1-ni) * val[0] + \
#                             var_inter[0]   * (1-var_inter[1]) * (1-ni) * val[1] + \
#                             var_inter[0]   *   var_inter[1]   * (1-ni) * val[2] + \
#                           (1-var_inter[0]) *   var_inter[1]   * (1-ni) * val[3] + \
#                                                        ni              * val[4]

interpolation["der_nodal"] = val[0]

quality = 1
# ---------------------------------------------------------------------------------
def local_coordinates(point):
  v = positions[1]-positions[0]
  l = dot( point-positions[0], v ) / dot(v,v)
  return vector( [l] )
def pos_using_local_coordinates(coords):
  v = positions[1]-positions[0]
  return v * coords[0] + positions[0]
    
# ---------------------------------------------------------------------------------
# gauss_points[2] = [
#   ( 1.0/3.0, { var_inter[0] : (1.0+sqrt(2.0/3.0))/2.0, var_inter[1] : 0.0 } ),
#   ( 1.0/3.0, { var_inter[0] : (1.0-sqrt(1.0/6.0))/2.0, var_inter[1] : (1.0+sqrt(1.0/2.0))/2.0 } ),
#   ( 1.0/3.0, { var_inter[0] : (1.0-sqrt(1.0/6.0))/2.0, var_inter[1] : (1.0-sqrt(1.0/2.0))/2.0 } ),
# ]

gauss_points[3] = [
  ( 1.0/4.0, { var_inter[0] : (1.0+sqrt(1.0/3.0))/2.0, var_inter[1] : (1+sqrt(1.0/3.0))/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1.0-sqrt(1.0/3.0))/2.0, var_inter[1] : (1+sqrt(1.0/3.0))/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1.0+sqrt(1.0/3.0))/2.0, var_inter[1] : (1-sqrt(1.0/3.0))/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1.0-sqrt(1.0/3.0))/2.0, var_inter[1] : (1-sqrt(1.0/3.0))/2.0 } ),
]

r = sqrt(7.0/15.0); s = sqrt((7.0+sqrt(24.0))/15.0); t = sqrt((7-sqrt(24.0))/15.0)
gauss_points[5] = [
  ( 2.0/7.0,    { var_inter[0] : 1.0/2.0,     var_inter[1] : 1.0/2.0 } ),
  ( 25.0/168.0, { var_inter[0] : (1.0-r)/2.0, var_inter[1] : (1.0-r)/2.0 } ),
  ( 25.0/168.0, { var_inter[0] : (1.0+r)/2.0, var_inter[1] : (1.0+r)/2.0 } ),
  ( 5.0/48.0,   { var_inter[0] : (1.0+s)/2.0, var_inter[1] : (1.0-t)/2.0 } ),
  ( 5.0/48.0,   { var_inter[0] : (1.0-s)/2.0, var_inter[1] : (1.0+t)/2.0 } ),
  ( 5.0/48.0,   { var_inter[0] : (1.0+t)/2.0, var_inter[1] : (1.0-s)/2.0 } ),
  ( 5.0/48.0,   { var_inter[0] : (1.0-t)/2.0, var_inter[1] : (1.0+s)/2.0 } ),
]

# a = sqrt(3.0/5.0)
# gauss_points[5] = [
#   ( 8.0/18.0*8.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0  )/2.0 } ),
#   ( 5.0/18.0*8.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0  )/2.0 } ),
#   ( 5.0/18.0*8.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0  )/2.0 } ),
#   ( 8.0/18.0*5.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0-a)/2.0 } ),
#   ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0-a)/2.0 } ),
#   ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0-a)/2.0 } ),
#   ( 8.0/18.0*5.0/18.0, { var_inter[0] : (1.0  )/2.0, var_inter[1] : (1.0+a)/2.0 } ),
#   ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0-a)/2.0, var_inter[1] : (1.0+a)/2.0 } ),
#   ( 5.0/18.0*5.0/18.0, { var_inter[0] : (1.0+a)/2.0, var_inter[1] : (1.0+a)/2.0 } ),
# ]

