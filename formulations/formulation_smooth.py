dep = Variable( unknown=True, nb_dim=[dim], default_value='0.0', unit='m' )

assume_non_linear = True
use_test_functions = False

def formulation():
    #
    P = [ pos.expr_on_node[i]+dep.expr_on_node[i] for i in range(e.nb_nodes) ]
    
    # distances egales
    longueurs = [ norm(P[j]-P[i]) for i,j in [(0,1),(1,2),(2,0)] ]
    moyenne_longueurs = sum(longueurs) / e.nb_nodes
    
    res = 0
    for i in [0,1,2]:
        r = ( longueurs[i] - moyenne_longueurs )**2
        res += r
        
    #
    #C = sum(P) / e.nb_nodes
    #R = sum([ norm(p-C) for p in P ]) / e.nb_nodes
    #res = 0.0
    #for p in P:
        #r = dot( C + (p-C)/norm(p-C)*R - p, C + (p-C)/norm(p-C)*R - p )
        #res += r + 1e6 * r ** 1.5
    
    return res * dV + (0.001+1e3*is_on_skin.expr*0)*dot(dep.expr,dep.expr) * dN
