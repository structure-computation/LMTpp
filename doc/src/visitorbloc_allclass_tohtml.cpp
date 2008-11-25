#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<map>

#include<cmath>
#include"time.h"

using namespace std ;

#include "parameter.h"
#include "classe.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_allclass_tohtml.h"
#include "visitorbloc_namebaseclass.h"
#include "visitorbloc_getcaracteristicclass.h"
#include "visitorbloc_getcaracteristicstruct.h"
#include "visitorbloc_getcaracteristicfunction.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"
#include "listtarget.h"
#include "target.h"
//#include "visitorcommentitem_tohtml.h"

void VisitorBloc_AllClass_toHTML :: generate_stream_HTML_for_typedef( ofstream* f, Bloc* b, bool sommary ) {

    Target* ptr_t ;
    string stmp, stmp2,stmp3 ;
    int i,n,m,j ;

    n = b->listTypedef.size() ;
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> typedef </h3> " << std::endl ;
            *f << "<div class=\"sommaire_typedef\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                stmp = b->listTypedef[i].type.name ;
                if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                else
                    stmp2 = french2HTML( stmp ) ;
                stmp = b->listTypedef[i].nameVariable ;
                if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp3 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                else
                    stmp3 = french2HTML( stmp ) ;
                *f << "<li> " << stmp2 << "  &#x21D4  " << stmp3 << " </li>"  << std::endl ;
            }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
        else {
            *f << "<div class=\"description_typedef\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                m = b->listTypedef[i].listTag.size() ;
                if (m>0) {
                    *f <<  "<li> <strong> typedef " ;
                    stmp = b->listTypedef[i].type.name ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                    else
                        stmp2 = french2HTML( stmp ) ;
                    stmp = b->listTypedef[i].nameVariable ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp3 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                    else
                        stmp3 = french2HTML( stmp ) ;
                    *f << stmp2 << " " << stmp3 << " " ;
                    *f << "</strong> </li>" << std::endl ;
                    for(j=0;j<m;j++) 
                        b->listTypedef[i].listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent ) ;
                }
            }
            *f << "<ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
    }
}

void VisitorBloc_AllClass_toHTML :: generate_stream_HTML_for_class_or_struct( ofstream* f, Bloc* b, bool sommary ) {

    VisitorBloc_GetCaracteristicClass    visitor_caract_class ;
    VisitorBloc_GetCaracteristicStruct   visitor_caract_struct ;
    string stmp, stmp2, stmp3 ;
    int i,n,m,j ;
    Target* ptr_t ;

    n = b->list_subType_function.size() ;
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> sous-classe ou sous-struct </h3> " << std::endl ;
            *f << "<div class=\"sommaire_structure\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->execute_function( &visitor_caract_class ) ;
                b->list_subType_function[i]->execute_function( &visitor_caract_struct ) ;
                if (visitor_caract_class.enphase || visitor_caract_struct.enphase ) {
                    *f << "<li> " << b->list_subType_function[i]->portee + " " ;
                    m = b->list_subType_function[i]->listTemplateParameter.size() ;
                    if (m>0) {
                        *f << " <strong> template </strong> &lt; " ;
                        for(j=0;j<m;j++) {
                            *f << " <strong> " << b->list_subType_function[i]->listTemplateParameter[j]->type << " </strong> " ;
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name ;
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                            else
                                stmp2 = french2HTML( stmp ) ;
                            if (b->list_subType_function[i]->listTemplateParameter[j]->defaultType.size() > 0)
                                stmp2 +=  " = " + b->list_subType_function[i]->listTemplateParameter[j]->defaultType ;
                            if (j != m-1)
                                *f << stmp2 << "," ;
                            else
                                *f << stmp2 << " &gt; " ;
                        }
                    }
                    if (visitor_caract_class.enphase)
                        stmp3 = " class " ;
                    else
                        stmp3 = " struct " ;
                    *f << " <strong>" << stmp3 << "</strong> " << link_fragmentHTML( b->list_subType_function[i]->name.name ) <<  " </li>" << std::endl ;
                }
            }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
        else {
            *f << "<div class=\"description_structure\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->execute_function( &visitor_caract_class ) ;
                b->list_subType_function[i]->execute_function( &visitor_caract_struct ) ;
                if (visitor_caract_class.enphase || visitor_caract_struct.enphase ) {
                    *f << "<li> <strong> " << b->list_subType_function[i]->portee + " " ;
                    m = b->list_subType_function[i]->listTemplateParameter.size() ;
                    if (m>0) {
                        *f << " template &lt; " ;
                        for(j=0;j<m;j++) {
                            *f << " " << b->list_subType_function[i]->listTemplateParameter[j]->type << " " ;
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name ;
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                            else
                                stmp2 = french2HTML( stmp ) ;
                            if (b->list_subType_function[i]->listTemplateParameter[j]->defaultType.size() > 0)
                                stmp2 +=  " = " + b->list_subType_function[i]->listTemplateParameter[j]->defaultType ;
                            if (j != m-1)
                                *f << stmp2 << "," ;
                            else
                                *f << stmp2 << " &gt; " ;
                        }
                    }
                    *f << " class " << ancreHTML( b->list_subType_function[i]->name.name,true ) <<  " </strong> </li>" << std::endl ;
                    m = b->list_subType_function[i]->listTag.size() ;
                    for(j=0;j<m;j++) 
                        b->list_subType_function[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent ) ;
                }
            }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
    }
}

