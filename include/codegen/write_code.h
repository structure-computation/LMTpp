#ifndef WRITE_CODE_H
#define WRITE_CODE_H

#include "ex.h"

namespace Codegen {

class Write_code_language;

/*!

La classe Write_code permet de générer le code C++ du corps d'une fonction. On ajoute du code à l'aide de la fonction add() puis à la fin on appelle la fonction to_string() qui renvoie le code dans une chaine de caractères. 
Voici un exemple de code :
\code C/C++
    int main() {
        Write_code wc("float");
        Ex pi(3.14),R,S,tmp;
        wc.add(pi,"pi");
        S = pi*R*R;
        tmp = R / 2 ;
        wc.add(S,"S");
        for(i=0;i<10;i++) {
            wc.add(tmp,"R",Write_code.Set);
            wc.add( S,"S",Write_code.Add);
        }
        std::cout wc.to_string() std::endl;
    }


<strong> REMARQUE : </strong> place "Return" var at the end of operations

\friend raphael.pasquier@lmt.ens-cachan.fr
\friend hugo.leclerc@lmt.ens-cachan.fr
\relates Ex
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
    unsigned node_count() const;
    
    std::string to_asm();
    std::string asm_caller( std::string asm_function_name );
    
    std::vector<Var> lst_var;
    
    void write_graphviz(std::ostream &os);
    void display_graphviz();

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
};

void write_graphviz(const Op *op,std::ostream &os);

};

#endif // WRITE_CODE_H
