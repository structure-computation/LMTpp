#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<map>

#include<cmath>
#include"time.h"

using namespace std;

#include "parameter.h"
#include "classe.h"
#include "function.h"
#include "functionmetil.h"
#include "classemetil.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_allclass_tohtml.h"
#include "visitorbloc_namebaseclass.h"
#include "visitorbloc_getstructclassfunction.h"
#include "visitorbloc_getinheritance.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"
#include "listtarget.h"
#include "target.h"
//#include "visitorcommentitem_tohtml.h"

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_template_cpp( ofstream* f, Bloc* b ) {
    int j,m;
    string stmp, stmp2;
    Target* ptr_t;

    m = b->listTemplateParameter.size();
    if (m>0) {
        *f << " <strong> template </strong> &lt; ";
        for(j=0;j<m;j++) {
            *f << " <strong> " << b->listTemplateParameter[j]->type << " </strong> ";
            stmp = b->listTemplateParameter[j]->name;
            if ((ptr_t = ptr_list_target->isName( stmp )) )
                stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp );
            else
                stmp2 = french2HTML( stmp );
            if (b->listTemplateParameter[j]->defaultType.size())
                stmp2 +=  " = " + b->listTemplateParameter[j]->defaultType;
            if (j != m-1)
                *f << stmp2 << ",";
            else
                *f << stmp2 << " &gt; ";
        }
    }
}

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_typedef( ofstream* f, Bloc* b, bool sommary ) {

    Target* ptr_t;
    string stmp, stmp2,stmp3;
    int i,n,m,j;

    n = b->listTypedef.size();
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> typedef </h3> " << std::endl;
            *f << "<div class=\"sommaire_typedef\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                stmp = b->listTypedef[i].type.name;
                if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                else
                    stmp2 = french2HTML( stmp );
                stmp = b->listTypedef[i].nameVariable;
                if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp3 = linkHTML( b->reference(), ptr_t->reference(),stmp );
                else
                    stmp3 = french2HTML( stmp );
                *f << "<li> " << stmp2 << "  &#x21D4  " << stmp3 << " </li>"  << std::endl;
            }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
        else {
            *f << "<div class=\"description_typedef\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                m = b->listTypedef[i].listTag.size();
                if (m>0) {
                    *f <<  "<li> <tt> typedef ";
                    stmp = b->listTypedef[i].type.name;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                    else
                        stmp2 = french2HTML( stmp );
                    stmp = b->listTypedef[i].nameVariable;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp3 = linkHTML( b->reference(), ptr_t->reference(),stmp );
                    else
                        stmp3 = french2HTML( stmp );
                    *f << stmp2 << "  &#x21D4 " << stmp3 << " ";
                    *f << "</tt> </li>" << std::endl;
                    for(j=0;j<m;j++) 
                        b->listTypedef[i].listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
                }
            }
            *f << "<ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
    }
}