void VisitorBloc_AllClass_toHTML :: generate_stream_HTML_for_method( ofstream* f, Bloc* b, bool sommary ) {

    VisitorBloc_GetCaracteristicFunction visitor_caract_function ;
    int n,i,m,j ;
    string stmp ;
    string stmp2 ;
    string stmp3 ;
    ListParameter* ptr_listParameter ;
    Target* ptr_t ;


    n = b->list_subType_function.size() ;
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> m&eacute;thodes </h3> " << std::endl ;
            *f << "<div class=\"sommaire_method\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->execute_function( &visitor_caract_function ) ;
                if (visitor_caract_function.enphase) {
                    *f << "<li> " << b->list_subType_function[i]->portee + " " ;
                    m = b->list_subType_function[i]->listTemplateParameter.size() ;
                    if (m>0) {
                        *f << " <strong> template </strong> &lt; " ;
                        for(j=0;j<m;j++) {
                            *f << " <strong> " << b->list_subType_function[i]->listTemplateParameter[j]->type << " </strong> " ;
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name ;
                            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                            else
                                stmp2 = french2HTML( stmp ) ;
                            if (j != m-1)
                                *f << stmp2 << "," ;
                            else
                                *f << stmp2 << " &gt; " ;
                        }
                    }
                    stmp = (*visitor_caract_function.ptr_returnType).name ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp ) ;
                    else
                        stmp2 = french2HTML( stmp ) ;
                    *f << stmp2 << "   " ;
                    stmp = b->list_subType_function[i]->name.name ;
                    *f << link_fragmentHTML( stmp ) << " ( " ;
                    ptr_listParameter = visitor_caract_function.ptr_listParameter ;

                    ptr_listParameter->display_parameter_to_HTML(f,ptr_list_target,b);
                    *f << " ) " ;
//                     if (m == 0)
//                         *f << " ) " ;
                    stmp = *visitor_caract_function.ptr_listAttribut ;
                    *f << " <strong> " << stmp << " </strong> ; </li>" << std::endl ;
                }
            }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
        else {
            *f << "<div class=\"description_method\">" << std::endl ;
            *f << "<ul>" << std::endl ;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->execute_function( &visitor_caract_function ) ;
                if (visitor_caract_function.enphase) {
                    *f << "<li> <strong> " << b->list_subType_function[i]->portee + " " ;
                    m = b->list_subType_function[i]->listTemplateParameter.size() ;
                    if (m>0) {
                        *f << " template  &lt; " ;
                        for(j=0;j<m;j++) {
                            *f << " " << b->list_subType_function[i]->listTemplateParameter[j]->type << " " ;
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name ;
                            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                            else
                                stmp2 = french2HTML( stmp ) ;
                            if (j != m-1)
                                *f << stmp2 << "," ;
                            else
                                *f << stmp2 << " &gt; " ;
                        }
                    }
                    stmp = (*visitor_caract_function.ptr_returnType).name ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                    else
                        stmp2 = french2HTML( stmp ) ;
                    *f << stmp2 << "   " ;
                    stmp = b->list_subType_function[i]->name.name ;
                    *f << ancreHTML( stmp,true ) << " ( " ;
                    ptr_listParameter = visitor_caract_function.ptr_listParameter ;
                    m = (*ptr_listParameter).size() ;
                    for(j=0;j<m;j++) {
                        stmp = (*ptr_listParameter)[j].type.name ;
                        if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                            stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                        else
                            stmp2 = french2HTML( stmp ) ;
                        *f << " " <<  (*ptr_listParameter)[j].listAttribut << " " << stmp2 << " " ;
                        *f << (*ptr_listParameter)[j].nameVariable ;
                        stmp = (*ptr_listParameter)[j].defaultType ;
                        if (stmp.size() > 0 ) {
                            *f << " = " << french2HTML( stmp ) << " " ;
                        }
                        if (j != m-1)
                            *f << ", " ;
                        else
                            *f << " ) " ;
                    }
                    if (m == 0)
                        *f << " ) " ;
                    stmp = *visitor_caract_function.ptr_listAttribut ;
                    *f << " " << stmp << " ; </strong> </li>" << std::endl ;
                    m = b->list_subType_function[i]->listTag.size() ;
                    for(j=0;j<m;j++) 
                        b->list_subType_function[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent ) ;
                }
            }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
    }
}

