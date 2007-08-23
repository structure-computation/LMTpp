can_directly_be_represented_by = 'Wedge'

interval_var_inter = [
  [0,1],
  [0,1-var_inter[0]],
  [0,1],
]

#     5
#    /|\
#   / | \
#  /  |  \
# 3___|___4
# |   |   |
# |   2   |
# |  / \  |
# | /   \ |
# |/     \|
# 0______ 1

children = [
  {'name':'Quad', 'nodes':[0, 1, 4, 3], 'var':[var_inter[0],number(0),var_inter[1]]},
  {'name':'Quad', 'nodes':[0, 2, 5, 3], 'var':[number(0),var_inter[0],var_inter[1]]},
  {'name':'Quad', 'nodes':[1, 2, 5 ,4], 'var':[1-var_inter[0],var_inter[0],var_inter[1]]},
  {'name':'Triangle', 'nodes':[0, 1, 2], 'var':[var_inter[0],var_inter[1],number(0)]},
  {'name':'Triangle', 'nodes':[3, 4, 5], 'var':[var_inter[0],var_inter[1],number(1)]},
]

permutation = [ 0, 2, 1, 3, 5, 4 ]

interpolation["nodal"] = (1-var_inter[0]-var_inter[1]) * (1-var_inter[2])   * val[0] + \
                                   var_inter[0] * (1-var_inter[2])          * val[1] + \
                                   var_inter[1] * (1-var_inter[2])          * val[2] + \
                         (1-var_inter[0]-var_inter[1]) * (var_inter[2]) * val[3] + \
                                  (var_inter[0]) * (var_inter[2])       * val[4] + \
                                  (var_inter[1]) * (var_inter[2])       * val[5] 

interpolation["der_nodal"] = val[0]

quality = 1
                               
def local_coordinates(point):
  v = positions[1]-positions[0]
  l = dot( point-positions[0], v ) / dot(v,v)
  return vector( [l] )
def pos_using_local_coordinates(coords):
  v = positions[1]-positions[0]
  return v * coords[0] + positions[0]

# ---------------------------------------------------------------------------------
# gauss_points[1] = [
#   ( 1.0/2.0, { var_inter[0] : 1.0/3.0, var_inter[1] : 1.0/3.0 , var_inter[2] : 1.0/2.0  } ),
# ]

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






