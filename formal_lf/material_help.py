""" quelques outils pour faciliter le travail sur les formulations """
from include.codegen import *
import math

#simplification du comportement
def simplification_behaviour(Kglo,Hglo,epsth,dim,type_stress_2D='plane stress'):
   if dim==3:
      return Kglo,epsth
   elif dim==2:
      if type_stress_2D=='plane stress':
         K2d=matrix([
         [Hglo(0,0),Hglo(0,1),Hglo(0,3)],
         [Hglo(1,0),Hglo(1,1),Hglo(1,3)],
         [Hglo(3,0),Hglo(3,1),Hglo(3,3)],
         ]).inverse()
         epsth2d=vector([epsth[0],epsth[1],epsth[3]])
         return K2d,epsth2d
      elif type_stress_2D=='plane strain':
            K2d=matrix([
                [Kglo(0,0),Kglo(0,1),Kglo(0,3)],
                [Kglo(1,0),Kglo(1,1),Kglo(1,3)],
                [Kglo(3,0),Kglo(3,1),Kglo(3,3)],
            ])
            H2d=K2d.inverse()
            sigth=mul(Kglo,epsth)
            sigth2d=vector([sigth[0],sigth[1],sigth[3]])
            epsth2d=mul(K2d.inverse(),sigth2d)
            return K2d,epsth2d
   elif dim==1:
      return Kglo(0,0),epsth[0]

def reconstruction_quantites_3d(epsilon,Kglo,Hglo,epsth,deltaT,dim,type_stress_2D='plane stress'):
   if dim==3:
      sigma = mul(Kglo,(epsilon-epsth*deltaT))
      return epsilon,sigma
   elif dim==2:
      if type_stress_2D=='plane stress':
         K2d=matrix([
         [Hglo(0,0),Hglo(0,1),Hglo(0,3)],
         [Hglo(1,0),Hglo(1,1),Hglo(1,3)],
         [Hglo(3,0),Hglo(3,1),Hglo(3,3)],
         ]).inverse()
         epsth2d=vector([epsth[0],epsth[1],epsth[3]])
         sigma2d = mul(K2d,(epsilon-epsth2d*deltaT))
         sigma = vector([sigma2d[0],sigma2d[1],0.,sigma2d[2],0.,0.])
         epsilon = mul(Hglo,sigma)+epsth*deltaT
         return epsilon,sigma
      elif type_stress_2D=='plane strain':
            K2d=matrix([
                [Kglo(0,0),Kglo(0,1),Kglo(0,3)],
                [Kglo(1,0),Kglo(1,1),Kglo(1,3)],
                [Kglo(3,0),Kglo(3,1),Kglo(3,3)],
            ])
            H2d=K2d.inverse()
            sigth=mul(Kglo,epsth)
            sigth2d=vector([sigth[0],sigth[1],sigth[3]])
            epsth2d=mul(K2d.inverse(),sigth2d)
            epsilon = vector([epsilon[0],epsilon[1],0.,epsilon[2],0.,0.])
            sigma = mul(Kglo,(epsilon-epsth*deltaT))
            return epsilon,sigma
   elif dim==1:
      raise 'reconstruction 3D non faite pour dim 1D'

#simplification matrice de rotation
def simplification_projection(P,dim):
   if dim==3:
      return P
   elif dim==2:
      P2d=matrix([
         [P(0,0),P(0,1),P(0,3)],
         [P(1,0),P(1,1),P(1,3)],
         [P(3,0),P(3,1),P(3,3)],
         ])
      return P2d
   elif dim==1:
      return 1

#loi de hooke isotrope direct 3d
def hooke_direct_isotrope_3d(E,nu):
    l = E * nu / (1. + nu) / (1. - 2. * nu)
    m = E / (1. + nu)
    H = matrix([
            [l+m,  l ,  l , 0., 0., 0.],
            [ l , l+m,  l , 0., 0., 0.],
            [ l ,  l , l+m, 0., 0., 0.],
            [ 0.,  0.,  0., m , 0., 0.],
            [ 0.,  0.,  0., 0., m , 0.],
            [ 0.,  0.,  0., 0., 0., m ],
            ])
    return H