/// pour du code C++
void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_sub_class_struct_function( ofstream* f, Bloc* b, TypeDisplayName t ) {

    VisitorBloc_getStruct_Class_Function visi;
    string stmp, stmp2, stmp3;
    int i,n,m,j;
    Target* ptr_t;
    vector<Function*> list_method;
    vector<Classe*> list_subClass;
    vector<Struct*> list_subStruct;

    /// rangement dans les listes précédentes
    n = b->list_subType_function.size();
//     for(i=0;i<n;i++) {
//         b->list_subType_function[i]->exec( &visi );
//         if (visi.isClass)
//             list_subClass.push_back(b->list_subType_function[i]);
//         else {
//             if (visi.isStruct)
//                 list_subStruct.push_back(b->list_subType_function[i]);
//             else {
//                 if (visi.isFunction)
//                     list_method.push_back(b->list_subType_function[i]);
//             }
//         }
//     }
    for(i=0;i<n;i++) {
        b->list_subType_function[i]->exec( &visi );
        if (visi.pc)
            list_subClass.push_back(visi.pc);
        else {
            if (visi.ps)
                list_subStruct.push_back(visi.ps);
            else {
                if (visi.pf)
                    list_method.push_back(visi.pf);
            }
        }
    }
    
    if (list_subStruct.size()+list_subClass.size()) {
        /// i ly a des classes ou struct
        *f <<  "<h3> sous-classe ou sous-struct </h3> " << std::endl;
        switch(t) {
            case Normal : *f << "<div class=\"description_structure\">" << std::endl; break;
            case Link   : *f << "<div class=\"sommaire_structure\">" << std::endl; break;
            case Anchor : *f << "<div class=\"description_structure\">" << std::endl; break;
        }
        *f << "<ul>" << std::endl;
        for(i=0;i<list_subStruct.size();i++) {
            *f << "<li> " << list_subStruct[i]->portee << " ";
            generate_stream_HTML_for_template_cpp(f,list_subStruct[i]);
            *f << " <strong> struct </strong> ";
            switch( t ) {
                case Normal : 
                    *f << french2HTML( list_subStruct[i]->name.name );
                    *f << " </li> ";
                    break;
                case Link   :
                    *f << link_fragmentHTML( list_subStruct[i]->name.name );
                    *f << " </li> ";
                    break;
                case Anchor : 
                    *f << ancreHTML( list_subStruct[i]->name.name,true );
                    *f << " </li> ";
                    for(j=0;j<list_subStruct[i]->listTag.size();j++) /// affichage des commentaires
                        list_subStruct[i]->listTag[j]->generate_pageHTML( f, ptr_list_target, ptr_parent );
                    break;
            }
        }
        for(i=0;i<list_subClass.size();i++) {
            *f << "<li> " << list_subClass[i]->portee << " ";
            generate_stream_HTML_for_template_cpp(f,list_subClass[i]);
            *f << " <strong> class </strong> ";
            switch(t) {
                case Normal : 
                    *f << french2HTML( list_subClass[i]->name.name );
                    *f << " </li> ";
                    break;
                case Link   :
                    *f << link_fragmentHTML( list_subClass[i]->name.name );
                    *f << " </li> ";
                    break;
                case Anchor : 
                    *f << ancreHTML( list_subClass[i]->name.name,true );
                    *f << " </li> ";
                    for(j=0;j<list_subClass[i]->listTag.size();j++) /// affichage des commentaires
                        list_subClass[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
                    break;
            }
        }
        *f << "</ul>" << std::endl;
        *f << "</div>" << std::endl;
    }
    if (list_method.size()) {
        /// il y a des méthodes
        *f <<  "<h3> m&eacute;thodes </h3> " << std::endl;
        switch( t ) {
            case Normal : *f << "<div class=\"description_methode\">" << std::endl; break;
            case Link   : *f << "<div class=\"sommaire_methode\">" << std::endl; break;
            case Anchor : *f << "<div class=\"description_methode\">" << std::endl; break;
        }
        *f << "<ul>" << std::endl;
        for(i=0;i<list_method.size();i++) {
            *f << "<li> ";
            generate_stream_HTML_for_function( f, list_method[ i ], t );
            *f << " </li> ";
        }
        *f << "</ul>" << std::endl;
        *f << "</div>" << std::endl;
    }
}

/// même chose que le code c++ équivalent avec les struct en moins
void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_sub_classMetil_functionMetil( ofstream* f, Bloc* b, TypeDisplayName t ) {

    VisitorBloc_getStruct_Class_Function visi;
    string stmp, stmp2, stmp3;
    int i,n,m,j;
    Target* ptr_t;
    vector<FunctionMetil*> list_method;
    vector<ClasseMetil*> list_subClass;

    /// rangement dans les listes précédentes
    n = b->list_subType_function.size();
    for(i=0;i<n;i++) {
        b->list_subType_function[i]->exec( &visi );
        if (visi.pcm)
            list_subClass.push_back(visi.pcm);
        else {
            if (visi.pfm)
                list_method.push_back(visi.pfm);
        }
    }

    if (list_subClass.size()) {
        /// i ly a des classes ou struct
        *f <<  "<h3> sous-classe </h3> " << std::endl;
        switch(t) {
            case Normal : *f << "<div class=\"description_structure\">" << std::endl; break;
            case Link   : *f << "<div class=\"sommaire_structure\">" << std::endl; break;
            case Anchor : *f << "<div class=\"description_structure\">" << std::endl; break;
        }
        *f << "<ul>" << std::endl;
        for(i=0;i<list_subClass.size();i++) {
            *f << "<li> " << list_subClass[i]->portee << " ";
            generate_stream_HTML_for_template_cpp(f,list_subClass[i]);
            *f << " <strong> class </strong> ";
            switch(t) {
                case Normal : 
                    *f << french2HTML( list_subClass[i]->name.name );
                    *f << " </li> ";
                    break;
                case Link   :
                    *f << link_fragmentHTML( list_subClass[i]->name.name );
                    *f << " </li> ";
                    break;
                case Anchor : 
                    *f << ancreHTML( list_subClass[i]->name.name,true );
                    *f << " </li> ";
                    for(j=0;j<list_subClass[i]->listTag.size();j++) /// affichage des commentaires
                        list_subClass[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
                    break;
            }
        }
        *f << "</ul>" << std::endl;
        *f << "</div>" << std::endl;
    }
    
    if ( list_method.size() ) {
        /// il y a des méthodes
        *f <<  "<h3> m&eacute;thodes </h3> " << std::endl;
        switch( t ) {
            case Normal : *f << "<div class=\"description_methode\">" << std::endl; break;
            case Link   : *f << "<div class=\"sommaire_methode\">" << std::endl; break;
            case Anchor : *f << "<div class=\"description_methode\">" << std::endl; break;
        }
        *f << "<ul>" << std::endl;
        for(i=0;i<list_method.size();i++) {
            *f << "<li> ";
            generate_stream_HTML_for_functionMetil( f, list_method[ i ], t );
            *f << "</li> ";
        }
        *f << "</ul>" << std::endl;
        *f << "</div>" << std::endl;
    }
}


/*
void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_method( ofstream* f, Bloc* b, bool sommary ) {

    n = b->list_subType_function.size();
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> m&eacute;thodes </h3> " << std::endl;
            *f << "<div class=\"sommaire_method\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->exec( &visitor_caract_function );
                if (visitor_caract_function.enphase) {
                    *f << "<li> " << b->list_subType_function[i]->portee + " ";
                    m = b->list_subType_function[i]->listTemplateParameter.size();
                    if (m>0) {
                        *f << " <strong> template </strong> &lt; ";
                        for(j=0;j<m;j++) {
                            *f << " <strong> " << b->list_subType_function[i]->listTemplateParameter[j]->type << " </strong> ";
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name;
                            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp );
                            else
                                stmp2 = french2HTML( stmp );
                            if (j != m-1)
                                *f << stmp2 << ",";
                            else
                                *f << stmp2 << " &gt; ";
                        }
                    }
                    stmp = (*visitor_caract_function.ptr_returnType).name;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp );
                    else
                        stmp2 = french2HTML( stmp );
                    *f << stmp2 << "   ";
                    stmp = b->list_subType_function[i]->name.name;
                    *f << link_fragmentHTML( stmp ) << " ( ";
                    ptr_listParameter = visitor_caract_function.ptr_listParameter;

                    ptr_listParameter->display_parameter_to_HTML(f,ptr_list_target,b);
                    *f << " ) ";
//                     if (m == 0)
//                         *f << " ) ";
                    stmp = *visitor_caract_function.ptr_listAttribut;
                    *f << " <strong> " << stmp << " </strong>; </li>" << std::endl;
                }
            }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
        else {
            *f << "<div class=\"description_method\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                b->list_subType_function[i]->exec( &visitor_caract_function );
                if (visitor_caract_function.enphase) {
                    *f << "<li> <tt> " << b->list_subType_function[i]->portee + " ";
                    m = b->list_subType_function[i]->listTemplateParameter.size();
                    if (m>0) {
                        *f << " template  &lt; ";
                        for(j=0;j<m;j++) {
                            *f << " " << b->list_subType_function[i]->listTemplateParameter[j]->type << " ";
                            stmp = b->list_subType_function[i]->listTemplateParameter[j]->name;
                            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
                            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                                stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                            else
                                stmp2 = french2HTML( stmp );
                            if (j != m-1)
                                *f << stmp2 << ",";
                            else
                                *f << stmp2 << " &gt; ";
                        }
                    }
                    stmp = (*visitor_caract_function.ptr_returnType).name;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                    else
                        stmp2 = french2HTML( stmp );
                    *f << stmp2 << "   ";
                    stmp = b->list_subType_function[i]->name.name;
                    *f << ancreHTML( stmp,true ) << " ( ";
                    ptr_listParameter = visitor_caract_function.ptr_listParameter;
                    m = (*ptr_listParameter).size();
                    for(j=0;j<m;j++) {
                        stmp = (*ptr_listParameter)[j].type.name;
                        if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                            stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                        else
                            stmp2 = french2HTML( stmp );
                        *f << " " <<  (*ptr_listParameter)[j].listAttribut << " " << stmp2 << " ";
                        *f << (*ptr_listParameter)[j].nameVariable;
                        stmp = (*ptr_listParameter)[j].defaultType;
                        if (stmp.size() > 0 ) {
                            *f << " = " << french2HTML( stmp ) << " ";
                        }
                        if (j != m-1)
                            *f << ", ";
                        else
                            *f << " ) ";
                    }
                    if (m == 0)
                        *f << " ) ";
                    stmp = *visitor_caract_function.ptr_listAttribut;
                    *f << " " << stmp << "; </tt> </li>" << std::endl;
                    m = b->list_subType_function[i]->listTag.size();
                    for(j=0;j<m;j++) 
                        b->list_subType_function[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
                }
            }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
    }
}*/

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_property( ofstream* f, ClasseMetil* c, bool sommary ) {

    int i,n,j,m;
    string stmp;
    string stmp2;
    Target* ptr_t;

    n = c->listProperty.size();
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> propri&eacute;t&eacute;s </h3> " << std::endl;
            *f << "<div class=\"sommaire_propriete\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                *f << "<li> <tt> property </tt> ";
                stmp = c->listProperty[i].type.name;
                if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp2 = linkHTML( c->reference(), ptr_t->reference(), stmp );
                else
                    stmp2 = french2HTML( stmp );
                *f << stmp2 << "  </li> " << std::endl;
            }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
        else {
            *f << "<div class=\"description_propriete\">" << std::endl;
            *f << "<ul>" << std::endl;
            for(i=0;i<n;i++) {
                *f << "<li> <tt> property </tt> ";
                stmp = c->listProperty[i].type.name;
                if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                    stmp2 = linkHTML( c->reference(), ptr_t->reference(), stmp );
                else
                    stmp2 = french2HTML( stmp );
                *f << stmp2 << "  </li> " << std::endl;
                m = c->listProperty[i].listTag.size();
                for(j=0;j<m;j++) 
                    c->listProperty[i].listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
            }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
    }
}

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_attribut( ofstream* f, Bloc* b, bool sommary ) {

    int i,n,j,m;
    string stmp;
    string stmp2;
    Target* ptr_t;

    n = b->listMember.size();
    if (n>0) {
        if (sommary) {
            *f <<  "<h3> attributs </h3> " << std::endl;
            *f << "<div class=\"sommaire_attribut\">" << std::endl;
            *f << "<ul>" << std::endl;
                for(i=0;i<n;i++) {
                    stmp = b->listMember[i].listAttribut;
                    *f << "<li> " << " <strong> " << stmp << " </strong> ";
                    stmp = b->listMember[i].type.name;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                    else
                        stmp2 = french2HTML( stmp );
                    *f << stmp2 << "  ";
                    stmp = b->listMember[i].nameVariable;
                    *f << link_fragmentHTML( stmp ) << " ";
                    if ( b->listMember[i].defaultType.size() >0 ) {
                        stmp = b->listMember[i].defaultType;
                        if (b->listMember[i].op.size())
                            *f << " " <<  b->listMember[i].op << " " << french2HTML( stmp ) << " </li> " << std::endl;
                        else
                            *f << " = " << french2HTML( stmp ) << " </li> " << std::endl;
                    } else
                        *f << "; </li> " << std::endl;

                }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
        else {
            *f << "<div class=\"description_attribut\">" << std::endl;
            *f << "<ul>" << std::endl;
                for(i=0;i<n;i++) {
                    stmp = b->listMember[i].listAttribut;
                    *f << "<li> " << stmp << " ";
                    stmp = b->listMember[i].type.name;
                    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                        stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
                    else
                        stmp2 = french2HTML( stmp );
                    *f << stmp2 << "  ";
                    stmp = b->listMember[i].nameVariable;
                    *f << ancreHTML( stmp,true ) << " ";
                    if ( b->listMember[i].defaultType.size() >0 ) {
                        stmp = b->listMember[i].defaultType;
                        if (b->listMember[i].op.size())
                            *f << " " << b->listMember[i].op << " " << french2HTML( stmp ) << " </tt> </li> " << std::endl;
                        else
                            *f << " = " << french2HTML( stmp ) << " </tt> </li> " << std::endl;
                    } else
                        *f << "; </li> " << std::endl;
                    m = b->listMember[i].listTag.size();
                    for(j=0;j<m;j++) 
                        b->listMember[i].listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
                }
            *f << "</ul>" << std::endl;
            *f << "</div>" << std::endl;
        }
    }
}

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_inheritance( ofstream* f, Bloc* b ) {

    int n,i;
    string stmp, stmp2;
    VisitorBloc_GetInheritance visitor_getInheritance;
    Target* ptr_t;
    ListParameter* ptr_listParameter;

    b->exec( &visitor_getInheritance );
    if (not(visitor_getInheritance.ptr_listHerited))
        return; /// pas d'héritage

    ptr_listParameter = visitor_getInheritance.ptr_listHerited;
    n = ptr_listParameter->size();

    if (n) {
        *f <<  "<h3> H&eacute;rite de </h3> " << std::endl;
        *f << "<ul name=\"herited\" >" << std::endl;
        for(i=0;i<n;i++) {
            stmp = (*ptr_listParameter)[i].type.name;
            //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
            if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
                stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
            else
                stmp2 = french2HTML( stmp );
            *f << "<li> <strong>" << (*ptr_listParameter)[i].listAttribut << " </strong>" << "   " <<  stmp2 << " </li>" << std::endl;
        }
        *f << "</ul>" << std::endl;
    }
}

// void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_template_cpp( ofstream* f, Bloc* b ) {
//     int n,i;
//     string stmp;
//     string stmp2;
//     Target* ptr_t;
// 
//     n = b->listTemplateParameter.size();
//     if (n>0) {
//         *f <<  "<br><strong> Param&egrave;tre template : </strong> " << std::endl;
//         //pageWeb << "<ul class=\"parameter_template\" >" << std::endl;
//         for(i=0;i<n;i++) {
//             //pageWeb << "<li> <tt> " << b->listTemplateParameter[i]->type << " </strong> ";
//             stmp = b->listTemplateParameter[i]->name;
//             if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
//                 stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
//             else
//                 stmp2 = french2HTML( stmp );
//             *f << stmp2 << " ";
//             stmp = b->listTemplateParameter[i]->defaultType;
//             if (stmp.size() >0) {
//                 //if (ptr_VisitorBloc_NameBaseClass->isNameBaseClass( stmp ))
//                 if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
//                     stmp2 = linkHTML( b->reference(), ptr_t->reference(), stmp );
//                 else
//                     stmp2 = french2HTML( stmp );
//                 *f << " = " << stmp2  /* << " </li>"    << std::endl */;
//                 if (i != n-1)
//                     *f << " , ";
//                 else
//                     *f << " . " << endl;
//             }
//             else {
//                 if (i != n-1)
//                     *f << " , ";
//                 else
//                     *f << " . " << endl;
//             }
//         }
//     }    
// }

/// c'est pour du code C++
void VisitorBloc_AllClass_toHTML::generate_page_HTML_for_class_or_struct( const string& type_block, Bloc* b ) {

    int n,i;
    string stmp;

    //stmp = b->path + french2webID( b->name.name ) + ".html";
    stmp = b->reference();
    ofstream pageWeb( stmp.c_str() ,ios::out);

    stmp = type_block + ' ' + french2HTML( b->name.name );

    generate_header( b, (*ptr_tree)["root"], pageWeb, stmp );

    pageWeb << "<hr />" << std::endl;
    
    pageWeb << "<div class=\"table_des_matieres\">" << std::endl;
    
    /// namespace
    if (b->_namespace.size()) {
        pageWeb << "<br> <strong>  namespace : </strong> " << b->_namespace << " <br> " << std::endl;
    }

    /// les héritages
    generate_stream_HTML_for_inheritance(&pageWeb,b);

    /// les paramètres template
    generate_stream_HTML_for_template_cpp(&pageWeb,b);
    
    /// typedef de la classe
    generate_stream_HTML_for_typedef( &pageWeb,b,true );

    /// sous-type classe, struct ou méthode de la classe
    generate_stream_HTML_for_sub_class_struct_function(&pageWeb,b,Link);

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,b,true);


    pageWeb << "<br>" << std::endl;
    pageWeb << "<hr />" << std::endl;
    pageWeb <<  "<h2> Description </h2> " << std::endl;
    pageWeb << "<div class=\"description_structure\">" << std::endl;

    n = b->listTag.size();
    if (n>0) {
        for(i=0;i<n;i++) {
            b->listTag[i]->generate_pageHTML(&pageWeb,ptr_list_target,ptr_parent );
        }
    }
    pageWeb << "</div>";
    /// typedef de la classe
    generate_stream_HTML_for_typedef( &pageWeb,b,false );

    /// sous-type classe, struct ou méthode de la classe
    generate_stream_HTML_for_sub_class_struct_function(&pageWeb,b,Anchor);

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,b,false);

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl;
    pageWeb << linkHTML( b->reference(),b->source_file,b->source_file ) <<  "    ";
    pageWeb << "</p>" << std::endl;

    feetPage(pageWeb);
}

