//
// C++ Interface: remove_ddl
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_REMOVE_DDL_HEADER
#define LMT_REMOVE_DDL_HEADER

#include "containers/mat.h"

namespace LMT {

/// remove indices_to_remove to matrice m and store m[indices_to_remove,indices_to_remove] in r
template<class T,class TS,class TI> void remove_ddl( Mat<T,TS,SparseLine<> > &m, Mat<T,TS,SparseLine<> > &r, const Vec<TI> &indices_to_remove ) {
    if ( indices_to_remove.size()==0 ) return;
    r.resize( m.nb_rows(), m.nb_cols() );

    // cum index
    Vec<int> cum_index; cum_index.resize( m.nb_cols() );
    for(unsigned i=0;i<indices_to_remove[0];++i)
        cum_index[i] = i;
    cum_index[ indices_to_remove[0] ] = -1;
    unsigned cpt = indices_to_remove[0];
    for(unsigned i=1;i<indices_to_remove.size();++i) {
        for(unsigned j=indices_to_remove[i-1]+1;j<indices_to_remove[i];++j,++cpt)
            cum_index[j] = cpt;
        cum_index[indices_to_remove[i]] = -1;
    }
    for(unsigned i=indices_to_remove.back()+1;i<cum_index.size();++i,++cpt)
        cum_index[i] = cpt;

    // remove columns
    unsigned cpt_row = 0;
    Vec<unsigned> old_indices;
    Vec<T> old_values;
    for(unsigned line=0;line<m.nb_rows();++line) {
        if ( cum_index[line]<0 ) {
            r.row( line ) = m.row( line );
        }
        else {
            old_indices = m.data[line].indices; // the indice vector we will modify
            old_values = m.data[line].data;
            Vec<unsigned> &new_indices = m.data[cpt_row].indices; // the indice vector we will modify
            Vec<T> &new_values = m.data[cpt_row].data;
            unsigned os = old_indices.size();
            
            new_indices.resize( 0 ); // assume that free() is not automatic (see resize() in vecfull.h)
            new_values.resize( 0 );
            for(unsigned i=0;i<os;++i) {
                if ( cum_index[old_indices[i]]<0 ) {
                    r.data[line].indices.push_back( old_indices[i] );
                    r.data[line].data.push_back( old_values[i] );
                }
                else {
                    new_indices.push_back( cum_index[old_indices[i]] );
                    new_values.push_back(  old_values[i] );
                }
            }
            ++cpt_row;
        }
    }

    m.resize( m.nb_rows()-indices_to_remove.size(), m.nb_cols()-indices_to_remove.size() );
    
}


}

#endif // LMT_REMOVE_DDL_HEADER
