//
// C++ Implementation: displayparaview
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "mesh/tetra.h"
#include "mesh/hexa.h"
#include "mesh/wedge.h"
#include "mesh/wedge_15.h"
#include "mesh/triangle_6.h"
#include "mesh/hexa_20.h"
#include "mesh/tetra_10.h"

namespace LMT {

const unsigned NodalElement::nb_nodes;
const unsigned Bar::nb_nodes;
const unsigned Bar_3::nb_nodes;
const unsigned Quad::nb_nodes;
const unsigned Quad_8::nb_nodes;
const unsigned Tetra::nb_nodes;
const unsigned Tetra_10::nb_nodes;
const unsigned Triangle::nb_nodes;
const unsigned Triangle_6::nb_nodes;
const unsigned Wedge::nb_nodes;
const unsigned Wedge_15::nb_nodes;
const unsigned Hexa::nb_nodes;
const unsigned Hexa_20::nb_nodes;

#ifdef PRINT_ALLOC
std::map<std::string,long long> total_allocated;
#endif // PRINT_ALLOC

};
