import os
arch = os.uname()[4]
execfile( os.path.dirname(__file__) + os.sep + "codegen_"+arch+".py" )

def matrix(l):
    if ( len(l)==0 ):
        return ExMatrix( 0, 0 )
    
    res = ExMatrix( len(l), len(l[0]) )
    for i in range(len(l)):
        for j in range(len(l[0])):
            res[i,j] = l[i][j]
    return res

def vector(l):
    res = ExVector( len(l) )
    for i in range(len(l)):
        res[i] = l[i]
    return res

def mat_sym_to_vec_col(m):
    res = []
    if m.nb_rows()==1:
        res=[ m[0,0] ]
    elif m.nb_rows()==2:
        res=[ m[0,0], m[1,1], m[1,0] ]
    elif m.nb_rows()==3:
        res=[ m[0,0], m[1,1], m[2,2], m[0,1], m[0,2], m[1,2] ] # as abaqus
    else:
        assert 0
    #for d in range(m.nb_rows()):
        #for e in range(m.nb_rows()-d):
         #res.append( m[e,d+e] )
    #   for i in range(m.nb_rows()):
    #     res.append( m[i,i] )
    #   
    #   for i in range(m.nb_rows()):
    #     for j in range(i):
    #       res.append( m[i,j] )
    return vector(res)

def vec_col_to_mat_sym(v):
   res = []
   if v.size()==3:
      res=matrix([[v[0],v[2]],[v[2],v[1]]])
   elif v.size()==6:
      res=matrix([ [v[0],v[3],v[4]] , [v[3],v[1],v[5]] , [v[4],v[5],v[2]] ])
   return res
      
def mul(A,B):
  if isinstance(B,ExVector):
    res = []
    for i in range(A.nb_rows()):
      tmp = 0.0
      for j in range(A.nb_cols()):
        tmp += A[i,j] * B[j]
      res.append( tmp )
    return vector( res )
    
  assert A.nb_cols()==B.nb_rows()
  res = [ [ 0.0 for j in range(B.nb_cols()) ] for i in range(A.nb_rows()) ]
  for i in range(A.nb_rows()):
    for j in range(B.nb_cols()):
      for k in range(A.nb_cols()):
        res[i][j] += A[i,k] * B[k,j]
  return matrix( res )

def vectorial_product(v1,v2):
  if v1.size()==2: return vector([ v1[1]*v2, -v1[0]*v2 ])
  if v2.size()==2: return vector([ -v1*v2[1], v1*v2[0] ])
  # 3 D
  return vector([
    v1[1]*v2[2] - v1[2]*v2[1],
    v1[2]*v2[0] - v1[0]*v2[2],
    v1[0]*v2[1] - v1[1]*v2[0]
  ])

def trace_sym_col(sigma,epstest):
    res = 0
    dim = (sigma.size()+1)/2
    for i in range(dim): res += sigma[i] * epstest[i]
    for i in range(dim,epstest.size()): res += 2 * sigma[i] * epstest[i]
    return res

## procedure recursive pour 
#def multivariate_poly( coeffs, variables, cpt_variable = 0 ):
    #res = Ex(0)

    #degree,cpt = 0,0
    ##while cpt < len( coeffs ):
        
    
def get_taylor_expansion( expr, beg, var, deg_poly_max ):
    res = ExVector()
    r = 1.0
    for i in range( deg_poly_max + 1 ):
        res.push_back( r * expr.subs( var, beg ) )
        if i < deg_poly_max:
            expr = expr.diff( var )
            r /= i + 1
    return res



def minimize_iteration( expr, variables, old_values = ExVector() ):
    if type( variables ) != ExVector:
        return minimize_iteration( expr, vector( variables ), old_values )
    if not old_values.size():
        old_values = [ number( 0 ) ] * variables.size()
    #
    nb_unknowns = variables.size()
    M = ExMatrix( nb_unknowns, nb_unknowns )
    V = ExVector( nb_unknowns )
    #
    for i in range( nb_unknowns ):
        d = expr.diff( variables[i] )
        for j in range( nb_unknowns ):
            M[i,j] = d.diff( variables[j] )
        V[i] = -d
    #
    for i in range( nb_unknowns ):
        for j in range( nb_unknowns ):
            V[i] += M[i,j] * variables[j]
    #
    for n in range( nb_unknowns ):
        for i in range( nb_unknowns ):
            V[i] = V[i].subs( variables[n], old_values[n] )
            for j in range( nb_unknowns ):
                M[i,j] = M[i,j].subs( variables[n], old_values[n] )
    
    return solve_with_lu( lu( M ), V )
    #return M.inverse() * V

import types

def _flatten(L,a):
    for x in L:
        if type(x) in (types.ListType,types.TupleType): _flatten(x,a)
        else: a(x)

def flatten(L):
    '''recursively flatten the list or tuple L'''
    R = []
    _flatten(L,R.append)
    return R
    
def lu( mat ):
    fact = ExMatrix( mat.nb_rows(), mat.nb_cols() )
    for row in range( mat.nb_rows() ):
        # L
        for col in range( row ):
            tmp = mat[ row, col ]
            for i in range( col ):
                tmp -= fact[ i, col ] * fact[ row, i ]
            fact[ row, col ] = tmp / fact[ col, col ]
        # U
        for col in range( row + 1 ):
            tmp = mat[ col, row ]
            for i in range( col ):
                tmp -= fact[ i, row ] * fact[ col, i ]
            fact[ col, row ] = tmp
    return fact

