//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_REMOVEDOUBLE_H
#define LMT_REMOVEDOUBLE_H

namespace LMT {

/// return true if some points have been removed. Felipe BORDEU WELDT and Hugo LECLERC
template<class Carac>
bool remove_doubles( Mesh<Carac> &m, typename Mesh<Carac>::Tpos geom_prec, bool look_on_skin_only = false ) {
    typedef Mesh<Carac> TM;
    typedef typename TM::TNode TNode;
    typedef typename TM::Pvec Pvec;

    unsigned nn = m.node_list.size();
    Vec<unsigned> cor = range( nn ), cor2;
    
    //    0 1 2 3 4 5
    // -> 0 1 2 0 4 0 if [0,3,5] are close enough
    if ( look_on_skin_only ) {
        m.update_skin();
        for(unsigned i=0;i<m.skin.node_list.size();++i) {
            Pvec pi( m.skin.node_list[i].pos );
            for(unsigned j=i+1;j<m.skin.node_list.size();++j)
                if ( length( pi - m.skin.node_list[j].pos ) <= geom_prec )
                    cor[ m.skin.node_list[j].number_in_original_mesh() ] = cor[ m.skin.node_list[i].number_in_original_mesh() ];
        }
    } else {
        for(unsigned i=0;i<nn;++i) {
            Pvec pi( m.node_list[i].pos );
            for(unsigned j=i+1;j<nn;++j)
                if ( length( pi - m.node_list[j].pos ) <= geom_prec )
                    cor[j] = cor[i];
        }
    }
    
    //    0 1 2 0 4 0
    // -> 0 1 2 0 3 0 (rm point number 3)
    unsigned new_nn = 0;
    for(unsigned i=0;i<nn;++i) {
        if ( cor[i] != i )
            cor[i] = cor[cor[i]];
        else {
            if ( i != new_nn )
                DM::copy( m.node_list[i], m.node_list[new_nn] );
            cor[i] = new_nn++;
        }
    }
    
    //
    if ( new_nn != nn ) {
        Vec<TNode *> ncor; ncor.resize( nn );
        for(unsigned i=0;i<nn;++i) ncor[i] = &m.node_list[ cor[i] ];
        
        m.change_node_ptr_in_elements(ncor.ptr());
        m.node_list.pop_back(nn-new_nn);
        m.signal_connectivity_change();
        return true;
    }
    return false;
    
//     unsigned nn = m.node_list.size(), old_nn = nn;
//     Vec<unsigned> cor; cor = range( nn );
// 
//     // correspondance round 1 : equal nodes point on an unique one (the first in the list)
//     for(unsigned i=0;i<nn;++i) {
//         Pvec pi( m.node_list[i].pos );
//         for(unsigned j=i+1;j<nn;++j)
//             if ( length( pi - m.node_list[j].pos ) <= geom_prec )
//                 cor[j] = cor[i];
//     }
//     // round 2 : 
//     for(unsigned i=0;i<nn;++i) {
//         if ( cor[i] != i ) {
//             while( nn && cor[nn-1]!=nn-1 ) --nn;
//             for(unsigned j=nn;j<old_nn;++j) if ( cor[j]==nn-1 ) cor[j]=i;
//             if ( i>=nn ) break;
//             cor[ nn-1 ] = i;
//             //std::cout << "Copy " << i << " " << nn-1 << std::endl;
//             DM::copy( m.node_list[nn-1], m.node_list[i] );
//         }
//     }
// 
//     unsigned new_size = max( cor )+1;
//     
//     Vec<TNode *> ncor; ncor.resize( old_nn );
//     for(unsigned i=0;i<old_nn;++i) ncor[i] = &m.node_list[ cor[i] ];
//     
//     if ( new_size!=old_nn ) {
//         m.change_node_ptr_in_elements(ncor.begin());
//         //PRINT( old_nn-new_size );
//         m.node_list.pop_back(old_nn-new_size);
//         m.signal_connectivity_change();
//         return true;
//     }
//     return false;
}

/// remove double nodes (and modify connectivity) for a given mesh and a given box 
template<class Carac,class T>
bool remove_doubles(Mesh<Carac> &m,Vec<T,2> &box, typename Mesh<Carac>::Tpos geom_prec) {
    typedef Mesh<Carac> TM;
    typedef typename TM::TNode TNode;
    typedef typename TM::Pvec Pvec;

    
    unsigned nn = m.node_list.size(), old_nn = nn;
    Vec<unsigned> cor; cor = range( nn );

    // correspondance round 1 : equal nodes point on an unique one (the first in the list)
    for(unsigned i=0;i<nn;++i) {
        Pvec pi( m.node_list[i].pos );
        if(bool_vec(pi <= (box[1]+geom_prec) and pi >= (box[0]-geom_prec)) )
          for(unsigned j=i+1;j<nn;++j)
               if ( (length( pi - m.node_list[j].pos ) <= geom_prec) )
                  cor[j] = cor[i];
    }
    // round 2 : 
    for(unsigned i=0;i<nn;++i) {
        if ( cor[i] != i ) {
            while( nn && cor[nn-1]!=nn-1 ) --nn;
            for(unsigned j=nn;j<old_nn;++j) if ( cor[j]==nn-1 ) cor[j]=i;
	    if ( i>=nn ) break;
            cor[ nn-1 ] = i;
            //std::cout << "Copy " << i << " " << nn-1 << std::endl;
            DM::copy( m.node_list[nn-1], m.node_list[i] );
        }
    }

    unsigned new_size = max( cor )+1;
    
    Vec<TNode *> ncor; ncor.resize( old_nn );
    for(unsigned i=0;i<old_nn;++i) ncor[i] = &m.node_list[ cor[i] ];
    
    //PRINT( cor );
    //PRINT( ncor );
    
    if ( new_size!=old_nn ) {
        m.change_node_ptr_in_elements(ncor.begin());
        //PRINT( old_nn-new_size );
        m.node_list.pop_back(old_nn-new_size);
        m.signal_connectivity_change();
        return true;
    }
    return false;
}


};

#endif // LMT_REMOVEDOUBLE_H
