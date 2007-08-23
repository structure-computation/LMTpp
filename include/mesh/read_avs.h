#ifndef READ_AVS_H
#define READ_AVS_H

#include "mesh/hexa.h"
#include "mesh/triangle_6.h"
#include "mesh/tetra.h"
#include "mesh/wedge.h"
#include <stdexcept>
#include <map>
using namespace std;

namespace LMT {
/// put avs castem mesh in mesh



struct Totito {
    //     template<class T>
    //     void operator()(unsigned num,const char *name,T &val) const {
    //     }
    template<class T,int s>
    void operator()(unsigned num,const char *name,Vec<T,s> &val) const {
        for(unsigned i=0;i<fname.size();++i)
            if ( name == fname[i] ) {
                val = data[number][i];
//                 debug << " cambiando info de los nodos numero " << number << " dato "<< name << " valor : " << val << endl ;
            }
    }
    template<class T>
    void operator()(unsigned num,const char *name,T &val) const {
        for(unsigned i=0;i<fname.size();++i)
            if (name==fname[i]) {
                val = data[number][i][0];
//                 debug << " cambiando info de los nodos numero " << number << " dato "<< name << " valor : " << val << endl ;
            }
    }

    template<class TE>
    void operator()(TE &e) {
        number = e.number;
        DM::apply_with_names( e, *this );
    }

