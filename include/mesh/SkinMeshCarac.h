#ifndef SKIN_CARAC_H
#define SKIN_CARAC_H

namespace LMT {

/**
    Mesh<SkinMeshCarac<TM> > -> type pour stocker des maillages de type enfants dans TM
*/
template<class TM>
struct SkinMeshCarac {
    typedef typename TM::Carac Carac;
    typedef typename Carac::Tpos Tpos;
    static const unsigned dim = Carac::dim;
    typedef typename Carac::Pvec Pvec;
    typedef typename Carac::NodalStaticData NodalStaticData;
    typedef typename Carac::GlobalStaticData GlobalStaticData;
    //typedef typename Carac::TNode TNode;
    //typedef typename Carac::EA EA;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    template<unsigned nvi_to_subs,unsigned num_sub_element> struct ElementChoice<nvi_to_subs,0,num_sub_element,0> {
        typedef typename Carac::template ElementChoice<nvi_to_subs+1,1,num_sub_element>::NE NE;
        typedef typename Carac::template ElementChoice<nvi_to_subs+1,1,num_sub_element>::BE BE;
        typedef typename Carac::template ElementChoice<nvi_to_subs+1,1,num_sub_element>::TData TData;
    };
};

}

#endif // SKIN_CARAC_H
