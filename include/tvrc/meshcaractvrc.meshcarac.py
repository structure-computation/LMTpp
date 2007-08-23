# mesh with 
nb_dim = Parameter( type_par='unsigned', par_range=[1,2,3], default_value='3' )
T = Parameter( type_par='class', par_range=[None], default_value='double' )

def get_carac(carac):
    """this function is called for each set of parameters and for each kind of element """
    carac.dim = nb_dim
    carac.Tpos = T
    Pvec = 'Vec<T,%s>' % nb_dim
    PPvec = 'Vec<Vec<T,%s>,%s>' % (nb_dim,nb_dim)
    MatC = 'Mat<T,Sym<%s> >' % (nb_dim)
    Rvec = 'Vec<T,%s>' % (nb_dim-(nb_dim==2))
    carac.nodaldata = [
        DM( name='normal', dm_type=Pvec, unit='m', default_value='0.0' ),
        DM( name='local_coords', dm_type=Pvec, unit='m', default_value='0.0' ),
        DM( name='X', dm_type=Pvec, unit='1', default_value='0.0' ),
        DM( name='Y', dm_type=Pvec, unit='1', default_value='0.0' ),
        DM( name='Z', dm_type=Pvec, unit='1', default_value='0.0' ),
        DM( name='curvature', dm_type=MatC, unit='1/m', default_value='%i,%i,0.0'%(nb_dim,nb_dim) ),
        DM( name='has_local_coords', dm_type='unsigned', unit='1', default_value='0' ),
        DM( name='is_separation', dm_type='unsigned', unit='1', default_value='0' ),
        
        DM( name='amp_real', dm_type=Pvec, unit='m', default_value='0.0' ),
        DM( name='amp_imag', dm_type=Pvec, unit='m', default_value='0.0' ),
        DM( name='amp_norm', dm_type=Pvec, unit='m', default_value='0.0' ),
        DM( name='rot_real', dm_type=Rvec, unit='m', default_value='0.0' ),
        DM( name='rot_imag', dm_type=Rvec, unit='m', default_value='0.0' ),
        DM( name='rot_norm', dm_type=Rvec, unit='m', default_value='0.0' ),
    ]
    carac.nvi_to_subs_range = nb_dim
    
def get_elem_choice(nvi_to_subs,skin):
    ns = [ DM( name='num_structure', dm_type='unsigned', default_value='0' ) ]
    #     def loc(nvi): return [DM( name='local_'+t, dm_type='Vec<T,%s>'%nb_dim, default_value='0.0' ) for t in ['X','Y','Z'] ] + \
    #         [ DM( name='local_C', dm_type='Vec<T,%s>'%nvi, default_value='0.0' ) ]
    #     angle = [
    #         DM( name='local_curvature', dm_type='double', default_value='0.0' ),
    #         DM( name='N1', dm_type='Vec<T,%s>'%nb_dim, default_value='0.0' ),
    #         DM( name='N2', dm_type='Vec<T,%s>'%nb_dim, default_value='0.0' ),
    #     ] * (nvi_to_subs==1)

    return [ 
        ( 'NodalElement', 'DefaultBehavior', ns ),
        ( 'Bar', 'DefaultBehavior', ns ),
        ( 'Triangle', 'DefaultBehavior', ns ),
        ( 'Tetra', 'DefaultBehavior', ns ),
    ][0:nb_dim+1-nvi_to_subs] # (nvi_to_subs==0)