void VisitorBloc_AllClass_toHTML :: generate_stream_HTML_for_attribut( ofstream* f, Bloc* b, bool sommary ) {

    int i,n,j,m ;
    string stmp ;
    string stmp2 ;
    Target* ptr_t ;


    n = b->listMember.size() ;
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> attributs </h3> " << std::endl ;
            *f << "<div class=\"sommaire_attribut\">" << std::endl ;
            *f << "<ul>" << std::endl ;
                for(i=0;i<n;i++) {
                    stmp = b->listMember[i].listAttribut ;
                    *f << "<li> " << " <strong> " << stmp << " </strong> " ;
                    stmp = b->listMember[i].type.name ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                    else
                        stmp2 = french2HTML( stmp ) ;
                    *f << stmp2 << "  " ;
                    stmp = b->listMember[i].nameVariable ;
                    *f << link_fragmentHTML( stmp ) << " " ;
                    if ( b->listMember[i].defaultType.size() >0 ) {
                        stmp = b->listMember[i].defaultType ;
                        *f << " = " <<french2HTML( stmp ) << " ; </li> " << std::endl ;
                    } else
                        *f << " ; </li> " << std::endl ;

                }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
        else {
            *f << "<div class=\"description_attribut\">" << std::endl ;
            *f << "<ul>" << std::endl ;
                for(i=0;i<n;i++) {
                    stmp = b->listMember[i].listAttribut ;
                    *f << "<li> <strong> " << stmp << " " ;
                    stmp = b->listMember[i].type.name ;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                    else
                        stmp2 = french2HTML( stmp ) ;
                    *f << stmp2 << "  " ;
                    stmp = b->listMember[i].nameVariable ;
                    *f << ancreHTML( stmp,true ) << " " ;
                    if ( b->listMember[i].defaultType.size() >0 ) {
                        stmp = b->listMember[i].defaultType ;
                        *f << " = " << french2HTML( stmp ) << " ; </strong> </li> " << std::endl ;
                    } else
                        *f << " ; </strong> </li> " << std::endl ;
                    m = b->listMember[i].listTag.size() ;
                    for(j=0;j<m;j++) 
                        b->listMember[i].listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent ) ;
                }
            *f << "</ul>" << std::endl ;
            *f << "</div>" << std::endl ;
        }
    }
}