#loi de hooke isotrope 3d
def hooke_isotrope_th_3d(E,nu,alpha):
    """ isotrope """
    vecalpha=vector([alpha,alpha,alpha,0,0,0])
    s1 = 1./E
    s2 = - nu /E
    s3 = (1.+ nu)/E
    Hglo = matrix([
            [s1,s2,s2,0.,0.,0.],
            [s2,s1,s2,0.,0.,0.],
            [s2,s2,s1,0.,0.,0.],
            [0.,0.,0.,s3,0.,0.],
            [0.,0.,0.,0.,s3,0.],
            [0.,0.,0.,0.,0.,s3],
            ])
    Kglo = Hglo.inverse()
    epsth=vecalpha
    sigth = mul(Kglo,vecalpha)
    return Kglo, Hglo, epsth

#loi de hooke isotrope direct 3d
def hooke_isotrope_direct_3d(E,nu):
    l = E * nu / (1. + nu) / (1. - 2. * nu)
    m = 2. * E / (1. + nu)
    H = matrix([
            [l+m,  l ,  l , 0., 0., 0.],
            [ l , l+m,  l , 0., 0., 0.],
            [ l ,  l , l+m, 0., 0., 0.],
            [ 0.,  0.,  0., m , 0., 0.],
            [ 0.,  0.,  0., 0., m , 0.],
            [ 0.,  0.,  0., 0., 0., m ],
            ])
    return H

#
def hooke_isotrope_3d(E,nu):
    return hooke_isotrope_th_3d(E,nu,number(0))

#loi de hooke isotrope
def hooke_isotrope_th(E,nu,dim,alpha,type_stress_2D='plane stress'):
   Kglo, Hglo, epsth = hooke_isotrope_th_3d(E,nu,alpha)
   K, epsth = simplification_behaviour(Kglo,Hglo,epsth,dim,type_stress_2D)
   return K, epsth

#
def hooke_isotrope(E,nu,dim,type_stress_2D='plane stress'):
   return hooke_isotrope_th(E,nu,dim,number(0),type_stress_2D)

#loi de hooke orthotrope 3d
def hooke_orthotrope_th_3d(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3):
   P,Pinv=matrice_passage(v1,v2)
   Hloc = matrix([
   [1./E1, -nu12/E1, -nu13/E1, 0, 0, 0],
   [-nu12/E1, 1./E2, -nu23/E2, 0, 0, 0],
   [-nu13/E1, -nu23/E2, 1./E3, 0, 0, 0],
   [0, 0, 0, 1./(2.*G12), 0, 0],
   [0, 0, 0, 0, 1./(2.*G13), 0],
   [0, 0, 0, 0, 0, 1./(2.*G23)],
   ])
   Kloc = Hloc.inverse()
   Kglo=mul(Pinv,mul(Kloc,P))
   Hglo = mul(P,mul(Hloc,Pinv))
   vecalpha=vector([alpha1,alpha2,alpha3,0,0,0])
   epsth=mul(Pinv,vecalpha)
   return Kglo, Hglo, epsth, P

def hooke_orthotrope_th_3d_endo(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,d,dp,df):
   print 'toto'
   P,Pinv=matrice_passage(v1,v2)
   Hloc = matrix([
   [1./(E1*(1-df)), -nu12/(E1*(1-df)), -nu13/(E1*(1-df)), 0, 0, 0],
   [-nu12/(E1*(1-df)), 1./(E2*(1-dp)), -nu23/E2, 0, 0, 0],
   [-nu13/(E1*(1-df)), -nu23/E2, 1./(E3*(1-dp)), 0, 0, 0],
   [0, 0, 0, 1./(2.*G12*(1-d)), 0, 0],
   [0, 0, 0, 0, 1./(2.*G13*(1-d)), 0],
   [0, 0, 0, 0, 0, 1./(2.*G23)],
   ])
   Kloc = Hloc.inverse()
   Kglo=mul(Pinv,mul(Kloc,P))
   Hglo = mul(P,mul(Hloc,Pinv))
   vecalpha=vector([alpha1,alpha2,alpha3,0,0,0])
   epsth=mul(Pinv,vecalpha)
   return Kglo, Hglo, epsth, P

def hooke_orthotrope_th_3d_loc(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3):
   P,Pinv=matrice_passage(v1,v2)
   Hloc = matrix([
   [1./E1, -nu12/E1, -nu13/E1, 0, 0, 0],
   [-nu12/E1, 1./E2, -nu23/E2, 0, 0, 0],
   [-nu13/E1, -nu23/E2, 1./E3, 0, 0, 0],
   [0, 0, 0, 1./(2.*G12), 0, 0],
   [0, 0, 0, 0, 1./(2.*G13), 0],
   [0, 0, 0, 0, 0, 1./(2.*G23)],
   ])
   Kloc = Hloc.inverse()
   Kglo = mul(Pinv,mul(Kloc,P))
   Hglo = mul(P,mul(Hloc,Pinv))
   vecalpha=vector([alpha1,alpha2,alpha3,0,0,0])
   epsth=mul(Pinv,vecalpha)
   return Kglo, Hglo, epsth, P, Kloc, Hloc

