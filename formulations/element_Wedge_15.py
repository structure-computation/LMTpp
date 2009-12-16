can_directly_be_represented_by = 'Wedge_15'

interval_var_inter = [
  [0,1],
  [0,1-var_inter[0]],
  [0,1],
]
#     5
#    /|\
#  11 | 10
#  /  14  \
# 3   9   4
# |   |   |
# |   2   |
#12  / \  13
# | 8   7 |
# |/     \|
# 0___6__ 1

children = [
  {'name':'Quad_8', 'nodes':[0, 1, 4, 3, 6, 13, 9, 12], 'var':[var_inter[0],number(0),var_inter[1]]},
  {'name':'Quad_8', 'nodes':[0, 2 ,5 ,3 ,8 ,14 ,11, 12], 'var':[number(0),var_inter[0],var_inter[1]]},
  {'name':'Quad_8', 'nodes':[1, 2, 5 ,4, 7, 14, 10, 13], 'var':[var_inter[0],1-var_inter[0],var_inter[1]]},
  {'name':'Triangle_6', 'nodes':[0, 1, 2, 6, 7, 8], 'var':[var_inter[0],var_inter[1],number(0)]},
  {'name':'Triangle_6', 'nodes':[3, 4, 5, 9, 10, 11], 'var':[var_inter[0],var_inter[1],number(1)]},
]

degree = 3

permutation = [ 14,13,12,11,10,9,8,7,6, 5, 4, 3, 2, 1, 0 ]

tmp_authorized_permutations = [
    [0,1,2, 3,4,5, 6,7,8, 9,10,11, 12,13,14],
    [3,5,4, 0,2,1, 11,10,9, 8,7,6, 12,14,13],
]
for i in range(3):
    authorized_permutations += tmp_authorized_permutations
    for c in range( len(tmp_authorized_permutations) ):
        tmp_authorized_permutations[c] = tmp_authorized_permutations[c][1:3] + [ tmp_authorized_permutations[c][0] ] + \
                                         tmp_authorized_permutations[c][4:6] + [ tmp_authorized_permutations[c][3] ] + \
                                         tmp_authorized_permutations[c][7:9] + [ tmp_authorized_permutations[c][6] ] + \
                                         tmp_authorized_permutations[c][10:12] + [ tmp_authorized_permutations[c][9] ] + \
                                         tmp_authorized_permutations[c][13:15] + [ tmp_authorized_permutations[c][12] ]
authorized_permutations = authorized_permutations[1:]

Z = 2*var_inter[2] - 1
X0 = 1- var_inter[0]-var_inter[1]
X1 = var_inter[0]
X2 = var_inter[1]

interpolation["nodal"] = ( 1./2. * X0 * (2*X0-1)*(1-Z) - 1./2. * X0 * (1-Z*Z) ) * val[0] + \
                         ( 1./2. * X1 * (2*X1-1)*(1-Z) - 1./2. * X1 * (1-Z*Z) ) * val[1] + \
                         ( 1./2. * X2 * (2*X2-1)*(1-Z) - 1./2. * X2 * (1-Z*Z) ) * val[2] + \
                         ( 1./2. * X0 * (2*X0-1)*(1+Z) - 1./2. * X0 * (1-Z*Z) ) * val[3] + \
                         ( 1./2. * X1 * (2*X1-1)*(1+Z) - 1./2. * X1 * (1-Z*Z) ) * val[4] + \
                         ( 1./2. * X2 * (2*X2-1)*(1+Z) - 1./2. * X2 * (1-Z*Z) ) * val[5] + \
                         ( 2 * X0 * X1 * (1-Z) ) * val[6] + \
                         ( 2 * X1 * X2 * (1-Z) ) * val[7] + \
                         ( 2 * X2 * X0 * (1-Z) ) * val[8] + \
                         ( 2 * X0 * X1 * (1+Z) ) * val[9] + \
                         ( 2 * X1 * X2 * (1+Z) ) * val[10] + \
                         ( 2 * X2 * X0 * (1+Z) ) * val[11] + \
                         ( X0 * (1-Z*Z) ) * val[12] + \
                         ( X1 * (1-Z*Z) ) * val[13] + \
                         ( X2 * (1-Z*Z) ) * val[14]

interpolation["der_nodal"] = val[0]

quality = 1

z1=(1+(1.0/sqrt(2.0)))/2;
z2=(1-(1.0/sqrt(2.0)))/2;
interpolation["gauss"] =  ( 2*var_inter[0] + 2*var_inter[1] - 1)   * (1-(var_inter[2]-z2)/(z1-z2))     * val[0]  + \
                          (-2*var_inter[0]                  + 1)   * (1-(var_inter[2]-z2)/(z1-z2))     * val[1]  + \
                          (-2*var_inter[1]                  + 1)   * (1-(var_inter[2]-z2)/(z1-z2))     * val[2]  + \
                          ( 2*var_inter[0] + 2*var_inter[1] - 1)   * (1-((1-var_inter[2])-z2)/(z1-z2)) * val[3]  + \
                          (-2*var_inter[0]                  + 1)   * (1-((1-var_inter[2])-z2)/(z1-z2)) * val[4]  + \
                          (-2*var_inter[1]                  + 1)   * (1-((1-var_inter[2])-z2)/(z1-z2)) * val[5]

a = 1.0/6.0 * 1.0/2.0
Flat_Interpolation_gauss_points = [
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 0.0     , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 0.0,     var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 0.0     , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 0.0,     var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
]
interpolation["Flat_Interpolation"] = ( 2*var_inter[0] + 2*var_inter[1] - 1)   * val[0]  + \
                          (-2*var_inter[0]                  + 1)   * val[1]  + \
                          (-2*var_inter[1]                  + 1)   * val[2]

