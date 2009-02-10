can_directly_be_represented_by = 'Bar_3'

interval_var_inter = [
  [0,1],
]

# 0 -- 2 -- 1
children = [
  {'name':'NodalElement', 'nodes':[0], 'var':[number(0)]},
  {'name':'NodalElement', 'nodes':[1], 'var':[number(1)]},
]

permutation = [ 1, 0, 2 ]

#ni = (1-var_inter[0])*var_inter[0]*4;
#interpolation['nodal'] = (1-var_inter[0])*(1-ni)*val[0] + ni*val[1] + var_inter[0]*(1-ni)*val[2]
X = var_inter[0]
interpolation['nodal'] =   2 * (1-X) * ( 0.5 - X ) * val[0] + \
                           2 *   X   * ( X - 0.5 ) * val[1] + \
                           4 * (1-X) *      X      * val[2]

interpolation['nodal_2'] = (1-X)*val[0] + X*val[1]

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
# gauss_points[1] = [
#   ( 1.0, { var_inter[0] : 1.0/2.0 } ),
# ]
gauss_points[3] = [
  ( 1.0/2.0, { var_inter[0] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( 1.0/2.0, { var_inter[0] : (1.0+sqrt(1.0/3.0))/2.0 } ),
]
gauss_points[5] = [
  ( 8.0/18.0, { var_inter[0] : 1.0/2.0 } ),
  ( 5.0/18.0, { var_inter[0] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( 5.0/18.0, { var_inter[0] : (1.0+sqrt(3.0/5.0))/2.0 } ),
]
# s = math.sqrt(6.0/5.0)*2.0
# d = 1.0/s/6.0
# gauss_points[7] = [
#   ( (1.0+d)/4.0, { var_inter[0] : (1.0+sqrt((3.0-s)/7.0))/2.0 } ),
#   ( (1.0+d)/4.0, { var_inter[0] : (1.0-sqrt((3.0-s)/7.0))/2.0 } ),
#   ( (1.0-d)/4.0, { var_inter[0] : (1.0+sqrt((3.0+s)/7.0))/2.0 } ),
#   ( (1.0-d)/4.0, { var_inter[0] : (1.0-sqrt((3.0+s)/7.0))/2.0 } ),
# ]
# gauss_points[9] = [
#   ( 128.0/225.0, { var_inter[0] : 1.0/2.0 } ),
#   ( number("0.476828670499366")/2.0, { var_inter[0] : (1.0+number("0.538469310105683"))/2.0 } ),
#   ( number("0.476828670499366")/2.0, { var_inter[0] : (1.0-number("0.538469310105683"))/2.0 } ),
#   ( number("0.236926885056189")/2.0, { var_inter[0] : (1.0+number("0.906179845938664"))/2.0 } ),
#   ( number("0.236926885056189")/2.0, { var_inter[0] : (1.0-number("0.906179845938664"))/2.0 } ),
# ]
#gauss_points[11] = [ 
  #( number("0.467913934572691")/2.0, { var_inter[0] : (1.0+number("0.238619186083197"))/2.0 } ),
  #( number("0.467913934572691")/2.0, { var_inter[0] : (1.0-number("0.238619186083197"))/2.0 } ),
  #( number("0.360761573048139")/2.0, { var_inter[0] : (1.0+number("0.661209386466265"))/2.0 } ),
  #( number("0.360761573048139")/2.0, { var_inter[0] : (1.0-number("0.661209386466265"))/2.0 } ),
  #( number("0.171324492379170")/2.0, { var_inter[0] : (1.0+number("0.932469514203152"))/2.0 } ),
  #( number("0.171324492379170")/2.0, { var_inter[0] : (1.0-number("0.932469514203152"))/2.0 } ),
#]

has_extrapolation = True