def solve_with_lu( fact, b ):
    res = b
    # L
    for r in range( fact.nb_rows() ):
        for i in range( r ):
            res[r] -= fact[r,i] * res[i]
    # U
    for c in range( fact.nb_cols()-1, -1, -1 ):
        res[c] /= fact[c,c]
        for i in range( c ):
            res[i] -= fact[i,c] * res[c]
    return res

def chol( mat ):
    assert( mat.nb_rows() == mat.nb_cols() )
    s = mat.nb_cols()
    fact = ExMatrix( s, s )
    for row in range( s ):
        for col in range( row + 1 ):
            tmp = mat[ row, col ]
            for i in range( col ):
                tmp -= fact[ col, i ] * fact[ row, i ]
            if row == col:
                fact[ row, col ] = 1 / sqrt( tmp )
            else:
                fact[ row, col ] = tmp * fact[ col, col ]
    return fact

def solve_with_chol( fact, b ):
    s = fact.nb_rows()
    #
    res = ExVector( b.size() )
    for r in range( s ):
        v = b[r]
        for i in range( r ):
            v -= fact[r,i] * res[i]
        res[r] = v * fact[r,r]
    #
    tmp_vec = res
    for c in range( fact.nb_cols()-1, -1, -1 ):
        tmp = tmp_vec[c] * fact[c,c]
        for i in range( c ):
            tmp_vec[i] -= fact[c,i] * tmp
        res[c] = tmp
    return res

# inverse of m assuming m is definite positive
def chol_inv( m ):
    fact = chol( m )
    s = m.nb_rows()
    res = ExMatrix( s, 0 )
    for i in range( s ):
        v = ExVector( s )
        v[i] = 1
        res.add_col( solve_with_chol( fact, v ) )
    return res

def diag_mat_from_vec( V ):
    res = ExMatrix( V.size(), V.size() )
    for i in range( V.size() ):
        res[i,i] = V[i]
    return res









# partie positive affectee de l'endommagement d'un vecteur colonne
# C est la matrice symetrique definie positive de souplesse endommagee
# S est le vecteur contrainte
def pos_part_dmg_vec_col(C, S):
    H = sqr_root_mat_sym(C)
    S_dmg = mul(H, S)
    S_dmg_pos = pos_part_vec_col(S_dmg)
    S_dmg_pos = mul(chol_inv(H), S_dmg_pos)
    return S_dmg_pos

# partie positive d'un vecteur colonne (OK)
def pos_part_vec_col(V):
    V_pos = vec_col_to_mat_sym(V)
    V_pos = pos_part_mat_sym(V_pos)
    V_pos = mat_sym_to_vec_col(V_pos)
    return V_pos

# partie negative d'un vecteur colonne (OK)
def neg_part_vec_col(V):
    V_neg = vec_col_to_mat_sym(V)
    V_neg = neg_part_mat_sym(V_neg)
    V_neg = mat_sym_to_vec_col(V_neg)
    return V_neg


# partie positive d'une matrice symetrique (OK?)
def pos_part_mat_sym( M ):
    M_eigen_values = M.find_eigen_values_sym()
    M_eigen_vectors = M.find_eigen_vectors_sym(M_eigen_values)
    DM_pos = diag_mat_from_vec( pos_part( M_eigen_values ) )
    M_pos = mul( mul( M_eigen_vectors, DM_pos ), M_eigen_vectors.transpose() )
    return M_pos

# partie negative d'une matrice symetrique (OK?)
def neg_part_mat_sym(M):
    M_eigen_values = M.find_eigen_values_sym()
    M_eigen_vectors = M.find_eigen_vectors_sym(M_eigen_values)
    DM_neg = diag_mat_from_vec( neg_part( M_eigen_values ) )
    M_neg = mul( mul( M_eigen_vectors, DM_neg ), M_eigen_vectors.transpose() )
    return M_neg

# partie positive d'une matrice diagonale (OK)
def pos_part_mat_diag(M):
    dim = M.nb_rows()
    res = ExMatrix(dim, dim)
    for i in range(dim):
        res[i, i] = M(i, i) * heavyside(M(i, i))
    return res

# partie negative d'une matrice diagonale (OK)
def neg_part_mat_diag(M):
    dim = M.nb_rows()
    res = ExMatrix(dim, dim)
    for i in range(dim):
        res[i, i] = M(i, i) * (1. - heavyside(M(i, i)))
    return res

# racine carree d'une matrice symetrique definie positive (OK?)
def sqr_root_mat_sym(M):
    M_eigen_values = M.find_eigen_values_sym()
    M_eigen_vectors = M.find_eigen_vectors_sym(M_eigen_values)
    DM_neg = diag_mat_from_vec( sqrt( M_eigen_values ) )
    M_neg = mul( mul( M_eigen_vectors, DM_neg ), M_eigen_vectors.transpose() )
    return M_neg

# racine carree d'une matrice positive (OK)
def sqr_root_mat_diag(M):
    dim = M.nb_rows()
    res = ExMatrix(dim, dim)
    for i in range(dim):
        res[i, i] = sqrt(M(i, i))
    return res