// void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_classMetil( ofstream* f, Bloc* b, bool sommary ) {
// 
//     VisitorBloc_GetCaracteristicClass    visitor_caract_class;
//     string stmp, stmp2, stmp3;
//     int i,n,m,j;
//     Target* ptr_t;
// 
//     n = b->list_subType_function.size();
//     if (n>0) {
//         if (sommary) {
//             *f <<  "<h3> sous-classe ou sous-struct </h3> " << std::endl;
//             *f << "<div class=\"sommaire_structure\">" << std::endl;
//             *f << "<ul>" << std::endl;
//             for(i=0;i<n;i++) {
//                 b->list_subType_function[i]->exec( &visitor_caract_class );
//                 if (visitor_caract_class.ptr_listHerited ) {
//                     *f << "<li> " << b->list_subType_function[i]->portee + " ";
//                     m = b->list_subType_function[i]->listTemplateParameter.size();
//                     if (m>0) {
//                         *f << " <strong> template </strong> &lt; ";
//                         for(j=0;j<m;j++) {
//                             *f << " <strong> " << b->list_subType_function[i]->listTemplateParameter[j]->type << " </strong> ";
//                             stmp = b->list_subType_function[i]->listTemplateParameter[j]->name;
//                             if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
//                                 stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp );
//                             else
//                                 stmp2 = french2HTML( stmp );
//                             if (b->list_subType_function[i]->listTemplateParameter[j]->defaultType.size() > 0)
//                                 stmp2 +=  " = " + b->list_subType_function[i]->listTemplateParameter[j]->defaultType;
//                             if (j != m-1)
//                                 *f << stmp2 << ",";
//                             else
//                                 *f << stmp2 << " &gt; ";
//                         }
//                     }
//                     *f << " <strong>" << " class "  << "</strong> " << link_fragmentHTML( b->list_subType_function[i]->name.name ) <<  " </li>" << std::endl;
//                 }
//             }
//             *f << "</ul>" << std::endl;
//             *f << "</div>" << std::endl;
//         }
//         else {
//             /// même chose mais avec les commentaires
//             *f << "<div class=\"description_structure\">" << std::endl;
//             *f << "<ul>" << std::endl;
//             for(i=0;i<n;i++) {
//                 b->list_subType_function[i]->exec( &visitor_caract_class );
//                 if (visitor_caract_class.ptr_listHerited ) {
//                     *f << "<li> <tt> " << b->list_subType_function[i]->portee + " ";
//                     m = b->list_subType_function[i]->listTemplateParameter.size();
//                     if (m>0) {
//                         *f << " template &lt; ";
//                         for(j=0;j<m;j++) {
//                             *f << " " << b->list_subType_function[i]->listTemplateParameter[j]->type << " ";
//                             stmp = b->list_subType_function[i]->listTemplateParameter[j]->name;
//                             if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
//                                 stmp2 = linkHTML( b->reference(), ptr_t->reference(),stmp );
//                             else
//                                 stmp2 = french2HTML( stmp );
//                             if (b->list_subType_function[i]->listTemplateParameter[j]->defaultType.size() > 0)
//                                 stmp2 +=  " = " + b->list_subType_function[i]->listTemplateParameter[j]->defaultType;
//                             if (j != m-1)
//                                 *f << stmp2 << ",";
//                             else
//                                 *f << stmp2 << " &gt; ";
//                         }
//                     }
//                     *f << " class " << ancreHTML( b->list_subType_function[i]->name.name,true ) <<  " </tt> </li>" << std::endl;
//                     m = b->list_subType_function[i]->listTag.size();
//                     for(j=0;j<m;j++) 
//                         b->list_subType_function[i]->listTag[j]->generate_pageHTML(f,ptr_list_target,ptr_parent );
//                 }
//             }
//             *f << "</ul>" << std::endl;
//             *f << "</div>" << std::endl;
//         }
//     }
// }

