can_directly_be_represented_by = 'Hexa_20'

interval_var_inter = [
  [0,1],
  [0,1],
  [0,1],
]

#    7 ---14----6
#   /.         /|
# 15 .       13 |
# /  19      /  18
#4-----12---5   |
#|   .      |   |
#|   3...10.|.. 2
#16 .      17  /
#|11        | 9
#|.         |/
#0-----8----1

children = [
  {'name':"Quad_8", 'nodes':[0,3,2,1,11,10,9,8], 'var':[var_inter[1],var_inter[0],number(0)]},
  {'name':"Quad_8", 'nodes':[4,5,6,7,12,13,14,15], 'var':[var_inter[0],var_inter[1],number(1)]},
  {'name':"Quad_8", 'nodes':[0,1,5,4,8,17,12,16], 'var':[var_inter[0],number(0),var_inter[1]]},
  {'name':"Quad_8", 'nodes':[1,2,6,5,9,18,13,17], 'var':[number(1),var_inter[0],var_inter[1]]},
  {'name':"Quad_8", 'nodes':[3,7,6,2,19,14,18,10], 'var':[var_inter[1],number(1),var_inter[0]]},
  {'name':"Quad_8", 'nodes':[0,4,7,3,16,15,19,11], 'var':[number(0),var_inter[1],var_inter[0]]},
]

degree = 3

# permutation = [ 19,18,17,16,15,14,13,12,11,10,9,8,7, 6, 5, 4, 3, 2, 1, 0 ]
permutation = [ 0,3,2,1,4,7,6,5,11,10,9,8,15,14,13,12,16,19,18,17]

tmp_authorized_permutations = [
    [0,1,2,3, 4,5,6,7, 8,9,10,11,   12,13,14,15, 16,17,18,19],
    [4,7,6,5, 0,3,2,1, 15,14,13,12, 11,10,9,8,   16,19,18,17],
    [3,2,6,7, 0,1,5,4, 10,18,14,19, 8,17,12,16,  11,9,13,15],
    [0,4,5,1, 3,7,6,2, 16,12,17,8,  19,14,18,10, 11,15,13,9],
    [1,5,6,2, 0,4,7,3, 17,13,18,9,  16,15,19,11, 8,12,14,10],
    [0,3,7,4, 1,2,6,5, 11,19,15,16, 9,18,13,17,  8,10,14,12],
]

for i in range(4):
    authorized_permutations += tmp_authorized_permutations
    for c in range( len(tmp_authorized_permutations) ):
        tmp_authorized_permutations[c] = tmp_authorized_permutations[c][1:4] + [ tmp_authorized_permutations[c][0] ] + \
                                         tmp_authorized_permutations[c][5:8] + [ tmp_authorized_permutations[c][4] ] + \
                                         tmp_authorized_permutations[c][9:12] + [ tmp_authorized_permutations[c][8] ]+ \
                                         tmp_authorized_permutations[c][13:16] + [ tmp_authorized_permutations[c][12] ] + \
                                         tmp_authorized_permutations[c][17:20] + [ tmp_authorized_permutations[c][16] ]

authorized_permutations = authorized_permutations[1:]

X = 2*var_inter[0]-1
Y = 2*var_inter[1]-1
Z = 2*var_inter[2]-1

interpolation["nodal"] =  ( 1./8. *  (1-X) * (1-Y) * (1-Z) * (-X -Y -Z - 2) ) * val[0] + \
                          ( 1./8. *  (1+X) * (1-Y) * (1-Z) * ( X -Y -Z - 2) ) * val[1] + \
                          ( 1./8. *  (1+X) * (1+Y) * (1-Z) * ( X +Y -Z - 2) ) * val[2] + \
                          ( 1./8. *  (1-X) * (1+Y) * (1-Z) * (-X +Y -Z - 2) ) * val[3] + \
                          ( 1./8. *  (1-X) * (1-Y) * (1+Z) * (-X -Y +Z - 2) ) * val[4] + \
                          ( 1./8. *  (1+X) * (1-Y) * (1+Z) * ( X -Y +Z - 2) ) * val[5] + \
                          ( 1./8. *  (1+X) * (1+Y) * (1+Z) * ( X +Y +Z - 2) ) * val[6] + \
                          ( 1./8. *  (1-X) * (1+Y) * (1+Z) * (-X +Y +Z - 2) ) * val[7] + \
                          ( 1./4. * (1 - X*X) * (1-Y) * (1-Z) ) * val[8] + \
                          ( 1./4. * (1 - Y*Y) * (1+X) * (1-Z) ) * val[9] + \
                          ( 1./4. * (1 - X*X) * (1+Y) * (1-Z) ) * val[10] + \
                          ( 1./4. * (1 - Y*Y) * (1-X) * (1-Z) ) * val[11] + \
                          ( 1./4. * (1 - X*X) * (1-Y) * (1+Z) ) * val[12] + \
                          ( 1./4. * (1 - Y*Y) * (1+X) * (1+Z) ) * val[13] + \
                          ( 1./4. * (1 - X*X) * (1+Y) * (1+Z) ) * val[14] + \
                          ( 1./4. * (1 - Y*Y) * (1-X) * (1+Z) ) * val[15] + \
                          ( 1./4. * (1 - Z*Z) * (1-X) * (1-Y) ) * val[16] + \
                          ( 1./4. * (1 - Z*Z) * (1+X) * (1-Y) ) * val[17] + \
                          ( 1./4. * (1 - Z*Z) * (1+X) * (1+Y) ) * val[18] + \
                          ( 1./4. * (1 - Z*Z) * (1-X) * (1+Y) ) * val[19]

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
  ( 1.0, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0/2.0, var_inter[2] : 1.0/2.0 } )
]