    int number;
    Vec<string> fname;
    Vec<int> fsize;
    Vec<Vec<Vec<double> > > data;

};



template<class TM>
void read_avs(TM &mesh, std::istream &is) throw(std::runtime_error) {

    //TM mesh;
    typedef typename TM::Tpos T;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    static const int dim = TM::dim;
    map<int,TNode *> map_num_node;

    //is.tellg();
    // correspondance between number in file -> ref in mesh

    // obtaining nbnode, nbelem
    int nbnode;
    int nbelem;
    int nbnode_data;
    int nbelem_data;
    int nbglobal_data;
    {
        string str;
        getline(is,str);
        istringstream s(str);
        s >> nbnode >> nbelem >> nbnode_data >> nbelem_data >> nbglobal_data;
    }
    // reading nodes coordinates
    int nb=0;
    Vec<int> NodeNumber;
    NodeNumber.resize(nbnode);
    while(nb<nbnode) {
        string str;
        getline(is,str);
        istringstream s(str);
        int number;
        s >> number;
        //s=tokenize(str);

        Vec<double,dim> vec;
        for(unsigned di=0;di<(unsigned)dim;di++)
            s >> vec[di];

        // we add the node and we retain is ref
        map_num_node[number] = mesh.add_node(vec);

        nb=nb+1;
    }
    //PRINT( generate( mesh.node_list, ExtractDM<pos_DM>() ) );

    //reading elem

    nb=0;
    //int nbnodeelem;
    int nnode_elem;
    string type_elem;
    while(nb<nbelem) {
        string str;
        getline(is,str);
        istringstream s(str);
        int number,number2;
        s >> number; // numero de l'element

        s >> number2; // 1 ou 2

        s >> type_elem;//type dl'element

        if (type_elem=="line") {
            nnode_elem=2;
            Vec<TNode *> vn;
            vn.resize(nnode_elem);
            for(int i=0;i<nnode_elem;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            mesh.add_element(Bar(),DefaultBehavior(),&vn[0]);
        } else if (type_elem=="tri") {
            Vec<TNode *> vn;
            while ( true ) {
                unsigned number;
                s >> number;
                if ( !s )
                    break;
                vn.push_back( map_num_node[number] );
            }
            if ( vn.size()==3 ) {
                if ( dim==2 ) {
                    T o = ((*vn[1]).pos[0]-(*vn[0]).pos[0])*((*vn[2]).pos[1]-(*vn[0]).pos[1]) - ((*vn[1]).pos[1]-(*vn[0]).pos[1])*((*vn[2]).pos[0]-(*vn[0]).pos[0]);
                    if ( o < 0 )
                        swap( vn[0], vn[1] );
                }
                permutation_if_jac_neg(Triangle(),vn.ptr());
                mesh.add_element(Triangle(),DefaultBehavior(),&vn[0]);
            } else if ( vn.size()==6 ) {
                permutation_if_jac_neg(Triangle_6(),vn.ptr());
                mesh.add_element(Triangle_6(),DefaultBehavior(),&vn[0]);
            } else
                throw std::runtime_error("Unknown element...");

        } else if (type_elem=="quad") {
            nnode_elem=4;
            Vec<TNode *> vn;
            vn.resize(nnode_elem);
            for(int i=0;i<nnode_elem;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            permutation_if_jac_neg(Quad(),vn.ptr());
            mesh.add_element(Quad(),DefaultBehavior(),&vn[0]);
        } else if (type_elem=="tet") {
            nnode_elem=4;
            Vec<TNode *> vn;
            vn.resize(nnode_elem);
            for(int i=0;i<nnode_elem;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            permutation_if_jac_neg(Tetra(),vn.ptr());
            mesh.add_element(Tetra(),DefaultBehavior(),&vn[0]);
        } else if (type_elem=="cub8" or type_elem=="hex") {
            nnode_elem=8;
            Vec<TNode *> vn;
            vn.resize(nnode_elem);
            for(int i=0;i<nnode_elem;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            permutation_if_jac_neg(Hexa(),vn.ptr());
            mesh.add_element(Hexa(),DefaultBehavior(),&vn[0]);
        } else if (type_elem=="prism") {
            nnode_elem=6;
            Vec<TNode *> vn;
            vn.resize(nnode_elem);
            for(int i=0;i<nnode_elem;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            permutation_if_jac_neg(Wedge(),vn.ptr());
            mesh.add_element(Wedge(),DefaultBehavior(),&vn[0]);
        } else {
            cout << "Erreur - type d'element non lu" <<endl;
            assert(0);
        }
        nb+=1;
    }
    mesh.sub_mesh(Number<1>()).elem_list.change_hash_size( mesh, mesh.elem_list.size() /2 +1);
    mesh.sub_mesh(Number<2>()).elem_list.change_hash_size( mesh, mesh.elem_list.size() /2 +1);

/*


    {    //reading node fields
        string str;
        getline(is,str);
        istringstream s(str);

        nb=0;
        int nb_of_node_fields;
        s >> nb_of_node_fields;
//         debug << "nb_of_node_fields " << nb_of_node_fields << endl;
        Vec<int> nb_of_comp;
        nb_of_comp.resize(nb_of_node_fields);
        while(nb<nb_of_node_fields) {
            s >> nb_of_comp[nb];
            ++nb;
        }
//         debug << "nb of comp " << nb_of_comp << endl;
        nb=0;
        Vec<string> node_fields_names;
        Vec<string> node_fields_units;
        node_fields_names.resize(nb_of_node_fields);
        node_fields_units.resize(nb_of_node_fields);

        while(nb<nb_of_node_fields) {
            string str;
            getline(is,str);
            istringstream s(str);
            string buf;
            s >> buf;
            Vec<std::string> split = tokenize( str, ',' );
            node_fields_names[nb] = split[0];
            node_fields_units[nb] = split[1];
            ++nb;
        }
//         debug << "names " << node_fields_names << " " <<  node_fields_units << endl;

        nb=0;
        int number;

        Totito mmmm;
        mmmm.fname = node_fields_names;
        mmmm.data.resize(nbnode);
        for(unsigned i=0;i<nbnode;++i)
            mmmm.data[i].resize(nb_of_node_fields);
        for(unsigned i=0;i<nbnode;++i)
            for(unsigned ii=0;ii<nb_of_node_fields;++ii)
                mmmm.data[i][ii].resize(nb_of_comp[ii]);

        while(nb<nbnode) {
            string str;
            getline(is,str);
            istringstream s(str);
            s >> number;
            int nb2=0;
            Vec<double> val;
            while(nb2<nb_of_node_fields) {
                val.resize(nb_of_comp[nb2]);
                for(unsigned i=0;i<nb_of_comp[nb2];++i) {
                    s >> mmmm.data[nb][nb2][i];
                    //                debug << mmmm.data[nb][nb2][i] << " " ;
                }
                ++nb2;
            }
            ++nb;
        }

        for(unsigned i=0;i<nbnode;++i) {
            mmmm.number = i;
            DM::apply_with_names( mesh.node_list[i], mmmm);
        }
    }


    {//reading elem fields
        string str;
        getline(is,str);
        istringstream s(str);

        nb=0;
        int nb_of_elem_fields;
        s >> nb_of_elem_fields;
//         debug << "nb_of_elem_fields " << nb_of_elem_fields << endl;
        Vec<int> nb_of_comp;
        nb_of_comp.resize(nb_of_elem_fields);
        while(nb<nb_of_elem_fields) {
            s >> nb_of_comp[nb];
            ++nb;
        }
        //debug << "nb of comp " << nb_of_comp << endl;
        nb=0;
        Vec<string> elem_fields_names;
        Vec<string> elem_fields_units;
        elem_fields_names.resize(nb_of_elem_fields);
        elem_fields_units.resize(nb_of_elem_fields);

        while(nb<nb_of_elem_fields) {
            string str;
            getline(is,str);
            istringstream s(str);
            string buf;
            s >> buf;
            Vec<std::string> split = tokenize( str, ',' );
            elem_fields_names[nb] = split[0];
            elem_fields_units[nb] = split[1];
            ++nb;
        }
//         debug << "names " << elem_fields_names << " " <<  elem_fields_units << endl;

        nb=0;
        int number;

        Totito mmmm;
        mmmm.fname = elem_fields_names;
        mmmm.data.resize(nbelem);
        for(unsigned i=0;i<nbelem;++i)
            mmmm.data[i].resize(nb_of_elem_fields);
        for(unsigned i=0;i<nbelem;++i)
            for(unsigned ii=0;ii<nb_of_elem_fields;++ii)
                mmmm.data[i][ii].resize(nb_of_comp[ii]);

        while(nb<nbelem) {
            string str;
            getline(is,str);
            istringstream s(str);
            s >> number;
            int nb2=0;
            Vec<double> val;
            while(nb2<nb_of_elem_fields) {
                val.resize(nb_of_comp[nb2]);
                for(unsigned i=0;i<nb_of_comp[nb2];++i) {
                    s >> mmmm.data[nb][nb2][i];
                    //                debug << mmmm.data[nb][nb2][i] << endl;
                }
                ++nb2;
            }
            ++nb;
        }

        apply( mesh.elem_list, mmmm);
    }

    {//reading globals fields
        ///nbglobal_data
        string str;
        getline(is,str);
        istringstream s(str);

        nb=0;
        int nb_of_global_fields;
        s >> nb_of_global_fields;
//         debug << "nb_of_global_fields " << nb_of_global_fields << endl;
        Vec<int> nb_of_comp;
        nb_of_comp.resize(nb_of_global_fields);
        while(nb<nb_of_global_fields) {
            s >> nb_of_comp[nb];
            ++nb;
        }
//         debug << "nb of comp " << nb_of_comp << endl;
        nb=0;
        Vec<string> global_fields_names;
        Vec<string> global_fields_units;
        global_fields_names.resize(nb_of_global_fields);
        global_fields_units.resize(nb_of_global_fields);

        while(nb<nb_of_global_fields) {
            string str;
            getline(is,str);
            istringstream s(str);
            string buf;
            s >> buf;
            Vec<std::string> split = tokenize( str, ',' );
            global_fields_names[nb] = split[0];
            global_fields_units[nb] = split[1];
            ++nb;
        }
//         debug << "names " << global_fields_names << " " <<  global_fields_units << endl;

        nb=0;
        int number;

        Totito mmmm;
        mmmm.fname = global_fields_names;
        mmmm.data.resize(nbelem);
        for(unsigned i=0;i<1;++i)
            mmmm.data[i].resize(nb_of_global_fields);
        for(unsigned i=0;i<1;++i)
            for(unsigned ii=0;ii<nb_of_global_fields;++ii)
                mmmm.data[i][ii].resize(nb_of_comp[ii]);

        while(nb<nb_of_global_fields) {
            string str;
            getline(is,str);
            istringstream s(str);
            //val.resize(nb_of_comp[nb2]);
            for(unsigned i=0;i<nb_of_comp[nb];++i) {
                s >> mmmm.data[0][nb][i];
                //                debug << mmmm.data[nb][nb2][i] << endl;
            }
            ++nb;
        }
        mmmm.number=0;
        DM::apply_with_names(mesh, mmmm);
    }
*/
}

/// put avs mesh castem in m
template<class TM>
void read_avs(TM &m,const std::string &fic_name) throw(std::runtime_error) {
    // ouverture du fichier
    std::ifstream my_file( fic_name.c_str() );
    if ( ! my_file.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed.");
    return read_avs(m,my_file);
}

};
#endif //READ_AVS_H
