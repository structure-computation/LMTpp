//
// C++ Interface: write_avs
//
// Description:
//
//
// Author: Felipe Bordeu Weldt <bordeu@lmt.ens-cachan.fr>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

/// Mesh in avs.imp file
struct cell_output_bin {
    template<class TE, class TF>
    void operator()(TE &e, TF &outfile) const {

        outfile.write ((char *)&e.number, sizeof(int)); /// Cell id number

#ifdef DEBUG_FELIPE
        debug << e.number<< " ";
#endif

        int a;
        a = int (e.type_formulation);
        outfile.write ((char *)&a, sizeof(int));   /// Material ID
#ifdef DEBUG_FELIPE
        debug << a<< " ";
#endif

        if (e.name_virtual() == "Hexa") {
            a=8;
            outfile.write ((char *)&a, sizeof(int));   /// Number of nodes
#ifdef DEBUG_FELIPE
            debug << "hex" << " ";
#endif
            a=7;
            outfile.write ((char *)&a, sizeof(int));  /// cell type
#ifdef DEBUG_FELIPE
            debug << a<< " " ;
#endif


            //        for(unsigned i=0;i<8;++i) {
            //            a = e.node(i)->number_in_original_mesh();
            //            outfile.write ((char *)&a, sizeof(int));   /// cell conetivity
            //            debug << a << " ";
            //        }

#ifdef DEBUG_FELIPE
            debug << endl;
#endif

        }
    }
};

struct cell_output_node_bin {
    template<class TE, class TF>
    void operator()(TE &e, TF &outfile) const {
        //outfile.write ((char *)&e.number, sizeof(int)); /// number of model data.
        int a;
        for(unsigned i=0;i<8;++i) {
            a = e.node(i)->number_in_original_mesh();
            outfile.write ((char *)&a, sizeof(int));   /// cell conetivity
#ifdef DEBUG_FELIPE
            debug << a<< " ";
#endif
        }
#ifdef DEBUG_FELIPE
        debug << endl;
#endif
    }
};

struct node_output_bin {
    template<class TE, class TF>
    void operator()(TE &e, TF &outfile, int pos) const {
        double val = e.pos[pos];
        outfile.write ((char *)&val, sizeof(double)); /// output of coordinates for nodes.
#ifdef DEBUG_FELIPE
        debug << e.pos[pos] << " ";
#endif
    }
};

struct cell_output_ascii {
    template<class TE, class TF>
    void operator()(TE &e, TF &outfile) const {
        /// Cell id number
        outfile << e.number+1 << " " ;
//         int a;
        /// Material ID
        //outfile << int (e.type_formulation) << " ";
        outfile << 0 << " ";
        if (e.name_virtual() == "Hexa") {
            /// Number of nodes
            outfile << "hex ";
            for(unsigned i=0;i<8;++i)
                outfile << (e.node(i)->number_in_original_mesh()+1) << " ";
            outfile  << endl;
        } else if(e.name_virtual() == "Wedge" ) {
            /// Number of nodes
            outfile << "prism ";
            for(unsigned i=0;i<6;++i)
                outfile << (e.node(i)->number_in_original_mesh()+1) << " ";
            outfile  << endl;
        } else if(e.name_virtual() == "Tetra" ) {
            /// Number of nodes
            outfile << "tet ";
            for(unsigned i=0;i<4;++i)
                outfile << (e.node(i)->number_in_original_mesh()+1) << " ";
            outfile  << endl;
        }
    }
};

struct node_output_ascii {
    template<class TE, class TF>
    void operator()(TE &e, TF &outfile) const {
        outfile << e.number+1 << " ";
        for(unsigned i=0;i<3;++i)
            outfile << e.pos[i] << " ";
        outfile << endl;
    }
};

struct Toto {
    template<class T>
    void operator()(unsigned num,const char *name,T val) const {
        if (name==cqjd) {//outfile << val << " " ;}
            *outfile <<  val << " ";
        }
    }
    template<class TE>
    void operator()(TE &e,const Vec<std::string> &cell_data_name) {
        *outfile << e.number+1 << " " ;
        for(unsigned i=0;i<cell_data_name.size();++i) {
            cqjd = cell_data_name[i];
            DM::apply_with_names( e, *this );
        }
        *outfile << endl;
    }
    std::string cqjd;
    std::ofstream *outfile;

};

#ifndef BINARY_
#define BINARY_
struct Binary {}
;
#endif

#ifndef Ascii_
#define Ascii_
struct Ascii {}
;
#endif

