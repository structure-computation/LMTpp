dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )
dep_sens = Variable( nb_dim=[dim], default_value='0.0', unit='m' )

dep_0 = Variable( nb_dim=[dim], default_value='0.0', unit='m' )
dep_1 = Variable( nb_dim=[dim], default_value='0.0', unit='m' )

normal = Variable( nb_dim=[dim], default_value='0.0', unit='1' )


# --------------------------------------------------------------------------------------------------------------------------------
def formulation():
    return 0
