""" quelques outils pour les fluides """
from include.codegen import *
import math

# #equations d'euler
# def mat_euler(U,gamma,dim,i):
#     
#     
#     
#     vecalpha=vector([alpha,alpha,alpha,0,0,0])
#     s1 = 1./E
#     s2 = - nu /E
#     s3 = (1.+ nu)/E
#     Sglo = matrix([
#             [s1,s2,s2,0.,0.,0.],
#             [s2,s1,s2,0.,0.,0.],
#             [s2,s2,s1,0.,0.,0.],
#             [0.,0.,0.,s3,0.,0.],
#             [0.,0.,0.,0.,s3,0.],
#             [0.,0.,0.,0.,0.,s3],
#             ])
#     Kglo = Sglo.inverse()
#     sigth = mul(Kglo,vecalpha)
#     if dim==3:
#         return Kglo,sigth
#     elif dim==2: # plane stress
#         if type_stress_2D=='plane stress':
#             S2d=matrix([
#                 [Sglo(0,0),Sglo(0,1),Sglo(0,3)],
#                 [Sglo(1,0),Sglo(1,1),Sglo(1,3)],
#                 [Sglo(3,0),Sglo(3,1),Sglo(3,3)],
#             ])
#             epsth2d=vector([vecalpha[0],vecalpha[1],vecalpha[3]])
#             K2d=S2d.inverse()
#             sigth2d=mul(K2d,epsth2d)
#             return K2d,sigth2d
#         elif type_stress_2D=='plane strain':
#             K2d=matrix([
#                 [Kglo(0,0),Kglo(0,1),Kglo(0,3)],
#                 [Kglo(1,0),Kglo(1,1),Kglo(1,3)],
#                 [Kglo(3,0),Kglo(3,1),Kglo(3,3)],
#             ])
# 
#             sigth2d=vector([sigth[0],sigth[1],sigth[3]])
#             return K2d,sigth2d
#         else:
#             raise 'Unknown type of stress in 2D : ' + str(type_stress_2D)
#     elif dim==1:
#         return matrix( [[E]] )

#
#
#
#
def heaviside_reg(a) :
    return (heavyside(a-0.005)+a/0.005*heavyside(a)*(1-heavyside(a-0.005)))
# fonction pour calculer les flux
def fct_fluxtest(gamma,dim,U):
    f=ExVector(0)
    m=ExMatrix(dim+2,dim)
    p=(gamma-1)*(U[dim+1]-0.5*(sum([U[i]*U[i] for i in range(1,dim+1)])))
    #p=Ex(2)
    for i in range(dim):
        f.push_back(U[1+i])
        for k in range(dim):
            f.push_back((gamma-1.)*U[dim+1]+(gamma-1.)/2.*(U[1+i]*U[1+k])+(i==k)*gamma*U[1+k]*U[1+k])
        f.push_back((U[dim+1]+p)*U[1+i])
    #m=matrix([
    #    [f[k*(dim+2)+i] for i in range(dim+2)] for k in range(dim)
    #])
    for h in range(dim+2):
        for j in range(dim):
           m[h,j]=f[h+(dim+2)*j]
    #truc
    return m
    #return m
#
#
#
def fct_flux(gamma,dim,U):
    f=ExVector(0)
    m=ExMatrix(dim+2,dim)
    p=(gamma-1)*(U[dim+1]-0.5*(sum([U[i]*U[i] for i in range(1,dim+1)]))/U[0])
    #p=Ex(2)
    for i in range(dim):
        f.push_back(U[1+i])
        for k in range(dim):
            f.push_back(p+U[1+i]*U[1+k]/U[0])
        f.push_back((U[dim+1]+p)*U[1+i]/U[0])
    #m=matrix([
    #    [f[k*(dim+2)+i] for i in range(dim+2)] for k in range(dim)
    #])
    for h in range(dim+2):
        for j in range(dim):
           m[h,j]=f[h+(dim+2)*j]
    #truc
    return m
#
#
#
#
#
def fct_flux2(gamma,dim,rho,U,p):
    m=ExMatrix(dim,dim)
    for h in range(dim):
        for j in range(dim):
           m[h,j]=p*(h==j)+U[h]*U[j]/rho
    return m
#
#
#

def sigF(p):
   s=vector([-p,-p,-p,0,0,0,0,0,0])
   return s





