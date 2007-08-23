#ifndef WRITE_CODE_H
#define WRITE_CODE_H

#include "ex.h"

namespace Codegen {

class Write_code_language;

/**
Ex :
    Write_code wc;
    wc.add( a+b, "toto", Write_code::Declare )
    wc.add( pow(a+b,10), "opza", Write_code::Add )
    cout << wc.to_string() << endl;
Result :
    T toto = a+b;
    T tmp = pow(toto,10);
    opza += toto;
    
TODO : place "Return" var at the end of operations
*/
class Write_code {
public:
    ///
    typedef enum {Declare,Set,Add,Sub,Return} Method;
    ///
    struct Var {
        Ex ex;
        std::string name;
        Method method;
    };
    /// beware : destructor of Write_code will delete cl.
    Write_code(const char *default_type="T",unsigned nb_spaces=4);
    ~Write_code();
    /// add ex to var that has to be calculated.
    /// update nodes and leaves.
    Write_code &add( const Ex &ex, const std::string &name, Method method=Declare );
    std::string to_string();    
    std::vector<Var> lst_var;
    
private:
    struct Node {
        Node():reg(-2) {}
        Ex ex;
        unsigned nb_times_to_be_used;
        unsigned depth;
        int reg;
    };
    struct SortNode {
        bool operator()(const Node *a,const Node *b) const { return a->depth > b->depth; }
    };
    typedef std::map<Ex,Node,Ex::ExMapCmp> Tnodes;
    typedef std::set<Node *> Tleaves;
    Tnodes nodes;
    Tleaves leaves;
    
    std::vector<Node *> node_order;
    
    Write_code_language *wcl;
    
    const Op *set_depth_rec(const Ex &ex,unsigned depth); /// find max depth for each sub nodes ( results in nodes ). Only used via add()
    
    Tleaves::iterator get_next_node();
    std::string ex_to_string(Node &node) const; /// use node_order to get output
    void set_node_order();
    
    void write_graphviz(std::ostream &os);
    void display_graphviz();
};

void write_graphviz(const Op *op,std::ostream &os);

};

#endif // WRITE_CODE_H
