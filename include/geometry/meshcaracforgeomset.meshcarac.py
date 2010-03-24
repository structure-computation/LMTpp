nb_dim = Parameter( type_par='unsigned', par_range=[1,2,3], default_value=3 )
nvi = Parameter( type_par='unsigned', par_range=[0,1,2,3], default_value=0 )
T = Parameter( type_par='class', par_range=[None], default_value='double' )

def get_carac(carac):
    """this function is called for each set of parameters and for each kind of element """
    carac.valid = nvi<=nb_dim
    carac.dim = nb_dim
    carac.Tpos = T
    carac.nodaldata = [
        #     /// 0           -> tangent 1 if surface, normal (from curvature center from point) if curve
        #     /// 1 (3d only) -> tangent 2 if surface, vect_prod(tangent,normal) if curve
        #     /// d-1         -> normal    if surface, tangent if curve
        DM( name='local_coords', dm_type='Vec<T,%s>'%(nvi+(nvi==0)), unit='m', default_value='0.0' ),
        DM( name='der_coords', dm_type='Vec<Vec<T,%s>,%s>'%(nb_dim,nb_dim), unit='m', default_value='0.0' ),
        DM( name='curvature', dm_type='Mat<T,Sym<%s> >'%(nvi+(nvi==0)), unit='1/m', default_value='%i,%i,0.0'%(nvi+(nvi==0),nvi+(nvi==0)) ),
    ]
    carac.nvi_to_subs_range = nb_dim
    
def get_elem_choice(nvi_to_subs,skin):
    if nvi-nvi_to_subs==0: return [ ('NodalElement','DefaultBehavior',[]) ]
    if nvi-nvi_to_subs==1: return [ ('Bar','DefaultBehavior',[]) ]
    if nvi-nvi_to_subs==2: return [ ('Triangle','DefaultBehavior',[]) ]
    if nvi-nvi_to_subs==3: return [ ('Tetra','DefaultBehavior',[]) ]
    return []

