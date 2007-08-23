//
// C++ Interface: calculate_curvatures
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_calculate_curvatures_HEADER
#define LMT_calculate_curvatures_HEADER

#include "calculate_normals.h"

namespace LMT {

/**
    Estimation of curvature on nodes.
    Recquires following fields on nodes :
        normal
*/
template<class TM>
void calculate_curvatures(TM &m) {
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;

    m.update_node_neighbours();
    calculate_normals( m );

    //static Vec<double> vc;
        
    for(unsigned i=0;i<m.node_list.size();++i) {
        // get neighbours (two rings)
        Vec<Pvec> snn;
        Pvec P = m.node_list[i].pos;
        for(SimpleConstIterator<const typename TM::TNode *> nn1 = m.get_node_neighbours( i );nn1;++nn1) {
            snn.push_back( (*nn1)->pos );
            for(SimpleConstIterator<const typename TM::TNode *> nn2 = m.get_node_neighbours( m.node_list.number(**nn1) );nn2;++nn2) {
                Pvec np = (*nn2)->pos;
                if ( find( snn, ExactlyEqual(), np ) == false )
                    snn.push_back( np );
            }
        }
        // in local coordinates
        Pvec Z = m.node_list[i].normal / length(m.node_list[i].normal);
        Pvec X = find_orthonormal( Z );
        Pvec Y = vect_prod( Z, X );
        //PRINT( snn );
//         if ( snn.size()>=90 ) {
//             for(unsigned j=0;j<snn.size();++j)
//                 snn[j] = Pvec( dot(snn[j]-P,X), dot(snn[j]-P,Y), dot(snn[j]-P,Z) );
//             
//             Mat<T> M( snn.size(), 6 );
//             Vec<T> v; v.resize( snn.size() );
//             for(unsigned j=0;j<snn.size();++j) {
//                 M(j,0) = snn[j][0] * snn[j][0];
//                 M(j,1) = snn[j][1] * snn[j][1];
//                 M(j,2) = snn[j][2] * snn[j][2];
//                 M(j,3) = snn[j][0] * snn[j][1];
//                 M(j,4) = snn[j][0] * snn[j][2];
//                 M(j,5) = snn[j][1] * snn[j][2];
//                 v[j] = snn[j][2];
//             }
//             Mat<T> ms( trans(M) * M );
//             Vec<T> coeffs = inv( ms ) * (trans(M) * v);
// //             Pvec new_normal( Z - X*coeffs[6]- Y*coeffs[7] );
// //             new_normal /= length(new_normal);
// //             if ( dot(m.node_list[i].normal,new_normal)<0.0 )
// //                 m.node_list[i].normal = -new_normal;
// //             else
// //                 m.node_list[i].normal = new_normal;
// 
//             PRINT( coeffs );
//             m.node_list[i].K1 = coeffs[0]+coeffs[1] - sqrt( pow(coeffs[0]-coeffs[1],2) + pow(coeffs[3],2) );
//             m.node_list[i].K2 = coeffs[0]+coeffs[1] + sqrt( pow(coeffs[0]-coeffs[1],2) + pow(coeffs[3],2) );
//             vc.push_back(m.node_list[i].K1);
//         }
//                 else if ( snn.size()>=6 ) {
//                     Vec<Pvec> snn2; snn2.resize(snn.size());
//                     Vec<T> coeffs;
//                     unsigned nb_iter = 0;
//                     while( true ){
//                         for(unsigned j=0;j<snn.size();++j)
//                             snn2[j] = Pvec( dot(snn[j]-P,X), dot(snn[j]-P,Y), dot(snn[j]-P,Z) );
//                             
//                         Mat<T> M( snn2.size(), 5 );
//                         Vec<T> v; v.resize( snn2.size() );
//                         for(unsigned j=0;j<snn2.size();++j) {
//                             M(j,0) = snn2[j][0] * snn2[j][0];
//                             M(j,1) = snn2[j][0] * snn2[j][1];
//                             M(j,2) = snn2[j][1] * snn2[j][1];
//                             M(j,3) = snn2[j][0];
//                             M(j,4) = snn2[j][1];
//                             v[j] = snn2[j][2];
//                         }
//                         Mat<T> ms( trans(M) * M );
//                         coeffs = inv( ms ) * (trans(M) * v);
//                         Pvec new_normal( Z - X * coeffs[3] - Y * coeffs[4] );
//                         new_normal /= length(new_normal);
// //                         if ( abs(coeffs[3])+abs(coeffs[4]) < 1e-4 )
//                             break;
//                         ++nb_iter;
//                         m.node_list[i].normal = new_normal;
//                         Z = m.node_list[i].normal;
//                         X -= dot(X,Z)*Z;
//                         X /= length(X);
//                         Y = vect_prod( Z, X );
//                     }
//                     
//                     m.node_list[i].K1 = coeffs[0]+coeffs[2] + sqrt( pow(coeffs[0]-coeffs[2],2) + 0*pow(coeffs[1],2) );
//                     m.node_list[i].K2 = coeffs[0]+coeffs[2] - sqrt( pow(coeffs[0]-coeffs[2],2) + 0*pow(coeffs[1],2) );
//                     
//                     vc.push_back(m.node_list[i].K1);
//                 }
//         else {
        for(unsigned j=0;j<snn.size();++j)
            snn[j] = Pvec( dot(snn[j]-P,X), dot(snn[j]-P,Y), dot(snn[j]-P,Z) );
        Mat<T> M( snn.size(), 3 );
        Vec<T> v; v.resize( snn.size() );
        for(unsigned j=0;j<snn.size();++j) {
            M(j,0) = snn[j][0] * snn[j][0];
            M(j,1) = snn[j][0] * snn[j][1];
            M(j,2) = snn[j][1] * snn[j][1];
            v[j] = snn[j][2];
        }
        Mat<T> ms( trans(M) * M );
        Vec<T> coeffs = inv( ms ) * (trans(M) * v);
        T a = coeffs[0], b = coeffs[1], c = coeffs[2];
        //T t = ;
        if ( abs(coeffs[1])<1e-20 ) {
            m.node_list[i].curvature(0,0) = 2.0 * coeffs[0];
            m.node_list[i].curvature(1,1) = 2.0 * coeffs[2];
            m.node_list[i].X = X;
            m.node_list[i].Y = Y;
            m.node_list[i].Z = Z;
        }
        else {
            T a = coeffs[0];
            T b = coeffs[1];
            T c = coeffs[2];
            T t2 = a*a;
            T t5 = c*c;
            T t6 = b*b;
            T t8 = sqrt(t2-2.0*a*c+t5+t6);
            T t11 = 1/b*(a-c-t8);
            
            m.node_list[i].curvature(0,0) = ( a + c*t11*t11 - b*t11 ) / (1+t11*t11);
            m.node_list[i].curvature(1,1) = ( a*t11*t11 + c + b*t11 ) / (1+t11*t11);
            m.node_list[i].X = X-t11*Y;  m.node_list[i].X /= length(m.node_list[i].X);
            m.node_list[i].Y = t11*X+Y; m.node_list[i].Y /= length(m.node_list[i].Y);
            m.node_list[i].Z = Z;
        }
    }
}

};

#endif // LMT_calculate_curvatures_HEADER
