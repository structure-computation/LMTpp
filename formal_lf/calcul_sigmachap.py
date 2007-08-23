""" calcul de sigmachap dans le cas de differentes formulations """
from LMT.include.codegen import *
from material_help import *
import math

#calcul de sigmachap dans le cas de l'endommagement
# d contient dans l'ordre : d12 puis d22 puis d23 si besoin
def endommagement(epsilonchap,d,E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,dim,deltaT,type_stress_2D='plane stress'):
  #cas de mode d'ouverture - sig22 > 0 - utilisation de d complet
  K1,H1,epsth1,P1 =  hooke_orthotrope_endommageable_th_3d(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,d)
  K1s,epsth1s = simplification_behaviour(K1,H1,epsth1,dim,type_stress_2D)
  
  #cas de mode de fermeture - sig22 < 0 - utilisation de d22=0
  dini= vector([d[0],0])
  K2,H2,epsth2,P2 = hooke_orthotrope_endommageable_th_3d(E1,E2,E3,nu12,nu13,nu23,G12,G13,G23,v1,v2,alpha1,alpha2,alpha3,dini) 
  K2s,epsth2s = simplification_behaviour(K2,H2,epsth2,dim,type_stress_2D)
  
  sigma_part_p = mul(K1s,(epsilonchap-epsth1s*deltaT) )
  sigma_part_m = mul(K2s,(epsilonchap-epsth2s*deltaT) )

  sigmachap = sigma_part_p * heavyside(sigma_part_p[1]) + sigma_part_m*(1-heavyside(sigma_part_p[1]))
  return sigmachap

