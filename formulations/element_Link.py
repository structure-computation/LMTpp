# -*- coding: utf-8 -*-
interval_var_inter = [
  [0,1],
]

children = []

permutation = [ 1, 0 ]

ni = (1-var_inter[0])*var_inter[0]*4;
interpolation['nodal'] = (1-var_inter[0])*val[0] + var_inter[0]*val[1]
interpolation['bubble'] = (1-var_inter[0])*(1-ni)*val[0]+var_inter[0]*(1-ni)*val[1] + ni*val[2];

quality = 1
degree = 2

# ---------------------------------------------------------------------------------
def local_coordinates(point):
  return vector([])
def pos_using_local_coordinates(coords):
  return positions[0]

# ---------------------------------------------------------------------------------
gauss_points[100] = [
  ( 1.0, { var_inter[0] : 0.0 } ),
]

can_directly_be_represented_by = "Bar"
