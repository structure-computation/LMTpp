interval_var_inter = [
  [0,1],
  [0,1-var_inter[0]],
  [0,1-var_inter[0]-var_inter[1]],
]

#
#       3
#      /|\
#     / |9\
#   7/  |  \8
#   /  /2\  \
#  / /6   5\ \
# 0/--- 4----\1

children = [
  {'name':'Triangle_6', 'nodes':[0, 2, 1, 6, 5, 4], 'var':[1-var_inter[0]-var_inter[1],var_inter[0],var_inter[1]]},
  {'name':'Triangle_6', 'nodes':[0, 1, 3, 4, 8, 7], 'var':[1-var_inter[0]-var_inter[1],var_inter[0],number(0)]},
  {'name':'Triangle_6', 'nodes':[0, 3, 2, 7, 9, 6], 'var':[number(0),var_inter[0],var_inter[1]]},
  {'name':'Triangle_6', 'nodes':[1, 2, 3, 5, 9, 8], 'var':[number(0),1-var_inter[0]-var_inter[1],var_inter[0]]},
]

permutation = [ 0, 1, 3, 2, 4, 8, 7, 6, 5, 9  ]

X0 = 1 - var_inter[0] - var_inter[1] - var_inter[2]
X1 = var_inter[0]
X2 = var_inter[1]
X3 = var_inter[2]

interpolation["nodal"] = X0*(2*X0-1) * val[0] + \
                         X1*(2*X1-1) * val[1] + \
                         X2*(2*X2-1) * val[2] + \
                         X3*(2*X3-1) * val[3] + \
                         4*X0*X1     * val[4] + \
                         4*X1*X2     * val[5] + \
                         4*X0*X2 * val[6] + \
                         4*X0*X3 * val[7] + \
                         4*X1*X3     * val[8] + \
                         4*X2*X3     * val[9]

# ni = (1-var_inter[0]-var_inter[1]-var_inter[2]) * var_inter[0] * var_inter[1] * var_inter[2] * 256
# interpolation["bubble"] = (1-var_inter[0]-var_inter[1]-var_inter[2]) * (1-ni) * val[0] + \
#                                           var_inter[0]               * (1-ni) * val[1] + \
#                                           var_inter[1]               * (1-ni) * val[2] + \
#                                           var_inter[2]               * (1-ni) * val[3] + \
#                                                ni                             * val[4]

interpolation["der_nodal"] = val[0]

a,b,c = 1.0/4.0, 1.0/6.0, 1.0/2.0;
interpolation["gauss"] = (var_inter[0]-b)*(var_inter[0]-c)/((a-b)*(a-c)) *  (var_inter[1]-b)*(var_inter[1]-c)/((a-b)*(a-c)) * (var_inter[2]-b)*(var_inter[2]-c)/((a-b)*(a-c)) * val[0] + \
                         (var_inter[0]-a)*(var_inter[0]-c)/((b-a)*(b-c)) *  (var_inter[1]-a)*(var_inter[1]-c)/((b-a)*(b-c)) * (var_inter[2]-a)*(var_inter[2]-c)/((b-a)*(b-c)) * val[1] + \
                         (var_inter[0]-a)*(var_inter[0]-b)/((c-a)*(c-b)) *  (var_inter[1]-a)*(var_inter[1]-c)/((b-a)*(b-c)) * (var_inter[2]-a)*(var_inter[2]-c)/((b-a)*(b-c)) * val[2] + \
                         (var_inter[0]-a)*(var_inter[0]-c)/((b-a)*(b-c)) *  (var_inter[1]-a)*(var_inter[1]-b)/((c-a)*(c-b)) * (var_inter[2]-a)*(var_inter[2]-c)/((b-a)*(b-c)) * val[3] + \
                         (var_inter[0]-a)*(var_inter[0]-c)/((b-a)*(b-c)) *  (var_inter[1]-a)*(var_inter[1]-c)/((b-a)*(b-c)) * (var_inter[2]-a)*(var_inter[2]-b)/((c-a)*(c-b)) * val[4]

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
#   ( 1.0/6, { var_inter[0] : 1.0/4, var_inter[1] : 1.0/4, var_inter[2] : 1.0/4 } ),
# ]
a,b,p = (5.0-sqrt(5.0))/20.0, (5.0+3.0*sqrt(5.0))/20.0, 1.0/24.0
gauss_points[2] = [
  ( p, { var_inter[0] : a, var_inter[1] : a, var_inter[2] : a } ),
  ( p, { var_inter[0] : b, var_inter[1] : a, var_inter[2] : a } ),
  ( p, { var_inter[0] : a, var_inter[1] : b, var_inter[2] : a } ),
  ( p, { var_inter[0] : a, var_inter[1] : a, var_inter[2] : b } ),
]
a,b,c = 1.0/4.0, 1.0/6.0, 1.0/2.0;
p1,p2 = -2.0/15.0, 3.0/40.0;
gauss_points[3] = [
  ( p1, { var_inter[0] : a, var_inter[1] : a, var_inter[2] : a } ),
  ( p2, { var_inter[0] : b, var_inter[1] : b, var_inter[2] : b } ),
  ( p2, { var_inter[0] : c, var_inter[1] : b, var_inter[2] : b } ),
  ( p2, { var_inter[0] : b, var_inter[1] : c, var_inter[2] : b } ),
  ( p2, { var_inter[0] : b, var_inter[1] : b, var_inter[2] : c } ),
]
a = 1.0/4.0; b1 = (7.0+sqrt(15.0))/34.0; b2 = (7.0-sqrt(15.0))/34.0;
c1 = (13.0-3.0*sqrt(15.0))/34.0; c2 = (13.0+3.0*sqrt(15.0))/34.0;
d = (5.0-sqrt(15.0))/20.0; e = (5.0+sqrt(15.0))/20.0;
p1 = 8.0/405.0; p2 = 5.0/567.0;
w1 = (2665.0-14.0*sqrt(15.0))/226800.0; w2 = (2665.0+14.0*sqrt(15.0))/226800.0;
gauss_points[5] = [
  ( p1, { var_inter[0] : a, var_inter[1] : a, var_inter[2] : a } ),

  ( w1, { var_inter[0] : b1, var_inter[1] : b1, var_inter[2] : b1 } ),
  ( w1, { var_inter[0] : c1, var_inter[1] : b1, var_inter[2] : b1 } ),
  ( w1, { var_inter[0] : b1, var_inter[1] : c1, var_inter[2] : b1 } ),
  ( w1, { var_inter[0] : b1, var_inter[1] : b1, var_inter[2] : c1 } ),

  ( w2, { var_inter[0] : b2, var_inter[1] : b2, var_inter[2] : b2 } ),
  ( w2, { var_inter[0] : c2, var_inter[1] : b2, var_inter[2] : b2 } ),
  ( w2, { var_inter[0] : b2, var_inter[1] : c2, var_inter[2] : b2 } ),
  ( w2, { var_inter[0] : b2, var_inter[1] : b2, var_inter[2] : c2 } ),

  ( p2, { var_inter[0] : d, var_inter[1] : d, var_inter[2] : e } ),
  ( p2, { var_inter[0] : d, var_inter[1] : e, var_inter[2] : d } ),
  ( p2, { var_inter[0] : e, var_inter[1] : d, var_inter[2] : d } ),

  ( p2, { var_inter[0] : e, var_inter[1] : e, var_inter[2] : d } ),
  ( p2, { var_inter[0] : e, var_inter[1] : d, var_inter[2] : e } ),
  ( p2, { var_inter[0] : d, var_inter[1] : e, var_inter[2] : e } ),
]

has_make_structured = True
