can_directly_be_represented_by = 'Triangle_6'

interval_var_inter = [
  [0,1],
  [0,1-var_inter[0]],
]

children = [
  {'name':'Bar_3', 'nodes':[0, 3, 1], 'var':[var_inter[0],number(0)]},
  {'name':'Bar_3', 'nodes':[1, 4, 2], 'var':[1-var_inter[0],var_inter[0]]},
  {'name':'Bar_3', 'nodes':[2, 5, 0], 'var':[number(0),1-var_inter[0]]},
]

permutation = [ 5,4,3,2,1,0 ]

#
#     2
#    | \
#    |  \
#    5   4
#    |    \
#    |     \
#    0__3___1
#

X0 = 1 - var_inter[0]-var_inter[1]
X1 = var_inter[0]
X2 = var_inter[1]

interpolation["nodal"] = (2*X0 - 1) * X0 * val[0] + \
                         (2*X1 - 1) * X1 * val[1] + \
                         (2*X2 - 1) * X2 * val[2] + \
                               4*X0 * X1 * val[3] + \
                               4*X1 * X2 * val[4] + \
                               4*X2 * X0 * val[5]

interpolation["nodal_3"] = (1-var_inter[0]-var_inter[1]) * val[0] + \
                           var_inter[0]                  * val[1] + \
                           var_inter[1]                  * val[2]
                         
# ni = (1-var_inter[0]-var_inter[1]) * var_inter[0] * var_inter[1] * 81
# interpolation["bubble"] = (1-var_inter[0]-var_inter[1]) * (1-ni) * val[0] + \
#                           var_inter[0]                  * (1-ni) * val[1] + \
#                           var_inter[1]                  * (1-ni) * val[2] + \
#                           ni                                     * val[3]

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
#   ( 1.0/2.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 } ),
# ]
# gauss_points[2] = [
#   ( 1.0/6.0, { var_inter[0] : 1.0/2.0, var_inter[1] : 0.0 } ),
#   ( 1.0/6.0, { var_inter[0] : 1.0/2.0, var_inter[1] : 1.0 } ),
#   ( 1.0/6.0, { var_inter[0] : 0.0,     var_inter[1] : 1.0/2.0 } ),
# ]
# gauss_points[3] = [
#   ( -27.0/96.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 } ),
#   (  25.0/96.0, { var_inter[0] : 1.0/5.0, var_inter[1] : 1.0/5.0 } ),
#   (  25.0/96.0, { var_inter[0] : 1.0/5.0, var_inter[1] : 3.0/5.0 } ),
#   (  25.0/96.0, { var_inter[0] : 3.0/5.0, var_inter[1] : 1.0/5.0 } ),
# ]
a = number("0.445948490915965"); b = number("0.091576213509771")
gauss_points[4] = [
  ( number("0.111690794839005"), { var_inter[0] : a,         var_inter[1] : a } ),
  ( number("0.111690794839005"), { var_inter[0] : 1.0-2.0*a, var_inter[1] : a } ),
  ( number("0.111690794839005"), { var_inter[0] : a,         var_inter[1] : 1.0-2.0*a } ),
  ( number("0.054975871827661"), { var_inter[0] : b,         var_inter[1] : b } ),
  ( number("0.054975871827661"), { var_inter[0] : 1.0-2.0*b, var_inter[1] : b } ),
  ( number("0.054975871827661"), { var_inter[0] : b,         var_inter[1] : 1.0-2.0*b } ),
]
a = (6.0+sqrt(15.0))/21.0;     b = (4.0-7.0*a)/7.0
A = (155.0+sqrt(15.0))/2400.0; B = (31.0-240.0*A)/240.0
gauss_points[5] = [
  ( 9.0/80.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 } ),
  ( A, { var_inter[0] : number(a),     var_inter[1] : number(a) } ),
  ( A, { var_inter[0] : 1-2*number(a), var_inter[1] : number(a) } ),
  ( A, { var_inter[0] : number(a),     var_inter[1] : 1-2*number(a) } ),
  ( B, { var_inter[0] : number(b),     var_inter[1] : number(b) } ),
  ( B, { var_inter[0] : 1-2*number(b), var_inter[1] : number(b) } ),
  ( B, { var_inter[0] : number(b),     var_inter[1] : 1-2*number(b) } ),
]
a = number("0.063089014491502"); b = number("0.249286745170910")
c = number("0.310352451033785"); d = number("0.053145049844816")
A = number("0.025422453185103"); B = number("0.058393137863189")
C = number("0.041425537809187")
gauss_points[6] = [
  ( A, { var_inter[0] : a,     var_inter[1] : a } ),
  ( A, { var_inter[0] : 1-2*a, var_inter[1] : a } ),
  ( A, { var_inter[0] : a,     var_inter[1] : 1-2*a } ),
  ( B, { var_inter[0] : b,     var_inter[1] : b } ),
  ( B, { var_inter[0] : 1-2*b, var_inter[1] : b } ),
  ( B, { var_inter[0] : b,     var_inter[1] : 1-2*b } ),

  ( C, { var_inter[0] : c,     var_inter[1] : d } ),
  ( C, { var_inter[0] : d,     var_inter[1] : c } ),
  ( C, { var_inter[0] : 1-c-d, var_inter[1] : c } ),
  ( C, { var_inter[0] : 1-c-d, var_inter[1] : d } ),
  ( C, { var_inter[0] : c,     var_inter[1] : 1-c-d } ),
  ( C, { var_inter[0] : d,     var_inter[1] : 1-c-d } ),
]

has_extrapolation = True
has_make_structured = True
