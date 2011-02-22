# -*- coding: utf-8 -*-

sigma_h_grad = Variable( interpolation='elementary_mul_nb_nodes', default_value='0', nb_dim=[dim], unit='1' )
sigma_n_phi = Variable( interpolation='elementary_mul_nb_nodes_of_each_children_elem', default_value='0', nb_dim=[dim], unit='1' )

sigma_chapeau = Variable( interpolation='P+3', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^3' )

execfile( './LMT/formulations/formulation_elasticity.py' )
#from LMT.formulations.formulation_elasticity.py import *
#def formulation():
    #return 0

def apply_on_elements_after_solve(unk_subs): # return a string
    #cw = Write_code('T')
    #print sigma_chapeau.expr[1]
    #sc = vec_col_to_mat_sym( sigma_chapeau.expr )
    #return cw.to_string()
    
    cw = Write_code('T')

    # sigma
    sigma = options['behavior_law']( formulation_instance )

    # sigma_h_grad
    for i in range(e.nb_nodes):
        phi = e.interpolation['nodal'].diff(e.val[i]) # fonction de forme numero i
        v = mul( sigma, e.grad(phi) )
        cw.add( e.integration( v, 2 ), 'toto[elem.node(%i)->number_in_original_mesh()]'%i, Write_code.Add )
        #cw.add( e.integration( v, 2 ), 'elem.sigma_h_e'grad[%i]'%i, Write_code.Set )

    # sigma_n_phi
    for child_info in e.children:
        child = Element( child_info['name'], dim )

        sigma_proj = e.get_proj_on_particular_child_element( sigma, child_info, child )
        cpt = 0
        for i in range(child.nb_nodes):
            cphi = child.interpolation['nodal'].diff(child.val[i]) # fonction de forme numero i de l'element child
            v = mul( sigma_proj, child.normal() ) * cphi
            cw.add( child.integration( v, 2 ), 'elem.sigma_n_phi[%i]'%i, Write_code.Set )
    #proute

    return cw.to_string()