def hooke_orthotrope_th_3d_endo_loc(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,d,dp,df):
   P,Pinv=matrice_passage(v1,v2)
   Hloc = matrix([
   [1./(E1*(1-df)), -nu12/(E1*(1-df)), -nu13/(E1*(1-df)), 0, 0, 0],
   [-nu12/(E1*(1-df)), 1./(E2*(1-dp)), -nu23/E2, 0, 0, 0],
   [-nu13/(E1*(1-df)), -nu23/E2, 1./(E3*(1-dp)), 0, 0, 0],
   [0, 0, 0, 1./(2.*G12*(1-d)), 0, 0],
   [0, 0, 0, 0, 1./(2.*G13*(1-d)), 0],
   [0, 0, 0, 0, 0, 1./(2.*G23)],
   ])
   Kloc = Hloc.inverse()
   Kglo = mul(Pinv,mul(Kloc,P))
   Hglo = mul(P,mul(Hloc,Pinv))
   vecalpha=vector([alpha1,alpha2,alpha3,0,0,0])
   epsth=mul(Pinv,vecalpha)
   return Kglo, Hglo, epsth, P, Kloc, Hloc

def hooke_orthotrope_th(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,dim,type_stress_2D='plane stress'):
   Kglo, Hglo, epsth, P = hooke_orthotrope_th_3d(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3)
   K, epsth = simplification_behaviour(Kglo,Hglo,epsth,dim,type_stress_2D)
   P = simplification_projection(P,dim)
   return K, epsth, P

def hooke_orthotrope(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,dim,type_stress_2D='plane stress'):
   return hooke_orthotrope_th(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,number(0),number(0),number(0),dim,type_stress_2D)

#loi de hooke orthotrope endommageable 3d
def hooke_orthotrope_endommageable_th_3d(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,d):
   P,Pinv=matrice_passage(v1,v2)
   Hloc = matrix([
   [1./E1, -nu12/E1, -nu13/E1, 0, 0, 0],
   [-nu12/E1, 1./( E2*(1.-d[1])*(1-eqz(1.-d[1])) + E2*1e-10*eqz(1-d[1]) ), -nu23/E2, 0, 0, 0],
   [-nu13/E1, -nu23/E2, 1./E3, 0, 0, 0],
   [0, 0, 0, 1./(2.*G12*(1.-d[0])*(1-eqz(1.-d[0])) + 2.*G12*1e-10*eqz(1-d[0])), 0, 0],
   [0, 0, 0, 0, 1./(2.*G13), 0],
   [0, 0, 0, 0, 0, 1./(2.*G23)],
   ])
   Kloc = Hloc.inverse()
   Kglo=mul(Pinv,mul(Kloc,P))
   Hglo = mul(P,mul(Hloc,Pinv))
   vecalpha=vector([alpha1,alpha2,alpha3,0,0,0])
   epsth=mul(Pinv,vecalpha)
   return Kglo, Hglo, epsth, P

#definition de la matrice de passage d'une base globale a une base locale : Tl= P*Tg
def matrice_passage(v1,v2):
   v1 /= norm( v1 )
   v2 /= norm( v2 )
   v3 = vect_prod(v1,v2)
   a1 = v1[0]
   a2 = v1[1]
   a3 = v1[2]
   b1 = v2[0]
   b2 = v2[1]
   b3 = v2[2]
   c1 = v3[0]
   c2 = v3[1]
   c3 = v3[2]
   P = matrix([
      [ a1*a1, a2*a2, a3*a3, 2*a1*a2,     2*a1*a3,     2*a2*a3	   ],
      [ b1*b1, b2*b2, b3*b3, 2*b1*b2,     2*b1*b3,     2*b2*b3	   ],
      [ c1*c1, c2*c2, c3*c3, 2*c1*c2,     2*c1*c3,     2*c2*c3	   ],
      [ b1*a1, b2*a2, b3*a3, b1*a2+b2*a1, b1*a3+b3*a1, b2*a3+b3*a2 ],
      [ c1*a1, c2*a2, c3*a3, c1*a2+c2*a1, a3*c1+c3*a1, c2*a3+c3*a2 ],
      [ c1*b1, c2*b2, c3*b3, c1*b2+c2*b1, c1*b3+c3*b1, c2*b3+c3*b2 ],
   ])
   Pinv = matrix([
      [ a1*a1, b1*b1, c1*c1, 2*a1*b1,     2*a1*c1,     2*b1*c1	   ],
      [ a2*a2, b2*b2, c2*c2, 2*a2*b2,     2*a2*c2,     2*b2*c2	   ],
      [ a3*a3, b3*b3, c3*c3, 2*a3*b3,     2*a3*c3,     2*b3*c3	   ],
      [ a2*a1, b2*b1, c2*c1, a2*b1+b2*a1, a2*c1+c2*a1, b2*c1+c2*b1 ],
      [ a3*a1, b3*b1, c3*c1, a3*b1+b3*a1, a3*c1+c3*a1, b3*c1+c3*b1 ],
      [ a3*a2, b3*b2, c3*c2, a3*b2+b3*a2, a3*c2+c3*a2, b3*c2+c3*b2 ],
   ])
   return P,Pinv

