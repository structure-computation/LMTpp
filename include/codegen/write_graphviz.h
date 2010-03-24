#ifndef WRITE_GRAPHVIZ_H
#define WRITE_GRAPHVIZ_H

#include "ex.h"

#ifdef METIL_COMP_DIRECTIVE
#pragma src_file write_graphviz.cpp
#endif

namespace Codegen {

void write_graphviz(const Ex &op,std::ostream &os);

};

#endif // WRITE_GRAPHVIZ_H
