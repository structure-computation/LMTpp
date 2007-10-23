# Outils pour gerer les rotations
# P.Cresta 24/08/2005

import os
import math
import sys
from LMT.include.codegen import *

# Spin() : renvoie la matrice de spin (3*3,antisymetrique) d'un vecteur axial de rotation(3)

def Spin(vect):
    res = ExMatrix(3,3)
    if (vect.size()!=3):
        raise 'Spin() ne s''applique qu''aux vecteurs de dimension 3'
    else:
        res[0,1] = - vect[2]
        res[0,2] = vect[1]
        res[1,0] = vect[2]
        res[1,2] = - vect[0]
        res[2,0] = - vect[1]
        res[2,1] = vect[0]

    return res


# Axial() : renvoie le vecteur axial de rotation (3) d'une matrice de spin (3*3)
def Axial(Spinor):
    res = ExVector(3)

    if (Spinor.nb_rows() != 3 or Spinor.nb_cols() != 3):
        raise 'Axial() ne s''applique qu''aux matrices de dimension 3*3'

    else:
        res[0] = Spinor[2,1]
        res[1] = Spinor[0,2]
        res[2] = Spinor[1,0]
    
    return res


# Rot() : renvoie la matrice de rotation (3*3,symetrique) d'une matrice de spin(3*3)
def Rot(Spinor):
    res = ExMatrix(3,3)
    if (Spinor.nb_rows() != 3 or Spinor.nb_cols() != 3):
        raise 'Rot() ne s''applique qu''aux matrices de dimension 3*3'
    else:
        Id = ExMatrix(3,3)
        for i in range(3):
            for j in range(3):
                Id[i,j] = (i==j)
        theta = Spin_to_theta(Spinor)
        Spinor2 = mul(Spinor,Spinor)
        res = Id + Spinor * (sin(theta))/(theta+eqz(theta)) + Spinor2 * (1-cos(theta))/((theta+eqz(theta))**2)
    return res


# Skew() : renvoie la matrice de spin (3*3,antisymetrique) d'une matrice de rotation(3*3)
# Attention cet algo est numeriquement instable pour theta proche de 0 et 180, etc ...
# Et plante carrement pour theta = 180 ...

def Skew(Rotator):
    res = ExMatrix(3,3)

    if (Rotator.nb_rows() != 3 or Rotator.nb_cols() != 3):
        raise 'Skew() ne s''applique qu''aux matrices de dimension 3*3'
    else:
        theta = Rot_to_theta(Rotator)
        res = (Rotator-Rotator.transpose()) * theta / (2*sin(theta)+eqz(sin(theta)))
        
       # a faire : DL de la formule autour de Pi (pour sin == 0 et cos!=0)
       # if (sin(theta)==0):
       #     if (cos(theta)==0):
       #         return res
       #     else:
       #         raise 'Pas de chance, l''angle vaut Pi et je n''ai pas de formule associee'

       #else:
       #    res = theta * (Rotator-Rotator.transpose())/(2*sin(theta))
    return res


def Spin_to_theta(Spinor):
    
    if (Spinor.nb_rows() != 3 or Spinor.nb_cols() != 3):
        raise 'Spin_to_theta() ne s''applique qu''aux matrices de dimension 3*3'
    else:
        temp = Axial(Spinor)
        #temp[0]+=1E-300
        #temp[1]+=1E-300
        #temp[2]+=1E-300
        theta = norm(temp)#,1E-300)
    return theta


def Rot_to_theta(Rotator):
    if (Rotator.nb_rows() != 3 or Rotator.nb_cols() != 3):
        raise 'Spin_to_theta() ne s''applique qu''aux matrices de dimension 3*3'
    else:
        temp = 0.5 * (Rotator.trace() - 1)
        theta = acos(temp)#+1E-300)
    return theta


def Axial_to_theta(Vector):
    if (Vector.size()!=3):
        raise 'Axial_to_theta() ne s''applique qu''aux vecteurs de dimension 3'
    else:
        #Vector[0]+=1E-300
        #Vector[1]+=1E-300
        #Vector[2]+=1E-300
        theta = norm(Vector)#,1E-300)
    return  theta
    
    