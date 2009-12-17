can_directly_be_represented_by = 'Hexa'

interval_var_inter = [
  [0,1],
  [0,1],
  [0,1],
]


#     7 ---------6
#    /.         /|
#   / .        / |
#  /  .       /  |
# 4----------5   |
# |   .      |   |
# |   3......|.. 2
# |  .       |  /
# | .        | /
# |.         |/
# 0--------- 1

children = [
  {'name':"Quad", 'nodes':[0,3,2,1], 'var':[var_inter[1],var_inter[0],number(0)]},
  {'name':"Quad", 'nodes':[4,5,6,7], 'var':[var_inter[0],var_inter[1],number(1)]},
  {'name':"Quad", 'nodes':[0,1,5,4], 'var':[var_inter[0],number(0),var_inter[1]]},
  {'name':"Quad", 'nodes':[3,7,6,2], 'var':[var_inter[1],number(1),var_inter[0]]},
  {'name':"Quad", 'nodes':[0,4,7,3], 'var':[number(0),var_inter[1],var_inter[0]]},
  {'name':"Quad", 'nodes':[1,2,6,5], 'var':[number(1),var_inter[0],var_inter[1]]},
]

permutation = [ 0, 3, 2, 1, 4, 7, 6, 5 ]
degree = 2

tmp_authorized_permutations = [
    [0,1,2,3,4,5,6,7],
    [4,7,6,5,0,3,2,1],
    [3,2,6,7,0,1,5,4],
    [0,4,5,1,3,7,6,2],
    [1,5,6,2,0,4,7,3],
    [0,3,7,4,1,2,6,5],
]
for i in range(4):
    authorized_permutations += tmp_authorized_permutations
    for c in range( len(tmp_authorized_permutations) ):
        tmp_authorized_permutations[c] = tmp_authorized_permutations[c][1:4] + [ tmp_authorized_permutations[c][0] ] + \
                                         tmp_authorized_permutations[c][5:8] + [ tmp_authorized_permutations[c][4] ]
authorized_permutations = authorized_permutations[1:]

# X = 2*var_inter[0]-1
# Y = 2*var_inter[1]-1
# Z = 2*var_inter[2]-1
# interpolation["nodal"] = 1./8. * (1. - X) * (1. - Y) * (1. - Z) * val[0] + \
#                          1./8. * (1. + X) * (1. - Y) * (1. - Z) * val[1] + \
#                          1./8. * (1. + X) * (1. + Y) * (1. - Z) * val[2] + \
#                          1./8. * (1. - X) * (1. + Y) * (1. - Z) * val[3] + \
#                          1./8. * (1. - X) * (1. - Y) * (1. + Z) * val[4] + \
#                          1./8. * (1. + X) * (1. - Y) * (1. + Z) * val[5] + \
#                          1./8. * (1. + X) * (1. + Y) * (1. + Z) * val[6] + \
#                          1./8. * (1. - X) * (1. + Y) * (1. + Z) * val[7]


interpolation["nodal"] =  (1-var_inter[0]) * (1-var_inter[1]) * (1-var_inter[2]) * val[0] + \
                            var_inter[0]   * (1-var_inter[1]) * (1-var_inter[2]) * val[1] + \
                            var_inter[0]   *   var_inter[1]   * (1-var_inter[2]) * val[2] + \
                          (1-var_inter[0]) *   var_inter[1]   * (1-var_inter[2]) * val[3] + \
                          (1-var_inter[0]) * (1-var_inter[1]) *   var_inter[2]   * val[4] + \
                            var_inter[0]   * (1-var_inter[1]) *   var_inter[2]   * val[5] + \
                            var_inter[0]   *   var_inter[1]   *   var_inter[2]   * val[6] + \
                          (1-var_inter[0]) *   var_inter[1]   *   var_inter[2]   * val[7]

# ni = (1-var_inter[0])*var_inter[0]*(1-var_inter[1])*var_inter[1]*(1-var_inter[2])*var_inter[2] * 64
# interpolation["bubble"] = (1-var_inter[0]) * (1-var_inter[1]) * (1-var_inter[2]) * (1-ni) * val[0] + \
#                             var_inter[0]   * (1-var_inter[1]) * (1-var_inter[2]) * (1-ni) * val[1] + \
#                           (1-var_inter[0]) *   var_inter[1]   * (1-var_inter[2]) * (1-ni) * val[2] + \
#                             var_inter[0]   *   var_inter[1]   * (1-var_inter[2]) * (1-ni) * val[3] + \
#                           (1-var_inter[0]) * (1-var_inter[1]) *   var_inter[2]   * (1-ni) * val[4] + \
#                             var_inter[0]   * (1-var_inter[1]) *   var_inter[2]   * (1-ni) * val[5] + \
#                           (1-var_inter[0]) *   var_inter[1]   *   var_inter[2]   * (1-ni) * val[6] + \
#                             var_inter[0]   *   var_inter[1]   *   var_inter[2]   * (1-ni) * val[7] + \
#                                                     ni        *                         val[8]

quality = 1
interpolation["der_nodal"] = val[0]