void VisitorBloc_AllClass_toHTML :: generate_page_HTML_for_class_or_struct( const string& type_block, Bloc* b ) {

    int n,i,m,j ;
    string stmp ;
    string stmp2 ;
    string stmp3 ;
    VisitorBloc_GetCaracteristicClass    visitor_caract_class ;
    VisitorBloc_GetCaracteristicStruct   visitor_caract_struct ;
    ListParameter* ptr_listParameter ;
    Target* ptr_t ;

    //stmp = b->path + french2webID( b->name.name ) + ".html" ;
    stmp = b->reference() ;
    ofstream pageWeb( stmp.c_str() ,ios::out);

    stmp = type_block + ' ' + french2HTML( b->name.name ) ;

    generate_header( b, (*ptr_tree)["root"], pageWeb, stmp ) ;

    pageWeb << "<hr />" << std::endl ;
    
    pageWeb << "<div class=\"table_des_matieres\">" << std::endl ;
    
    /// namespace
    if (b->_namespace.size() > 0) {
        pageWeb << "<br> <strong>  namespace is </strong> " << b->_namespace << std::endl ;
    }

    /// les héritages
    b->execute_function( &visitor_caract_class ) ;
    b->execute_function( &visitor_caract_struct ) ;
    if (visitor_caract_class.enphase) {
        ptr_listParameter = visitor_caract_class.ptr_listHerited ;
        n = (*ptr_listParameter).size() ;
    } else {
        if (visitor_caract_struct.enphase) {
            ptr_listParameter = visitor_caract_struct.ptr_listHerited ;
            n = (*ptr_listParameter).size() ;
        } else
            n = 0 ;
    }

    if (n>0) {
        pageWeb <<  "<h3> H&eacute;rite de </h3> " << std::endl ;
        pageWeb << "<ul name=\"herited\" >" << std::endl ;
        for(i=0;i<n;i++) {
            stmp = (*ptr_listParameter)[i].type.name ;
            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
            else
                stmp2 = french2HTML( stmp ) ;
            pageWeb << "<li> <strong>" << (*ptr_listParameter)[i].listAttribut << " </strong>" << "   " <<  stmp2 << " </li>" << std::endl ;
        }
        pageWeb << "</ul>" << std::endl ;
    }

    /// les paramètres template

    n = b->listTemplateParameter.size() ;
    if (n>0) {
        pageWeb <<  "<br><strong> Param&egrave;tre template : </strong> " << std::endl ;
        //pageWeb << "<ul class=\"parameter_template\" >" << std::endl ;
        for(i=0;i<n;i++) {
            //pageWeb << "<li> <strong> " << b->listTemplateParameter[i]->type << " </strong> " ;
            stmp = b->listTemplateParameter[i]->name ;
            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
            else
                stmp2 = french2HTML( stmp ) ;
            pageWeb << stmp2 << " " ;
            stmp = b->listTemplateParameter[i]->defaultType ;
            if (stmp.size() >0) {
                //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
                if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp ) ;
                else
                    stmp2 = french2HTML( stmp ) ;
                pageWeb << " = " << stmp2  /* << " </li>"    << std::endl */ ;
                if (i != n-1)
                    pageWeb << " , " ;
                else
                    pageWeb << " . " << endl ;
            }
            else {
                if (i != n-1)
                    pageWeb << " , " ;
                else
                    pageWeb << " . " << endl ;
            }
        }
        //pageWeb << "</ul>" << std::endl ;
    }

    /// typedef de la classe
    generate_stream_HTML_for_typedef( &pageWeb,b,true ) ;

    /// sous-type classe de la classe
    generate_stream_HTML_for_class_or_struct( &pageWeb,b,true ) ;

    /// sous-type function de la classe
    generate_stream_HTML_for_method( &pageWeb,b,true ) ;

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,b,true) ;


    pageWeb << "<br>" << std::endl ;
    pageWeb << "<hr />" << std::endl ;
    pageWeb <<  "<h2> Description </h2> " << std::endl ;
    pageWeb << "<div class=\"description_structure\">" << std::endl ;

    n = b->listTag.size() ;
    if (n>0) {
        for(i=0;i<n;i++) {
            b->listTag[i]->generate_pageHTML(&pageWeb,ptr_list_target,ptr_parent ) ;
        }
    }
    pageWeb << "</div>" ;
    /// typedef de la classe
    generate_stream_HTML_for_typedef( &pageWeb,b,false ) ;

    /// sous-classe ou sous-struct de la classe
    generate_stream_HTML_for_class_or_struct( &pageWeb,b,false ) ;

    /// methodes de la classe
    generate_stream_HTML_for_method( &pageWeb,b,false ) ;

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,b,false) ;

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl ;
    pageWeb << linkHTML( b->reference(),b->source_file,b->source_file ) <<  "    " ;
    ///stmp = enleve_suffix( b->source_file ) + b->suffix_source ;       /// <--------------------- problème éventuel si c'est un code C    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///pageWeb << linkHTML( b->reference(),stmp,stmp ) << std::endl ;
    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}

