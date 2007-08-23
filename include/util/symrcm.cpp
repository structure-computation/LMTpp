//
// C++ Implementation: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "symrcm.h"
#include <list>

namespace LMT {

/**

 */
double symrcm_cost(const Vec<Vec<unsigned> > &indices,const Vec<unsigned> &perm) {
    Vec<unsigned> inv; inv.resize( perm.size() );
    for(unsigned i=0;i<inv.size();++i)
        inv[perm[i]] = i;
    
    double cost = 0;
    for(unsigned i=0;i<indices.size();++i) {
        unsigned mi = i;
        for(unsigned j=0;j<indices[perm[i]].size();++j)
            mi = min( mi, inv[indices[perm[i]][j]] );
        cost += pow( i - mi + 1 ,2 );
    }
    return cost;
}

struct SortSymRCM {
    SortSymRCM(const Vec<Vec<unsigned> > &indices_):indices(indices_) {}
    bool operator()(unsigned a,unsigned b) const { return indices[a].size() < indices[b].size(); }
    const Vec<Vec<unsigned> > &indices;
};

void symrcm(const Vec<Vec<unsigned> > &indices,double &best_score,Vec<unsigned> &resf,unsigned start_indice) {
    Vec<unsigned> res;
    Vec<unsigned> unvisited = cst_vec( 1, indices.size() );
    std::list<unsigned> vertices;
    vertices.push_back( start_indice );
    while ( vertices.size() ) {
        unsigned v = vertices.front();
        vertices.pop_front();
        unvisited[v] = false;
        res.push_back( v );
        
        Vec<unsigned> neighbours; // neighbours.reserve( indices[v].size() );
        for(unsigned i=0;i<indices[v].size();++i) {
            if ( unvisited[ indices[v][i] ] ) {
                neighbours.push_back( indices[v][i] );
                unvisited[ indices[v][i] ] = false;
            }
        }
        std::sort( neighbours.begin(), neighbours.end(), SortSymRCM(indices) );
        for(unsigned i=0;i<neighbours.size();++i)
            vertices.push_back( neighbours[i] );
    }

    double score = symrcm_cost( indices, res );
    if ( score < best_score ) {
        best_score = score;
        resf = res;
    }
}

Vec<unsigned> symrcm(const Vec<Vec<unsigned> > &indices_) {
    if ( indices_.size()==0 )
        return Vec<unsigned>();
    
    // construction of sym version without diag
    Vec<Vec<unsigned> > indices; indices.resize( indices_.size() );
    for(unsigned i=0;i<indices_.size();++i)
        indices[i].reserve( 2*indices_[i].size() );
    for(unsigned i=0;i<indices_.size();++i) {
        for(unsigned j=0;j<indices_[i].size();++j) {
            if ( indices_[i][j] < i ) {
                indices[ indices_[i][j] ].push_back( i );
                indices[ i ].push_back( indices_[i][j] );
            }
        }
    }

    // find a good start_indice
    unsigned start_indice = 0;
    for(unsigned i=1;i<indices.size();++i)
        if ( indices[i].size() < indices[start_indice].size() )
            start_indice = i;
    
    Vec<unsigned> res;
    double best_score = 1e300;
    //    for(unsigned start_indice=0;start_indice<indices.size();++start_indice)
    symrcm( indices, best_score, res, start_indice );
        
    //std::cout << "new cost -> " << best_score << std::endl;;
    //std::cout << "old cost -> " << symrcm_cost( indices, range(indices.size()) ) << std::endl;;
    return res;
}


}