void VisitorBloc_AllClass_toHTML::exec( ClasseMetil* c ) {

    int n,i;
    string stmp;

    stmp = c->reference();
    ofstream pageWeb( stmp.c_str() ,ios::out);

    stmp = "Class " + french2HTML( c->name.name );

    generate_header( c, (*ptr_tree)["root"], pageWeb, stmp );

    pageWeb << "<hr />" << std::endl;

    pageWeb << "<div class=\"table_des_matieres\">" << std::endl;

    /// namespace
    if (c->_namespace.size()) {
        pageWeb << "<br> <strong>  namespace : </strong> " << c->_namespace << " <br> " << std::endl;
    }

    /// les héritages
    generate_stream_HTML_for_inheritance(&pageWeb,c);

    /// les paramètres template
    generate_stream_HTML_for_template_cpp(&pageWeb,c);

    /// propriétés de la classe
    generate_stream_HTML_for_property(&pageWeb,c,true);

    /// sous-type classe et méthode de la classe
    generate_stream_HTML_for_sub_classMetil_functionMetil(&pageWeb,c,Link);

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,c,true);


    pageWeb << "<br>" << std::endl;
    pageWeb << "<hr />" << std::endl;
    pageWeb <<  "<h2> Description </h2> " << std::endl;
    pageWeb << "<div class=\"description_structure\">" << std::endl;

    n = c->listTag.size();
    if (n>0) {
        for(i=0;i<n;i++) {
            c->listTag[i]->generate_pageHTML(&pageWeb,ptr_list_target,ptr_parent );
        }
    }
    /// propriétés de la classe
    generate_stream_HTML_for_property(&pageWeb,c,false);
    
    /// sous-type classe et méthode de la classe
    generate_stream_HTML_for_sub_classMetil_functionMetil(&pageWeb,c,Anchor);

    /// membre de la classe
    generate_stream_HTML_for_attribut( &pageWeb,c,false);

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl;
    pageWeb << linkHTML( c->reference(),c->source_file,c->source_file ) <<  "    ";
    pageWeb << "</p>" << std::endl;

    feetPage(pageWeb);
}