void VisitorBloc_AllClass_toHTML :: function_at_Classe( Classe* c ) {

    generate_page_HTML_for_class_or_struct( "class",c ) ;
}

void VisitorBloc_AllClass_toHTML :: function_at_Struct( Struct* s ) {

    generate_page_HTML_for_class_or_struct( "struct",s ) ;
}

void VisitorBloc_AllClass_toHTML :: function_at_Function( Function* f ) {

    int j,m ;
    Target* ptr_t ;
    string stmp ;
    string stmp2 ;
    string stmp3 ;
    string path ;


        stmp = f->reference() ;
        ofstream pageWeb( stmp.c_str() ,ios::out);
        stmp = "fonction " + french2HTML( f->name.name ) ;

        generate_header( f, (*ptr_tree)["root"], pageWeb, stmp ) ;

        pageWeb << "<div class=\"fonction\">" << std::endl ;
        pageWeb << f->portee << " " ;
        m = f->listTemplateParameter.size() ;
        if (m>0) {
            pageWeb << " <strong> template </strong> &lt; " ;
            for(j=0;j<m;j++) {
                pageWeb << " <strong> " << f->listTemplateParameter[j]->type << " </strong> " ;
                stmp = f->listTemplateParameter[j]->name ;
                if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
                    stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp ) ;
                }
                else
                    stmp2 = french2HTML( stmp ) ;
                if (j != m-1)
                    pageWeb << stmp2 << "," ;
                else
                    pageWeb << stmp2 << " &gt; " ;
            }
        }
        stmp = f->returnType.name ;
        //cerr << "f->returnType.name = " << stmp << endl ;
        if ((ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
//             cerr << " ptr_t = " << ptr_t << endl ;
//             cerr << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl ;
//             cerr << *ptr_list_target << endl ;
//             cerr << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl ;
            stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp ) ;
        }
        else
            stmp2 = french2HTML( stmp ) ;
        pageWeb << stmp2 << "   " ;
        pageWeb << french2HTML( f->name.name ) << " ( " ;
        m = f->listParameter.size() ;
        for(j=0;j<m;j++) {
            stmp = f->listParameter[j].type.name ;
            if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
                stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp ) ;
            }
            else
                stmp2 = french2HTML( stmp ) ;
            pageWeb << " <strong> " <<  f->listParameter[j].listAttribut << " " << stmp2 << " </strong> " ;
            pageWeb << f->listParameter[j].nameVariable ;
            stmp = f->listParameter[j].defaultType ;
            if (stmp.size() > 0 )
                pageWeb << " = " << french2HTML( stmp ) << " " ;
            if (j != m-1)
                pageWeb << ", " ;
            else
                pageWeb << " ) " ;
            }
        if (m == 0)
            pageWeb << " ) " ;
        pageWeb << " <strong> " << f->listAttribut << " </strong> ; </li>" << std::endl ;
        pageWeb << "</div>" << std::endl ;

        m = f->listTag.size() ;
        for(j=0;j<m;j++) {
            f->listTag[j]->generate_pageHTML(&pageWeb,ptr_list_target,ptr_parent ) ;
        }

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl ;
    pageWeb << linkHTML( f->reference(),f->source_file,f->source_file ) <<  "    " ;
    ///stmp = enleve_suffix( f->source_file ) + f->suffix_source ;       /// <--------------------- problème éventuel si c'est un code C    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ///pageWeb << linkHTML( f->reference(),stmp,stmp ) << std::endl ;
    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    for(j=0;j<NB_FINAL_LINE;j++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}