def hooke_matrix_shell(E,nu,h,dim,type_behaviour='membrane'):
    """ coques sans couplage tension/flexion """

    if dim==3:

        K = matrix([
        [ 1 , nu, 0        ],
        [ nu, 1 , 0        ],
        [ 0 , 0 , (1 - nu) ],
        ])
        K *= E / ( 1 - nu * nu)

        if type_behaviour=='membrane':
            K *= h
            return K

        elif type_behaviour=='flexion':
            K *= (h * h * h / 12)
            return K

        elif type_behaviour=='cisaillement transverse':
            Ki = 5./6. * h * E / ( 2 + 2 * nu )
            K = matrix([
            [Ki , 0 ],
            [0 , Ki ],
            ])
            return K
        else:
            raise 'Unknown type_behaviour in hook_matrix_shell : ' + str(type_behaviour)

    else:
        raise 'Shell behaviour only available in 3D'

def dev( sigma ):
    res = sigma
    tr = 0
    d = (sigma.size()+1)/2
    for i in range(d): tr += sigma[i]
    tr /= d
    for i in range(d): res[i] -= tr
    return res

# ne fonctionne qu'en 3D
def von_mises( sigma, e = 0 ):
    d = dev( sigma )
    return sqrt( 3.0/2.0 * trace_sym_col(d,d) + e )

# jac
def calc_jac_ext( coord, var_inter ):
    res = ExMatrix( 3, 3 )
    for j in range( 3 ):
        for i in range( 3 ):
            res[j,i] = coord[i].diff( var_inter[j] )
    return res

# grad( v )
def grad_ext( v, var_inter, inv_jac ):
    res = ExMatrix( v.size(), var_inter.size() )
    for k in range( v.size() ):
        for j in range( var_inter.size() ):
            for i in range( var_inter.size() ):
                res[k,j] += v[k].diff( var_inter[i] ) * inv_jac[j,i]
    return res

# grad_sym( v ) -> column
def grad_sym_ext( v, var_inter, inv_jac ):
    gr = grad_ext( v, var_inter, inv_jac )
    res = ExMatrix( v.size(), v.size() )
    for i in range( v.size() ):
        for j in range( v.size() ):
            res[ i, j ] = 0.5 * ( gr[ i, j ] + gr[ j, i ] )
    return mat_sym_to_vec_col( res )

# loi de comportement anisotrope 3d
def hooke_anisotrope_3d(C):
    H = matrix([
            [C(0, 0), C(0, 1), C(0, 2), C(0, 3), C(0, 4), C(0, 5)],
            [C(1, 0), C(1, 1), C(1, 2), C(1, 3), C(1, 4), C(1, 5)],
            [C(2, 0), C(2, 1), C(2, 2), C(2, 3), C(2, 4), C(2, 5)],
            [C(3, 0), C(3, 1), C(3, 2), C(3, 3), C(3, 4), C(3, 5)],
            [C(4, 0), C(4, 1), C(4, 2), C(4, 3), C(4, 4), C(4, 5)],
            [C(5, 0), C(5, 1), C(5, 2), C(5, 3), C(5, 4), C(5, 5)],
        ])
    #K = H.inverse()
    K = chol_inv(H)
    return K, H

# produit tensoriel pour notation en colonne (nicolas R)
def tens_col(v1,v2):
    dim = (v1.size()+1)/2
    res=ExMatrix(dim*(dim+1)/2,dim*(dim+1)/2)
    for i in range(dim*(dim+1)/2):
        for j in range(dim*(dim+1)/2):
                res[i,j]=v1[i]*v2[j]
    return res
