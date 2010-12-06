# -*- coding: utf-8 -*-
can_directly_be_represented_by = 'Quad'

interval_var_inter = [
  [0,1],
  [0,1],
]

# 3------2
# |      |
# |      |
# |      |
# 0------1

children = [
  {'name':'Bar', 'nodes':[0, 1], 'var':[var_inter[0],number(0)]},
  {'name':'Bar', 'nodes':[1, 2], 'var':[number(1),var_inter[0]]},
  {'name':'Bar', 'nodes':[2, 3], 'var':[1-var_inter[0],number(1)]},
  {'name':'Bar', 'nodes':[3, 0], 'var':[number(0),1-var_inter[0]]},
]

permutation = [0, 3, 2, 1 ]
degree = 2

interpolation["nodal"] =  (1-var_inter[0]) * (1-var_inter[1])   * val[0] + \
                            var_inter[0]   * (1-var_inter[1])   * val[1] + \
                            var_inter[0]   *   var_inter[1]     * val[2] + \
                          (1-var_inter[0]) *   var_inter[1]     * val[3]

ni = (1-var_inter[0]) * (1-var_inter[1]) * var_inter[0] * var_inter[1] * 16
interpolation["bubble"] = (1-var_inter[0]) * (1-var_inter[1]) * (1-ni) * val[0] + \
                            var_inter[0]   * (1-var_inter[1]) * (1-ni) * val[1] + \
                            var_inter[0]   *   var_inter[1]   * (1-ni) * val[2] + \
                          (1-var_inter[0]) *   var_inter[1]   * (1-ni) * val[3] + \
                                                       ni              * val[4]

interpolation["der_nodal"] = val[0]
interpolation["gauss"] = val[0] + val[1] + val[2] + val[3]

interpolation["gauss_2"] = interpolation["gauss"]

tmp_authorized_permutations = [
    [0,1,2,3],
]
for i in range(4):
    authorized_permutations += tmp_authorized_permutations
    for c in range( len(tmp_authorized_permutations) ):
        tmp_authorized_permutations[c] = tmp_authorized_permutations[c][1:4] + [ tmp_authorized_permutations[c][0] ]
authorized_permutations = authorized_permutations[1:]


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
