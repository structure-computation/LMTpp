# -*- coding: utf-8 -*-
import sys, re, string
from formal_lf import *
# gro toto
def print_gauss_point_for_order(e):
    print 'inline const double *gauss_point_for_order(unsigned order, const %s &elem) { /// order -> degre du polynome a integrer exactement' % e.name
    print '    static const unsigned offset[] = {',
    cpt = 0
    for order in range(10):
        print '%i,'%cpt ,
        try: k = min( filter(lambda x:x>=order,e.gauss_points.keys()) )
        except: k = e.gauss_points.keys()[-1]
        l = e.gauss_points[k]
        cpt += ( e.nb_var_inter + 1 ) * len(l) + 1
    print '}; // fonction de lordre du poly'
    print '    static const double values[] = {'
    for order in range(10):
        try: k = min( filter(lambda x:x>=order,e.gauss_points.keys()) )
        except: k = e.gauss_points.keys()[-1]
        for w,p in e.gauss_points[k]:
            print '        ' + string.join( map(lambda x:str(x),[w]+p.values()), ',' ) + ','
        print '        0.0,'
    
    print '    };'
    print '    return values + offset[order];'
    print '}'

def print_perm_if(e):
    print 'template<class TNode> void permutation_if_jac_neg(const %s &elem,TNode **nodes) {' % e.name
    print '    typedef typename TNode::T T;'
    el = Element( name_file, e.nb_var_inter )
    cw = Write_code('T')
    my_subs = {}
    for v in el.var_inter:
        my_subs[v] = number(0.5)
    for i in range(el.nb_nodes):
        for d in range(el.dim):
             my_subs[el.positions[i][d]] = symbol( 'nodes[%i]->pos[%i]' % (i,d) )
    cw.add( el.det_jacobian().subs(EM(my_subs)), 'det_jac', Write_code.Declare )
    print cw.to_string()
    print '    if ( det_jac < 0 ) {'
    print '        TNode *tmp[] = {'+string.join(['nodes[%i]'%p for p in el.permutation],',')+'};'
    print '        for(unsigned i=0;i<%i;++i) nodes[i] = tmp[i];' % e.nb_nodes
    print '    }'
    print '}'

def print_get_var_inter( e_, name_file, non_linear ):
    e = Element( name_file, e_.nb_var_inter )
    print 'template<class PosNodes,class Pvec,class TVI> void get_var_inter'+['_linear',''][non_linear]+'(const %s &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {' % e.name
    print 'typedef typename Pvec::template SubType<0>::T T;'
    
    my_subs = {}
    for i in range(e.nb_nodes):
        for d in range(e.dim):
             my_subs[e.positions[i][d]] = symbol( 'pos_nodes[%i][%i]' % (i,d) )
    
    #
    test_symbols = [ symbol('vt_%i'%i) for i in range(e.nb_var_inter) ]
    pos = vector([ symbol('pos[%i]'%i) for i in range(e.dim) ])
    expr = dot( pos - e.pos(), vector(test_symbols) )
    
    ma = calculate_matrix( expr, e.var_inter, test_symbols, my_subs, False, non_linear )
    dv = ma['M'].inverse() * ma['V']
    
    cw = Write_code('T')
    cw.add( dv, 'var_inter', [Write_code.Set,Write_code.Add][non_linear] )
    print cw.to_string()
    
    print '}'
    
    if non_linear:
        truly_non_linear = 0
        for vi in e.var_inter:
            truly_non_linear += ma['M'].depends_on( vi )
        print 'template<> struct ElemVarInterFromPosNonLinear<'+e.name+'> { static const bool res = '+str( truly_non_linear )+'; };'
    

def print_interpolations(e):
    for name_interpolation, interpolation in e.interpolation.items():
        n = string.capitalize(name_interpolation).replace('+','_plus_')
        print '#ifndef STRUCT_'+n
        print '#define STRUCT_'+n
        print 'struct '+n+' {};'
        print '#endif // STRUCT_'+n
        print 'template<class TVI,class TVAL,class T> void get_interp(const '+e.name+' &ne,const '+n+' &n,const TVI &var_inter,const TVAL &val,T &res) {'
        
        cw = Write_code('T')
        cw.add( interpolation, 'res', Write_code.Set )
        print cw.to_string()
        
        print '}'
        
def print_shape_functions( e ):
    print 'template<class TVI,class TVAL> void get_shape_functions(const '+e.name+' &ne,const TVI &var_inter,TVAL &res) {'
    print '    typedef typename TVAL::template SubType<0>::T T;'
    
    r = ExVector( e.nb_nodes )
    for i in range( e.nb_nodes ):
        s = {}
        for j in range( e.nb_nodes ):
            s[ e.val[j] ] = number( i==j )
        r[i] = e.interpolation['nodal'].subs(EM(s))
    
    cw = Write_code('T')
    cw.add( r, 'res', Write_code.Set )
    print cw.to_string()
    
    print '}'
    
    
def print_authorized_permutations(e):
    print '#ifndef AUTORIZEDPERM'
    print '#define AUTORIZEDPERM'
    print 'template<class T> struct AuthorizedPerm;'
    print '#endif // AUTORIZEDPERM'
    print 'template<> struct AuthorizedPerm<'+e.name+'> {'
    print '    static const unsigned nb_permutations = '+str(len(e.authorized_permutations))+';'
    for m in [ 'make', 'unmake' ]:
        print '    template<class TE> static void %s_permutation( TE &e, unsigned nb_perm ) {' % m
        for perm,cpt in zip( e.authorized_permutations, range(len(e.authorized_permutations)) ):
            print '        if ( nb_perm == '+str(cpt)+' ) {'
            if m == 'unmake':
                invperm = [ 0 ] * e.nb_nodes
                for p, cpt in zip( perm, range(len(perm)) ):
                    invperm[p] = cpt
                print '            typename TE::TNode *tmp[] = {'+string.join(['e.nodes[%i]'%p for p in invperm],',')+'};'
            else:
                print '            typename TE::TNode *tmp[] = {'+string.join(['e.nodes[%i]'%p for p in perm],',')+'};'
            print '            for(unsigned i=0;i<%i;++i) e.nodes[i] = tmp[i];' % e.nb_nodes
            print '            return;'
            print '        }'
        print '    }'
    
    print '};\n'
        
# ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
name_file = sys.argv[1]
e = Element( name_file, 3 )

nameHEADER = 'LMT_' + re.sub( '[/.]','_', name_file ).upper()
print '#ifndef '+nameHEADER
print '#define '+nameHEADER
print 'namespace LMT {'

print_gauss_point_for_order(e)
print_perm_if(e)
for non_linear in [False,True]:
    print_get_var_inter(e,name_file,non_linear)
    
print_interpolations(e)
print_shape_functions(e)
print_authorized_permutations(e)

print '}'
print '#endif // '+nameHEADER