#a,b = sqrt(2.0/3), sqrt(1.0/3)
#gauss_points[2] = [
  #( 1.0/4.0, { var_inter[0] : 1.0/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : (1-b)/2 } ),
  #( 1.0/4.0, { var_inter[0] : 1.0/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : (1-b)/2 } ),
  #( 1.0/4.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : 1.0/2.0, var_inter[2] : (1+b)/2 } ),
  #( 1.0/4.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : 1.0/2.0, var_inter[2] : (1+b)/2 } ),
#]

a=1./8.
b=sqrt(1.0/3.0)
gauss_points[2] = [
  ( a, { var_inter[0] : (1.0+b)/2.0, var_inter[1] : (1.0+b)/2.0, var_inter[2] : (1.0-b)/2.0 } ),
  ( a, { var_inter[0] : (1.0-b)/2.0, var_inter[1] : (1.0+b)/2.0, var_inter[2] : (1.0-b)/2.0 } ),
  ( a, { var_inter[0] : (1.0+b)/2.0, var_inter[1] : (1.0-b)/2.0, var_inter[2] : (1.0-b)/2.0 } ),
  ( a, { var_inter[0] : (1.0-b)/2.0, var_inter[1] : (1.0-b)/2.0, var_inter[2] : (1.0-b)/2.0 } ),
  ( a, { var_inter[0] : (1.0+b)/2.0, var_inter[1] : (1.0+b)/2.0, var_inter[2] : (1.0+b)/2.0 } ),
  ( a, { var_inter[0] : (1.0-b)/2.0, var_inter[1] : (1.0+b)/2.0, var_inter[2] : (1.0+b)/2.0 } ),
  ( a, { var_inter[0] : (1.0+b)/2.0, var_inter[1] : (1.0-b)/2.0, var_inter[2] : (1.0+b)/2.0 } ),
  ( a, { var_inter[0] : (1.0-b)/2.0, var_inter[1] : (1.0-b)/2.0, var_inter[2] : (1.0+b)/2.0 } ),
]

# a = sqrt(1.0/6.0); b = sqrt(1.0/2.0); c = sqrt(1.0/3.0); d = sqrt(2.0/3.0);
# gauss_points[3] = [
#   ( 1.0/6.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1-c)/2 } ),
#   ( 1.0/6.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1-c)/2 } ),
#   ( 1.0/6.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+b)/2.0, var_inter[2] : (1+c)/2 } ),
#   ( 1.0/6.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-b)/2.0, var_inter[2] : (1+c)/2 } ),
#   ( 1.0/6.0, { var_inter[0] : (1-d)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1-c)/2 } ),
#   ( 1.0/6.0, { var_inter[0] : (1+d)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1+c)/2 } ),
# ]

a = number("0.925820099772552"); b = number("0.330814963699288"); c = number("0.734112528752115");
p1 = number("0.295747599451303"); p2 = number("0.094101508916324");
p3 = number("0.412333862271436"); p4 = number("0.224703174765601");
gauss_points[7] = [
  ( p1/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : 1.0/2 } ),
  ( p1/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : 1.0/2 } ),
  ( p1/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1+a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p1/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1-a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p1/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : 1.0/2.0,   var_inter[2] : (1+a)/2 } ),
  ( p1/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : 1.0/2.0,   var_inter[2] : (1-a)/2 } ),

  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1+a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : (1-a)/2.0, var_inter[2] : 1.0/2 } ),
  ( p2/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1+a)/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1+a)/2.0, var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1-a)/2.0, var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : 1.0/2.0,   var_inter[1] : (1-a)/2.0, var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1+a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1+a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1-a)/2 } ),
  ( p2/8.0, { var_inter[0] : (1-a)/2.0, var_inter[1] : 1.0/2.0,   var_inter[2] : (1-a)/2 } ),

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