void VisitorBloc_AllClass_toHTML::exec( Classe* c ) {

    generate_page_HTML_for_class_or_struct( "class",c );
}

void VisitorBloc_AllClass_toHTML::exec( Struct* s ) {

    generate_page_HTML_for_class_or_struct( "struct",s );
}

void VisitorBloc_AllClass_toHTML::exec( Function* f ) {

    int j,m;
    Target* ptr_t;
    string stmp;
    string stmp2;
    string stmp3;

    stmp = f->reference();
    ofstream pageWeb( stmp.c_str() ,ios::out);
    stmp = "fonction " + french2HTML( f->name.name );

    generate_header( f, (*ptr_tree)["root"], pageWeb, stmp );

    generate_stream_HTML_for_function(&pageWeb,f,Normal);
    
    pageWeb << "</div>" << std::endl;

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl;
    pageWeb << linkHTML( f->reference(),f->source_file,f->source_file ) <<  "    ";
    //pageWeb << linkHTML( f->reference(),stmp,stmp ) << std::endl;
    pageWeb << "</p>" << std::endl;
    feetPage(pageWeb);
}

void VisitorBloc_AllClass_toHTML::exec( FunctionMetil* f ) {
    
    int j,m;
    Target* ptr_t;
    string stmp;

    stmp = f->reference();
    ofstream pageWeb( stmp.c_str() ,ios::out);
    stmp = "fonction " + french2HTML( f->name.name );

    generate_header( f, (*ptr_tree)["root"], pageWeb, stmp );

    generate_stream_HTML_for_functionMetil(&pageWeb,f,Normal);
    
    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl;
    pageWeb << linkHTML( f->reference(),f->source_file,f->source_file ) <<  "    ";
    //pageWeb << linkHTML( f->reference(),stmp,stmp ) << std::endl;
    pageWeb << "</p>" << std::endl;
    feetPage(pageWeb);
}

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_function( ofstream* o, Function* f, TypeDisplayName t ) {

    int j,m;
    string stmp, stmp2;
    Target* ptr_t;
    
    *o << "<div class=\"fonction\">" << std::endl;
    *o << f->portee << " ";
    m = f->listTemplateParameter.size();
    if (m>0) {
        *o << " <strong> template </strong> &lt; ";
        for(j=0;j<m;j++) {
            *o << " <strong> " << f->listTemplateParameter[j]->type << " </strong> ";
            stmp = f->listTemplateParameter[j]->name;
            if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
                stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp );
            }
            else
                stmp2 = french2HTML( stmp );
            if (j != m-1)
                *o << stmp2 << ",";
            else
                *o << stmp2 << " &gt; ";
        }
    }
    //*o << " <strong> " << f->listAttribut << " </strong> " << std::endl;
    stmp = f->returnType.name;
    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
        stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp );
        //cerr << " f->returnType = " << stmp << " de la fonction " << f->name.name << endl;
    } else {
        //cerr << " f->returnType ooouiiiiiiiiiiiiiiiii= " << stmp << " de la fonction " << f->name.name << endl;
        stmp2 = french2HTML( stmp );
    }
    *o << stmp2 << " ";
    //cerr << " f->reference() = " << f->reference() << endl;
    switch(t) {
        case Normal : *o << french2HTML( f->name.name ); break;
        case Link   : *o << link_fragmentHTML( f->name.name ); break;
        case Anchor : *o << ancreHTML( f->name.name,true ); break;
    }
    *o << " ( ";
    f->listParameter.display_parameter_to_HTML(o,ptr_list_target,f);
    *o << " ) ";
    if (f->listAttribut.size())
        *o << " <strong> " << f->listAttribut << " </strong> " << std::endl;

    if ((t == Normal) or (t == Anchor)) {
        m = f->listTag.size();
        for(j=0;j<m;j++) {
            f->listTag[j]->generate_pageHTML(o,ptr_list_target,ptr_parent );
        }
    }
    *o << "</div>" << std::endl;
}

