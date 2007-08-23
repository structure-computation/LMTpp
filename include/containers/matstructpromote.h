#ifndef LMT_MATSTRUCT_PROMOTE_H
#define LMT_MATSTRUCT_PROMOTE_H

#include "mat.h"

namespace LMT {

template<class S1,class S2>
struct MatStructPromote { typedef Gen<> T; };

template<class S1>
struct MatStructPromote<S1,S1> { typedef S1 T; };

template<class S1>
struct MatStructPromote<Diag<>,S1> { typedef S1 T; };
template<class S1>
struct MatStructPromote<S1,Diag<> > { typedef S1 T; };

template<>
struct MatStructPromote<AntiSym<>,Diag<> > { typedef Gen<> T; };
template<>
struct MatStructPromote<Diag<>,AntiSym<> > { typedef Gen<> T; };

}


#endif // LMT_MATSTRUCT_PROMOTE_H
