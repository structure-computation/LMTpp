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

permutation = [ 0, 7, 3, 6, 2, 5, 1, 4, 8 ]

#  3    6    2
#  x----x----x
#  |         |
# 7|    x8   x5
#  |         |
#  x----x----x
#  0    4    1

X = var_inter[0]
Y = var_inter[1]
                     
interpolation['nodal'] = \
    4 * (1-X) * ( 0.5 - X ) * (1-Y) * ( 0.5 - Y ) * val[0] + \
    4 *   X   * ( X - 0.5 ) * (1-Y) * ( 0.5 - Y ) * val[1] + \
    8 * (1-X) *      X      * (1-Y) * ( 0.5 - Y ) * val[4] + \
    4 * (1-X) * ( 0.5 - X ) *   Y   * ( Y - 0.5 ) * val[3] + \
    4 *   X   * ( X - 0.5 ) *   Y   * ( Y - 0.5 ) * val[2] + \
    8 * (1-X) *      X      *   Y   * ( Y - 0.5 ) * val[6] + \
    8 * (1-X) * ( 0.5 - X ) * (1-Y) *      Y      * val[7] + \
    8 *   X   * ( X - 0.5 ) * (1-Y) *      Y      * val[5] + \
    16* (1-X) *      X      * (1-Y) *      Y      * val[8]
  
#for u in [0,0.5,1]:
    #for v in [0,0.5,1]:
        #print interpolation['nodal'].subs(EM({var_inter[0]:number(u),var_inter[1]:number(v)}))
  
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