z1=(1+(1.0/sqrt(3.0)))/2;
z2=(1-(1.0/sqrt(3.0)))/2;
interpolation["gauss"] = (1-(var_inter[0]-z2)/(z1-z2))     * (1-(var_inter[1]-z2)/(z1-z2))     * (1-(var_inter[2]-z2)/(z1-z2))    * val[0]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-(var_inter[1]-z2)/(z1-z2))     * (1-(var_inter[2]-z2)/(z1-z2))    * val[1]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-((1-var_inter[1])-z2)/(z1-z2)) * (1-(var_inter[2]-z2)/(z1-z2))    * val[2]  + \
                         (1-(var_inter[0]-z2)/(z1-z2))     * (1-((1-var_inter[1])-z2)/(z1-z2)) * (1-(var_inter[2]-z2)/(z1-z2))    * val[3]  + \
                         (1-(var_inter[0]-z2)/(z1-z2))     * (1-(var_inter[1]-z2)/(z1-z2))     * (1-((1-var_inter[2])-z2)/(z1-z2))* val[4]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-(var_inter[1]-z2)/(z1-z2))     * (1-((1-var_inter[2])-z2)/(z1-z2))* val[5]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-((1-var_inter[1])-z2)/(z1-z2)) * (1-((1-var_inter[2])-z2)/(z1-z2))* val[6]  + \
                         (1-(var_inter[0]-z2)/(z1-z2))     * (1-((1-var_inter[1])-z2)/(z1-z2)) * (1-((1-var_inter[2])-z2)/(z1-z2))* val[7]



a = 1.0/sqrt(3.0)
Flat_Interpolation_gauss_points = [
  ( 1.0/4.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-a)/2.0,   var_inter[2] : 1.0/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-a)/2.0,   var_inter[2] : 1.0/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+a)/2.0,   var_inter[2] : 1.0/2.0 } ),
  ( 1.0/4.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+a)/2.0,   var_inter[2] : 1.0/2.0 } ),
]
z1=(1+(1.0/sqrt(3.0)))/2;
z2=(1-(1.0/sqrt(3.0)))/2;
interpolation["Flat_Interpolation"] = (1-(var_inter[0]-z2)/(z1-z2))     * (1-(var_inter[1]-z2)/(z1-z2))      * val[0]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-(var_inter[1]-z2)/(z1-z2))       * val[1]  + \
                         (1-((1-var_inter[0])-z2)/(z1-z2)) * (1-((1-var_inter[1])-z2)/(z1-z2))   * val[2]  + \
                         (1-(var_inter[0]-z2)/(z1-z2))     * (1-((1-var_inter[1])-z2)/(z1-z2))   * val[3]  \

# ---------------------------------------------------------------------------------
def local_coordinates(point):
  v = positions[1]-positions[0]
  l = dot( point-positions[0], v ) / dot(v,v)
  return vector( [l] )
def pos_using_local_coordinates(coords):
  v = positions[1]-positions[0]
  return v * coords[0] + positions[0]

# ---------------------------------------------------------------------------------
gauss_points[1] = [
  ( 1.0, { var_inter[0] : 1.0/2, var_inter[1] : 1.0/2, var_inter[2] : 1.0/2 } ),
]

#a,b = sqrt(2.0/3), sqrt(1.0/3)
#gauss_points[2] = [
  #( 1.0/4.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1-b)/2 } ),
  #( 1.0/4.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1-b)/2 } ),
  #( 1.0/4.0, { var_inter[0] : (1+a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1+b)/2 } ),
  #( 1.0/4.0, { var_inter[0] : (1-a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1+b)/2 } ),
#]

a = 1.0/sqrt(3.0)
gauss_points[2] = [
  ( 1.0/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1-a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1-a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1-a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1-a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1+a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1+a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1+a)/2.0 } ),
  ( 1.0/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1+a)/2.0 } ),
]

a = number("0.925820099772552"); b = number("0.330814963699288"); c = number("0.734112528752115");
p1 = number("0.295747599451303"); p2 = number("0.094101508916324");
p3 = number("0.412333862271436"); p4 = number("0.224703174765601");
gauss_points[7] = [
  ( p1/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] :   1.0/2 } ),
  ( p1/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] :   1.0/2 } ),
  ( p1/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p1/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p1/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1+a)/2 } ),
  ( p1/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1-a)/2 } ),

  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] :   1.0/2 } ),
  ( p2/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] :   1.0/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] :   1.0/2.0, var_inter[2] : (1-a)/2 } ),

  ( p3/8.0, { var_inter[0] : (1+b)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1+b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1+b)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1-b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1+b)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1+b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1+b)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1-b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1-b)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1+b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1-b)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1-b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1-b)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1+b)/2 } ),
  ( p3/8.0, { var_inter[0] : (1-b)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1-b)/2 } ),

  ( p4/8.0, { var_inter[0] : (1+c)/2.0, var_inter[1] : (1+c)/2.0, var_inter[2] : (1+c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1+c)/2.0, var_inter[1] : (1+c)/2.0, var_inter[2] : (1-c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1+c)/2.0, var_inter[1] : (1-c)/2.0, var_inter[2] : (1+c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1+c)/2.0, var_inter[1] : (1-c)/2.0, var_inter[2] : (1-c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1-c)/2.0, var_inter[1] : (1+c)/2.0, var_inter[2] : (1+c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1-c)/2.0, var_inter[1] : (1+c)/2.0, var_inter[2] : (1-c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1-c)/2.0, var_inter[1] : (1-c)/2.0, var_inter[2] : (1+c)/2 } ),
  ( p4/8.0, { var_inter[0] : (1-c)/2.0, var_inter[1] : (1-c)/2.0, var_inter[2] : (1-c)/2 } ),
]

gauss_points[3] = gauss_points[7]
gauss_points[4] = gauss_points[7]
gauss_points[5] = gauss_points[7]
gauss_points[6] = gauss_points[7]

has_make_structured = True