def local_coordinates(point):
  v = positions[1]-positions[0]
  l = dot( point-positions[0], v ) / dot(v,v)
  return vector( [l] )
def pos_using_local_coordinates(coords):
  v = positions[1]-positions[0]
  return v * coords[0] + positions[0]

# ---------------------------------------------------------------------------------
gauss_points[1] = [
  ( 1.0/2.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : 1.0/2.0  } ),
]

a = 1.0/6.0 * 1.0/2.0
gauss_points[2] = [
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 0.0     , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 0.0,     var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 0.0     , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 0.0,     var_inter[1] : 1.0/2.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
]

a = -27.0/96.0 * 1.0/2.0
b = 25.0/96.0 * 1.0/2.0
gauss_points[3] = [
  ( a, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 1.0/5.0, var_inter[1] : 1.0/5.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 1.0/5.0, var_inter[1] : 3.0/5.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 3.0/5.0, var_inter[1] : 1.0/5.0 , var_inter[2] : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( a, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 1.0/5.0, var_inter[1] : 1.0/5.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 1.0/5.0, var_inter[1] : 3.0/5.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
  ( b, { var_inter[0] : 3.0/5.0, var_inter[1] : 1.0/5.0 , var_inter[2] : (1.0+sqrt(1.0/3.0))/2.0 } ),
]

a = number("0.445948490915965"); b = number("0.091576213509771")
c1 = number("0.111690794839005")*8.0/18.0
d1 = number("0.054975871827661")*8.0/18.0
c2 = number("0.111690794839005")*5.0/18.0
d2 = number("0.054975871827661")*5.0/18.0
gauss_points[4] = [
  ( c1, { var_inter[0] : a,         var_inter[1] : a         , var_inter[2] : 1.0/2.0 } ),
  ( c1, { var_inter[0] : 1.0-2.0*a, var_inter[1] : a         , var_inter[2] : 1.0/2.0 } ),
  ( c1, { var_inter[0] : a,         var_inter[1] : 1.0-2.0*a , var_inter[2] : 1.0/2.0 } ),
  ( d1, { var_inter[0] : b,         var_inter[1] : b         , var_inter[2] : 1.0/2.0 } ),
  ( d1, { var_inter[0] : 1.0-2.0*b, var_inter[1] : b         , var_inter[2] : 1.0/2.0 } ),
  ( d1, { var_inter[0] : b,         var_inter[1] : 1.0-2.0*b , var_inter[2] : 1.0/2.0 } ),
  ( c2, { var_inter[0] : a,         var_inter[1] : a         , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( c2, { var_inter[0] : 1.0-2.0*a, var_inter[1] : a         , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( c2, { var_inter[0] : a,         var_inter[1] : 1.0-2.0*a , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : b,         var_inter[1] : b         , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : 1.0-2.0*b, var_inter[1] : b         , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : b,         var_inter[1] : 1.0-2.0*b , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( c2, { var_inter[0] : a,         var_inter[1] : a         , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0 } ),
  ( c2, { var_inter[0] : 1.0-2.0*a, var_inter[1] : a         , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( c2, { var_inter[0] : a,         var_inter[1] : 1.0-2.0*a , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : b,         var_inter[1] : b         , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : 1.0-2.0*b, var_inter[1] : b         , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0 } ),
  ( d2, { var_inter[0] : b,         var_inter[1] : 1.0-2.0*b , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0 } ),
]

a = (6.0+sqrt(15.0))/21.0;     b = (4.0-7.0*a)/7.0
A = (155.0+sqrt(15.0))/2400.0; B = (31.0-240.0*A)/240.0
C = 9.0/80.0
gauss_points[5] = [
  ( C*8.0/18.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : 1.0/2.0 } ),
  ( A*8.0/18.0, { var_inter[0] : a      , var_inter[1] : a       , var_inter[2] : 1.0/2.0 } ),
  ( A*8.0/18.0, { var_inter[0] : 1-2*a  , var_inter[1] : a       , var_inter[2] : 1.0/2.0 } ),
  ( A*8.0/18.0, { var_inter[0] : a      , var_inter[1] : 1-2*a   , var_inter[2] : 1.0/2.0 } ),
  ( B*8.0/18.0, { var_inter[0] : b      , var_inter[1] : b       , var_inter[2] : 1.0/2.0 } ),
  ( B*8.0/18.0, { var_inter[0] : 1-2*b  , var_inter[1] : b       , var_inter[2] : 1.0/2.0 } ),
  ( B*8.0/18.0, { var_inter[0] : b      , var_inter[1] : 1-2*b   , var_inter[2] : 1.0/2.0 } ),
  ( C*5.0/18.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : a      , var_inter[1] : a       , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : 1-2*a  , var_inter[1] : a       , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : a      , var_inter[1] : 1-2*a   , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : b      , var_inter[1] : b       , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : 1-2*b  , var_inter[1] : b       , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : b      , var_inter[1] : 1-2*b   , var_inter[2] : (1.0-sqrt(3.0/5.0))/2.0} ),
  ( C*5.0/18.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : a      , var_inter[1] : a       , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : 1-2*a  , var_inter[1] : a       , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( A*5.0/18.0, { var_inter[0] : a      , var_inter[1] : 1-2*a   , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : b      , var_inter[1] : b       , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : 1-2*b  , var_inter[1] : b       , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
  ( B*5.0/18.0, { var_inter[0] : b      , var_inter[1] : 1-2*b   , var_inter[2] : (1.0+sqrt(3.0/5.0))/2.0} ),
]

has_make_structured = True
