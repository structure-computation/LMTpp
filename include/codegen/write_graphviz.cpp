#include "write_graphviz.h"
#include <sstream>

using namespace std;

namespace Codegen {

void write_graphviz(const Ex &op,ostream &os) {
  std::set<Ex,Ex::ExMapCmp> lst;
  op.get_sub_nodes(lst);

  os << "digraph popo {" << endl;
  // nodes
  for(set<Ex,Ex::ExMapCmp>::const_iterator iter=lst.begin();iter!=lst.end();++iter)
    os << "  node" << iter->id() << " [ label=\"" << iter->graphviz_repr() << "\" ];" << endl;
  // children
  os << "  edge [ color=\"black\" ]" << endl;
  for(set<Ex,Ex::ExMapCmp>::const_iterator iter=lst.begin();iter!=lst.end();++iter)
    for(unsigned j=0;j<iter->nb_children();++j)
      os << "  node" << iter->id() << " -> node" << iter->child(j).id() << endl;
  // parents
//   os << "  edge [ color=\"red\" ]" << endl;
//   for(set<Ex,Ex::ExMapCmp>::const_iterator iter=lst.begin();iter!=lst.end();++iter)
//     for(unsigned j=0;j<iter->nb_parents();++j)
//       if ( lst.count(iter->parent(j)) )
//         os << "  node" << iter->parent(j).id() << " -> node" << iter->id() << endl;
  os << "}" << endl;
}

};