///**************************************************************************************
template<class TM>
void write_avs(const TM &mesh,const string &name,const Vec<string> &display_fields, Binary) throw(std::runtime_error) {

    std::ofstream outfile(name.c_str(), ios::binary);

    if(outfile.fail())
        cerr << "Error al crear el archivo : " << name << endl;
    else {

        int a;

        a=7;
        outfile.write( (char * )&a, sizeof(char) ); ///The magic number is the ASCII character BEL whose decimal value is 7.
#ifdef DEBUG_FELIPE
        debug << " 7 " ;
#endif

        a = mesh.node_list.size();
#ifdef DEBUG_FELIPE
        debug << a << " ";
#endif
        outfile.write ((char *)&a, sizeof(int));  /// The number of node


        a = mesh.elem_list.size();
#ifdef DEBUG_FELIPE
        debug << a << " ";
#endif
        outfile.write ((char *)&a, sizeof(int)); /// The number of cells


        a=0;
        if ( mesh.node_list.size() ) {

            const char *names[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_names<typename TM::TNode>( names );
            unsigned nb_comp[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_nb_comp<typename TM::TNode>( nb_comp );
            for(unsigned i=0;i<TM::TNode::nb_params;++i)
                nb_comp[i] += (nb_comp[i]==2);
            GetDynamicSize<TM::TNode::nb_params> gds;
            for(unsigned i=0;i<mesh.node_list.size();++i)
                DM::apply( mesh.node_list[i], gds );


#ifdef DEBUG_FELIPE
            debug << "(nb_params :" << TM::TNode::nb_params << ") ";
#endif
            for(unsigned i=0;i<TM::TNode::nb_params;++i) {
                // debug << "names :" << string(names[i]) << endl;
                // debug << "nb_comp :" << nb_comp[i] <<endl;
            }

            for(unsigned i=0;i<TM::TNode::nb_params;++i) {
                if ( std::find(display_fields.begin(),display_fields.end(),std::string(names[i]))!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {    //continue;
                    // debug << std::string(names[i]) << endl;
                    ++a;
                }
            }
        }

        a=0;/// ////////////////////////////
        outfile.write ((char *)&a, sizeof(int)); /// The number of node Fields, is zero if no node fields is present
#ifdef DEBUG_FELIPE
        debug << a << " ";
#endif

        a=0;

        if ( mesh.elem_list.size() ) {
            // static
            Data_vtk_extract_elem<false> dve;
            mesh.elem_list.apply_static(dve);
            apply( mesh.elem_list, dve, display_fields );
            for(typename Data_vtk_extract_elem<false>::Map::const_iterator iter=dve.mapd.begin();iter!=dve.mapd.end();++iter) {
                if ( std::find(display_fields.begin(),display_fields.end(),iter->first)!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all")) {    //continue;
                    if ( iter->second.nb_comp ) {

                        ++a;
                        // debug << "nombre :" <<  iter->first << endl;
                        // debug << "NumberOfComponents=" << iter->second.nb_comp << endl;
                    }
                }
            }
            // dynamic
            for(unsigned i=0;i<mesh.elem_list.nb_dyn_data();++i) {
                const DynamicDataAncestor *dd = mesh.elem_list.get_dyn_data(i);
                if ( std::find(display_fields.begin(),display_fields.end(),dd->get_name())!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all")) {    //continue;
                    if ( dd->nb_comp()==0 )
                        continue;
                    // debug << "                <DataArray Name='" << dd->get_name() << endl ;
                    // debug << "' NumberOfComponents='" << dd->nb_comp() << "' type='Float64' format='ascii'>" << endl;
                    //debug << endl;
                    //debug << "                </DataArray>" << endl;
                }
            }
        }



        // debug << "cantidad de data por cell : " << a << endl;
        a =0 ; /// /////////////////////////////////
        outfile.write ((char *)&a, sizeof(int)); /// The number of cell data fields, is zero if no node data fields is present.
#ifdef DEBUG_FELIPE
        debug << a<< " ";
#endif




        a= 0;

        const char *names[TM::nb_params+(TM::nb_params==0)];
        DM::get_names<TM>( names );
        unsigned nb_comp[TM::nb_params+(TM::nb_params==0)];
        DM::get_nb_comp<TM>( nb_comp );
        for(unsigned i=0;i<TM::nb_params;++i)
            nb_comp[i] += (nb_comp[i]==2);

        Data_vtk_extract<TM::nb_params,false> dvem;
        DM::get_nb_comp<TM>( dvem.nb_comp );
        DM::apply( mesh, dvem );
        for(unsigned i=0;i<TM::nb_params;++i) {
            if ( std::find(display_fields.begin(),display_fields.end(),names[i])!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {    //continue;
                if ( nb_comp[i]==0 )
                    continue;
                //debug << " <DataArray Name='" << names[i]  << "' NumberOfComponents='" << nb_comp[i] << "' type='Float64' format='" << "' offset='"  << "'>\n";
                std::string s;
                s.reserve( dvem.os[i].str().size() * mesh.elem_list.size() );
                for(unsigned k=0;k<mesh.elem_list.size();++k)
                    s += dvem.os[i].str();
                //               debug << s;
                //debug << "                </DataArray>" << std::endl;
                ++a;
            }
        }
        a=0;/////////////////////////////////////////////////////////
        // debug << "cantidad de datos globales : "  << a << endl; a = 0 ; /// ///////////////////////////////////
        outfile.write ((char *)&a, sizeof(int)); /// number of model data.
#ifdef DEBUG_FELIPE
        debug << a << endl;
#endif
        int nListNodes = 8;
        outfile.write ((char *)&nListNodes, sizeof(int)); ///Number of nlist nodes. This is equal to the product of the number of cells in each cell set and the number of nodes present in each cell set. This is for cell topology.
#ifdef DEBUG_FELIPE
        debug << "(nListNodes :" << nListNodes  << ")" << nListNodes << endl;
#endif
        ;
        ///cell information

        //        char buffer1[1024], buffer2[1024], label[32];

        apply(mesh.elem_list,cell_output_bin(),outfile);

        apply(mesh.elem_list,cell_output_node_bin(),outfile);

        apply(mesh.node_list,node_output_bin(),outfile, 0);
#ifdef DEBUG_FELIPE
        debug << endl;
#endif
       apply(mesh.node_list,node_output_bin(),outfile, 1);
#ifdef DEBUG_FELIPE
        debug << endl;
#endif
       apply(mesh.node_list,node_output_bin(),outfile, 2);
#ifdef DEBUG_FELIPE
        debug << endl;
#endif

        Vec<int> node_data_comp;
        Vec<string> node_data_name;
        if ( mesh.node_list.size() ) {
            const char *names[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_names<typename TM::TNode>( names );
            unsigned nb_comp[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_nb_comp<typename TM::TNode>( nb_comp );
            for(unsigned i=0;i<TM::TNode::nb_params;++i)
                nb_comp[i] += (nb_comp[i]==2);
            GetDynamicSize<TM::TNode::nb_params> gds;
            for(unsigned i=0;i<mesh.node_list.size();++i)
                DM::apply( mesh.node_list[i], gds );


            for(unsigned i=0;i<TM::TNode::nb_params;++i) {
                if ( std::find(display_fields.begin(),display_fields.end(),std::string(names[i]))!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {    //continue;
                    // debug << std::string(names[i]) << endl;
                    ++a;
                    node_data_comp.resize(a);
                    node_data_name.resize(a);
                    node_data_comp[a-1]= nb_comp[i];
                    node_data_name[a-1]= string(names[i]);
                }
            }
        }


        outfile.close();
    }


};
///************************************************************************************************************
template<class TM>
void write_avs(const TM &mesh,const string &name,const Vec<string> &display_fields, Ascii ) throw(std::runtime_error) {

    std::ofstream outfile(name.c_str());

    if(outfile.fail())
        cerr << "Error al crear el archivo : " << name << endl;
    else {


        outfile << mesh.node_list.size() << "  ";
        outfile << mesh.elem_list.size() << " ";

        int a;
        a=0;
        Vec<int> node_data_comp;
        Vec<string> node_data_name;

        if ( mesh.node_list.size() ) {
            const char *names[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_names<typename TM::TNode>( names );
            unsigned nb_comp[TM::TNode::nb_params+(TM::TNode::nb_params==0)];
            DM::get_nb_comp<typename TM::TNode>( nb_comp );
            for(unsigned i=0;i<TM::TNode::nb_params;++i)
                nb_comp[i] += (nb_comp[i]==2);
            GetDynamicSize<TM::TNode::nb_params> gds;
            for(unsigned i=0;i<mesh.node_list.size();++i)
                DM::apply( mesh.node_list[i], gds );


            for(unsigned i=0;i<TM::TNode::nb_params;++i) {
                if ( std::find(display_fields.begin(),display_fields.end(),std::string(names[i]))!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {    //continue;
                    ++a;
                    node_data_comp.resize(a);
                    node_data_name.resize(a);
                    node_data_comp[a-1]= nb_comp[i];
                    node_data_name[a-1]= string(names[i]);
                }
            }
        }


        outfile << sum(node_data_comp) << " ";/// The number of node data is zero if no node data is present

        a=0;

        Vec<int> cell_data_comp;
        Vec<string> cell_data_name;

        if ( mesh.elem_list.size() ) {
            // static
            Data_vtk_extract_elem<false> dve;
            mesh.elem_list.apply_static(dve);
            apply( mesh.elem_list, dve, display_fields );
            for(typename Data_vtk_extract_elem<false>::Map::const_iterator iter=dve.mapd.begin();iter!=dve.mapd.end();++iter) {
                if ( std::find(display_fields.begin(),display_fields.end(),iter->first)!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all")) {    //continue;
                    if ( iter->second.nb_comp ) {

                        ++a;
                        cell_data_comp.resize(a);
                        cell_data_name.resize(a);
                        cell_data_comp[a-1]= iter->second.nb_comp ;
                        cell_data_name[a-1]= iter->first;
                    }
                }
            }
            // dynamic
            for(unsigned i=0;i<mesh.elem_list.nb_dyn_data();++i) {
                const DynamicDataAncestor *dd = mesh.elem_list.get_dyn_data(i);
                if ( std::find(display_fields.begin(),display_fields.end(),dd->get_name())!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all")) {    //continue;
                    if ( dd->nb_comp()==0 )
                        continue;
                }
            }
        }

        outfile << sum(cell_data_comp) << " ";/// The number of cell data is zero if no node data is present

        Vec<int> glob_data_comp;
        Vec<string> glob_data_name;

        a= 0;
        const char *names[TM::nb_params+(TM::nb_params==0)];
        DM::get_names<TM>( names );
        unsigned nb_comp[TM::nb_params+(TM::nb_params==0)];
        DM::get_nb_comp<TM>( nb_comp );
        for(unsigned i=0;i<TM::nb_params;++i)
            nb_comp[i] += (nb_comp[i]==2);

        Data_vtk_extract<TM::nb_params,false> dvem;
        DM::get_nb_comp<TM>( dvem.nb_comp );
        DM::apply( mesh, dvem );
        for(unsigned i=0;i<TM::nb_params;++i) {
            if ( std::find(display_fields.begin(),display_fields.end(),names[i])!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {    //continue;
                if ( nb_comp[i]==0 )
                    continue;
                ++a;
                glob_data_comp.resize(a);
                glob_data_name.resize(a);
                glob_data_comp[a-1]= nb_comp[i] ;
                glob_data_name[a-1]= names[i];
            }
        }

        /// number of model data.
        outfile << sum(glob_data_comp) << endl;

        ///cell information
        apply(mesh.node_list,node_output_ascii(),outfile);
        apply(mesh.elem_list,cell_output_ascii(),outfile);

        /// nodes data
        if(node_data_comp.size()) {

            outfile << node_data_comp.size() << " " << node_data_comp << endl;

            for(unsigned i=0;i<node_data_name.size();++i) {
                outfile << node_data_name[i] << "," << "1" << endl;
            }
            for(unsigned j=0;j<mesh.node_list.size();++j) {
                outfile << j+1 << " " ;
                for(unsigned i=0;i<node_data_name.size();++i) {
                    Toto toto;
                    toto.outfile = &outfile;
                    toto.cqjd = node_data_name[i];
                    DM::apply_with_names( mesh.node_list[j], toto);
                }
                outfile << endl;
            }
        }
        ///  element data
        if (cell_data_comp.size()) {
            outfile << cell_data_comp.size() << " " << cell_data_comp << endl;
            for(unsigned i=0;i<cell_data_name.size();++i) {
                outfile << cell_data_name[i] << "," << "1" << endl;
            }

            Toto toto;
            toto.outfile = &outfile;
            apply( mesh.elem_list, toto, cell_data_name );

        }
        /// global data
        if (glob_data_comp.size()) {
            outfile << glob_data_comp.size() << " " << glob_data_comp << endl;

            for(unsigned i=0;i<glob_data_name.size();++i)
                outfile << glob_data_name[i] << ",1" << endl;

            for(unsigned i=0;i<TM::nb_params;++i) {
                if ( std::find(display_fields.begin(),display_fields.end(),names[i])!=display_fields.end() or (display_fields.size()>=1 and display_fields[0]=="all") ) {
                    outfile << dvem.os[i].str() << endl;
                }
            }
        }
        outfile.close();
    }
};


///**************************************************************************************
template<class TM, class TP>
void write_avs(TM &mesh, unsigned num, TP &structure, Binary) throw(std::runtime_error) {

    Vec<string> display_fields = structure.output;
    string path = structure.path;
    ostringstream ss;
    ss << path << "tmp/avs" << setfill('0') << setw(4) << num << ".inp";
    string name(ss.str());

    write_avs(mesh,name,display_fields, Binary());

}

///************************************************************************************************************
template<class TM, class TP>
void write_avs(TM &mesh, unsigned num, TP &structure, Ascii ) throw(std::runtime_error) {

    Vec<string> display_fields = structure.output;
    string path = structure.path;
    ostringstream ss;
    ss << path << "tmp/avs" << setfill('0') << setw(4) << num << ".inp";
    string name(ss.str());
    std::ofstream outfile(name.c_str());

    write_avs(mesh,name,display_fields, Ascii());

}