void VisitorBloc_AllClass_toHTML::generate_stream_HTML_for_functionMetil( ofstream* o, FunctionMetil* f, TypeDisplayName t ) {
    int j,m;
    string stmp, stmp2;
    Target* ptr_t;
    
    *o << "<div class=\"fonction\">" << std::endl;
    *o << f->portee << " ";
    m = f->listTemplateParameter.size();
    if (m>0) {
        *o << " <strong> template </strong> &lt; ";
        for(j=0;j<m;j++) {
            *o << " <strong> " << f->listTemplateParameter[j]->type << " </strong> ";
            stmp = f->listTemplateParameter[j]->name;
            if ( (ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
                stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp );
            }
            else
                stmp2 = french2HTML( stmp );
            if (j != m-1)
                *o << stmp2 << ",";
            else
                *o << stmp2 << " &gt; ";
        }
    }
    *o << " <strong> " << f->listAttribut << " </strong> " << std::endl;
    stmp = f->returnType.name;
    if ((ptr_t = ptr_list_target->isName( stmp )) != 0 ) {
        stmp2 = linkHTML( f->reference(), ptr_t->reference(), stmp );
    } else
        stmp2 = french2HTML( stmp );
    *o << stmp2 << "   ";
    switch(t) {
        case Normal : *o << french2HTML( f->name.name ); break;
        case Link   : *o << link_fragmentHTML( f->name.name ); break;
        case Anchor : *o << ancreHTML( f->name.name,true ); break;
    }
    *o << " ( ";
    f->listParameter.display_parameter_to_HTML(o,ptr_list_target,f);
    //if (f->listParameter.size() == 0)
    *o << " ) " << std::endl;
    if (f->condition.size())
        *o << " <strong> when </strong> " << f->condition << std::endl;
    if ((f->default_pertinence > 1e-5) or ((f->default_pertinence < -1e-5)))
        *o << " <strong> pertinence </strong> " << f->default_pertinence << std::endl;

    if ((t == Normal) or (t == Anchor)) {
        m = f->listTag.size();
        if (t == Anchor)
            *o << " </strong> ";
        for(j=0;j<m;j++) {
            f->listTag[j]->generate_pageHTML(o,ptr_list_target,ptr_parent );
        }
        if (t == Anchor)
            *o << " </strong> ";
    }
    *o << "</div>" << std::endl;
}



