from LMT.formal_lf import *

write_pb(
    name = 'pb_dep_cor',
    formulations = ['elasticity_dep'],
    elements = ['Triangle','Quad','Tetra','Hexa'],
    options = {
        'behavior_simplification' : 'plane stress',
    },
    name_der_vars = ["poisson_ratio"]
)


    