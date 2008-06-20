%module codegen
%include "std_map.i"
%{
#include "codegen.h"
#include <math.h>
#include <cmath>
#include <sstream>
namespace Codegen {
    inline double heavyside(double a) { return (a>=0); }
    inline double heavyside_if(double a) { return (a>=0); }
    inline double heaviside(double a) { return (a>=0); }
    inline double heaviside_if(double a) { return (a>=0); }
    inline double dirac(double a) { return (a==0); }
    inline double sqrt(double a) { return ::sqrt(a); }
    inline double sin(double a) { return ::sin(a); }
    inline double cos(double a) { return ::cos(a); }
    inline double asin(double a) { return ::asin(a); }
    inline double acos(double a) { return ::acos(a); }
    inline double eqz(double a) { return (a==0); }
    inline double sgn(double a) { return (a>0)-(a<0); }
    inline double tan(double a) { return ::tan(a); }
    inline double atan(double a) { return ::atan(a); }
    inline double log(double a) { return ::log(a); }
    inline double exp(double a) { return ::exp(a); }
    inline double abs(double a) { return ::fabs(a); }
    inline double max(double a,double b) { return std::max(a,b); }
    inline double min(double a,double b) { return std::min(a,b); }
    inline double atan2(double a,double b) { return std::atan2(a,b); }
    inline int max(int a,int b) { return std::max(a,b); }
    inline int mini(int a,int b) { return std::min(a,b); }
};


%}

%include "std_pair.i"
%include "std_string.i"
%include "std_vector.i"
namespace std {
    %template(UnsignedVector)    vector<unsigned>;
    %template(DoubleVector)      vector<double>;
}
%include "constraints.i"

namespace Codegen {

double heavyside(double a);
double heaviside(double a);
double dirac(double a);
double sqrt(double NONNEGATIVE);
double sin(double);
double cos(double);
double acos(double);
double asin(double);
double eqz(double);
double sgn(double);
double tan(double);
double atan(double);
double log(double POSITIVE);
double exp(double);
double abs(double);
double max(double,double);
double mini(double,double);
double atan2(double,double);
int max(int a,int b);
int mini(int a,int b);

class Ex {
public:
    Ex();
    Ex(const char *name,const char *texname=NULL);
    Ex(double v);
    ~Ex();
    std::string to_string() const;
    std::string graphviz_repr() const;
    
    bool is_a_symbol() const;
    bool is_a_number() const;
    double get_val() const;
    void set_val(double v);
    bool is_a_function_1() const;
    bool is_a_function_2() const;
    void display_graphviz(const char *filename="tmp.dot") const;
    
    Ex find_discontinuity( const Ex &v ) const;
    
    bool depends_on( const Ex &ex ) const;
    
    bool is_zero() const;
    
    Ex subs(const Ex &a,const Ex &b) const;
    Ex subs(std::map<Codegen::Ex,Codegen::Ex> &m) const;
    
    Ex subs_with_test(const Ex &a,const Ex &b) const;
    Ex subs_with_test(const std::map<Codegen::Ex,Codegen::Ex> &m) const;
    
    Ex diff(const Ex &a) const;
    
    unsigned nb_children() const;
    Ex child(unsigned i) const;
    unsigned nb_parents() const;
    Ex parent(unsigned i) const;
    int id() const { return (int)op; }
    
};

Ex symbol(const char *name,const char *texname=NULL);
Ex number(double val);
Ex number(const char *val);

Ex heavyside(const Ex &a);
Ex heavyside_if(const Ex &a);
Ex heaviside(const Ex &a);
Ex heaviside_if(const Ex &a);
Ex dirac(const Ex &a);
Ex sqrt(const Ex &a);
Ex sin(const Ex &a);
Ex cos(const Ex &a);
Ex asin(const Ex &a);
Ex acos(const Ex &a);
Ex eqz(const Ex &a);
Ex sgn(const Ex &a);
Ex tan(const Ex &a);
Ex atan(const Ex &a);
Ex log(const Ex &a);
Ex exp(const Ex &a);
Ex abs(const Ex &a);
Ex max(const Ex &a,const Ex &b);
Ex max(const Ex &a,double b);
Ex max(double a,const Ex &b);
Ex mini(const Ex &a,const Ex &b);
Ex mini(const Ex &a,double b);
Ex mini(double a,const Ex &b);

Ex atan2(const Ex &a,const Ex &b);
Ex atan2(const Ex &a,double b);
Ex atan2(double a,const Ex &b);

Ex integration(const Ex &expr,const Ex &v,const Ex &beg,const Ex &end,unsigned max_poly_order=5);

}

namespace std {
    %template(EM) map<Codegen::Ex, Codegen::Ex>;
    %template(PEX) pair<Codegen::Ex, Codegen::Ex>;
}

namespace Codegen {

%extend Ex {
    Ex __add__(const Ex &other) const { return *self + other; }
    Ex __add__(double other) { return *self + other; }
    Ex __radd__(double other) { return other + *self; }
    
    Ex __sub__(const Ex &other) { return *self - other; }
    Ex __sub__(double other) { return *self - other; }
    Ex __rsub__(double other) { return other - *self; }
    
    Ex __mul__(const Ex &other) { return *self * other; }
    Ex __mul__(double other) { return *self * other; }
    Ex __rmul__(double other) { return other * *self; }
    
    Ex __div__(const Ex &other) { return *self / other; }
    Ex __div__(double other) { return *self / other; }
    Ex __rdiv__(double other) { return other / *self; }
    
    Ex __pow__(const Ex &other) { return pow(*self,other); }
    Ex __pow__(double other) { return pow(*self,other); }
    Ex __rpow__(double other) { return pow(other,*self); }

    Ex __neg__() { return - *self; }
    Ex __abs__() { return abs( *self ); }
    
    bool __nonzero__() { return not (self->is_a_number() and self->get_val()==0); }
    
    std::string __repr__() const { return self->to_string(); }
    std::string __str__() const { return self->to_string(); }
    
    Ex subs(const Ex &f,double t) const { return self->subs(f,Codegen::number(t)); }
};

// --------------------------------
class ExVector {
public:
    ExVector(unsigned size=0);
    ExVector(const Ex &e1);
    ExVector(const Ex &e1,const Ex &e2);
    ExVector(const Ex &e1,const Ex &e2,const Ex &e3);
    ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4,const Ex &e5,const Ex &e6);
    // Ex &operator()(unsigned i);
    // const Ex &operator()(unsigned i) const;
    void push_back(const Ex &ex);
    void resize(unsigned s);
    unsigned size() const;
    std::string to_string() const;
    std::string graphviz_repr() const;
    
    bool is_null() const;
    
    ExVector subs(std::map<Codegen::Ex,Codegen::Ex> &map) const;
    ExVector subs(const Ex &a,const Ex &b) const;
    ExVector diff(const Ex &a) const;
    Ex max() const;
    Ex sum() const;
};
    
%extend ExVector {
    Ex __getitem__(unsigned i) { return (*self)(i); }
    void __setitem__(unsigned i,const Ex &val) { (*self)(i) = val; }
    void __setitem__(unsigned i,double val) { (*self)(i) = val; }
    
    ExVector __add__(const ExVector &other) const { return *self + other; }
    ExVector __add__(const Ex &other) const { return *self + other; }
    ExVector __add__(double other) { return *self + other; }
    ExVector __radd__(double other) { return other + *self; }
    
    ExVector __sub__(const ExVector &other) { return *self - other; }
    ExVector __sub__(const Ex &other) { return *self - other; }
    ExVector __sub__(double other) { return *self - other; }
    ExVector __rsub__(double other) { return other - *self; }
    
    ExVector __mul__(const ExVector &other) { return *self * other; }
    ExVector __mul__(const Ex &other) { return *self * other; }
    ExVector __mul__(double other) { return *self * other; }
    ExVector __rmul__(double other) { return other * *self; }
    ExVector __rmul__(const Ex &other) { return other * *self; }
    
    ExVector __div__(const ExVector &other) { return *self / other; }
    ExVector __div__(const Ex &other) { return *self / other; }
    ExVector __div__(double other) { return *self / other; }
    ExVector __rdiv__(double other) { return other / *self; }
    ExVector __rdiv__(const Ex &other) { return other / *self; }
    
    ExVector __pow__(const ExVector &other) { return pow(*self,other); }
    ExVector __pow__(const Ex &other) { return pow(*self,other); }
    ExVector __pow__(double other) { return pow(*self,other); }
    ExVector __rpow__(double other) { return pow(other,*self); }

    ExVector __neg__() { return - *self; }
    ExVector __abs__() { return abs( *self ); }
    
    ExVector __copy__() { return *self; }
    ExVector clone() { return *self; }
    
    std::string __repr__() const { return self->to_string(); }
    std::string __str__() const { return self->to_string(); }
    
    ExVector subs(const Ex &f,double t) const { return self->subs(f,Codegen::number(t)); }
};
    
ExVector sqrt(const ExVector &a);
ExVector abs(const ExVector &a);
ExVector heavyside(const ExVector &a);
ExVector heavyside_if(const ExVector &a);
ExVector heaviside(const ExVector &a);
ExVector heaviside_if(const ExVector &a);
ExVector eqz(const ExVector &a);
ExVector sin(const ExVector &a);
ExVector cos(const ExVector &a);
ExVector sgn(const ExVector &a);
ExVector tan(const ExVector &a);
ExVector log(const ExVector &a);
//ExVector exp(const ExVector &a);
ExVector neg(const ExVector &a);
ExVector asin(const ExVector &a);
ExVector acos(const ExVector &a);
ExVector atan(const ExVector &a);
    
ExVector pos_part(const ExVector &a);
ExVector neg_part(const ExVector &a);

ExVector max(const ExVector &a,const ExVector &b);
ExVector max(const ExVector &a,const Ex &b);
ExVector max(const Ex &a,const ExVector &b);

ExVector mini(const ExVector &a,const ExVector &b);
ExVector mini(const ExVector &a,const Ex &b);
ExVector mini(const Ex &a,const ExVector &b);

Ex dot(const ExVector &a,const ExVector &b);

Ex norm(const ExVector &a,double additional_val=0.0);
ExVector vect_prod(const ExVector &v1,const ExVector &v2);

// --------------------------------
class ExMatrix {
public:
    ExMatrix(unsigned nb_rows=0,unsigned nb_cols=0);
    ExMatrix copy() const;
    
    Ex &operator()(unsigned i,unsigned j);
    const Ex &operator()(unsigned i,unsigned j) const;
    unsigned nb_rows() const;
    unsigned nb_cols() const;
    std::string to_string(unsigned nb_spaces=0) const;
    std::string graphviz_repr() const;
    
    bool is_null() const;
    bool depends_on(const Ex &ex) const;
    
    ExMatrix subs(std::map<Codegen::Ex,Codegen::Ex> &map) const;
    ExMatrix subs(const Ex &a,const Ex &b) const;
    ExMatrix diff(const Ex &a) const;
    
    void resize( unsigned r, unsigned c );
    
    Ex max() const;
    Ex trace() const;
    ExMatrix transpose() const;
    Ex determinant() const;
    ExMatrix ldl() const;
    ExVector solve_using_ldl( const ExVector &b ) const;
    ExVector solve( const ExVector &v ) const;
    ExVector solve( const ExVector &v, const Ex &det ) const;
    ExVector solve_regular_or_not( const ExVector &v ) const;
    ExVector solve_with_one_at( unsigned index, const ExVector &v, bool zero_at_the_beginning = false ) const;
    ExVector find_eigen_values_sym() const;
    ExMatrix find_eigen_vectors_sym( const ExVector &eigen_values ) const;
    ExMatrix find_eigen_vectors_sym_bis() const;
    ExVector row(unsigned c) const;
    ExVector col(unsigned c) const;
    ExVector diag() const;
    ExMatrix without_col(unsigned col) const;
    ExMatrix without_row(unsigned row) const;
    ExMatrix inverse() const;
    ExMatrix operator-() const;
    void add_col( const ExVector &v );
    void add_row( const ExVector &v );
};
    
%extend ExMatrix {
    Ex __getitem__(std::vector<unsigned> i) { assert(i.size()==2); return (*self)(i[0],i[1]); }
    void __setitem__(std::vector<unsigned> i,const Ex &val) { assert(i.size()==2); (*self)(i[0],i[1]) = val; }
    void __setitem__(std::vector<unsigned> i,double val) { assert(i.size()==2); (*self)(i[0],i[1]) = val; }
    
    ExMatrix __add__(const ExMatrix &other) const { return *self + other; }
    ExMatrix __add__(const Ex &other) const { return *self + other; }
    ExMatrix __add__(double other) { return *self + other; }
    ExMatrix __radd__(double other) { return other + *self; }
    
    ExMatrix __sub__(const ExMatrix &other) { return *self - other; }
    ExMatrix __sub__(const Ex &other) { return *self - other; }
    ExMatrix __sub__(double other) { return *self - other; }
    ExMatrix __rsub__(double other) { return other - *self; }
    
    ExVector __mul__(const ExVector &other) { return *self * other; }
    /*     ExMatrix __mul__(const ExMatrix &other) { return *self * other; } */
    ExMatrix __mul__(const Ex &other) { return *self * other; }
    ExMatrix __mul__(double other) { return *self * other; }
    ExMatrix __rmul__(double other) { return other * *self; }
    ExMatrix __rmul__(const Ex &other) { return other * *self; }
    
    ExMatrix __div__(const ExMatrix &other) { return *self / other; }
    ExMatrix __div__(const Ex &other) { return *self / other; }
    ExMatrix __div__(double other) { return *self / other; }
    ExMatrix __rdiv__(double other) { return other / *self; }
    
    ExMatrix __pow__(const ExMatrix &other) { return pow(*self,other); }
    ExMatrix __pow__(const Ex &other) { return pow(*self,other); }
    ExMatrix __pow__(double other) { return pow(*self,other); }
    ExMatrix __rpow__(double other) { return pow(other,*self); }

    ExMatrix __neg__() { return - *self; }
    ExMatrix __abs__() { return abs( *self ); }
    
    std::string __repr__() const { return self->to_string(); }
    std::string __str__() const { return self->to_string(); }
    
    ExMatrix subs(const Ex &f,double t) const { return self->subs(f,Codegen::number(t)); }
};
    
ExMatrix abs(const ExMatrix &a);
ExMatrix heavyside(const ExMatrix &a);
ExMatrix heavyside_if(const ExMatrix &a);
ExMatrix heaviside(const ExMatrix &a);
ExMatrix heaviside_if(const ExMatrix &a);
ExMatrix eqz(const ExMatrix &a);
ExMatrix sin(const ExMatrix &a);
ExMatrix cos(const ExMatrix &a);
ExMatrix sgn(const ExMatrix &a);
ExMatrix tan(const ExMatrix &a);
ExMatrix log(const ExMatrix &a);
//ExMatrix exp(const ExMatrix &a);
ExMatrix neg(const ExMatrix &a);
ExMatrix asin(const ExMatrix &a);
ExMatrix acos(const ExMatrix &a);
ExMatrix atan(const ExMatrix &a);
    
ExMatrix pow(const ExMatrix &a,const ExMatrix &b);
ExMatrix max(const ExMatrix &a,const ExMatrix &b);
ExMatrix pow(const ExMatrix &a,const Ex &b);
ExMatrix max(const ExMatrix &a,const Ex &b);
ExMatrix pow(const Ex &a,const ExMatrix &b);
ExMatrix max(const Ex &a,const ExMatrix &b);

Ex dot(const ExMatrix &a,const ExVector &b);
Ex dot(const ExVector &a,const ExMatrix &b);
Ex dot(const ExMatrix &a,const ExMatrix &b);

// --------------------------------
class Write_code {
public:
    Write_code(const char *default_type="T",unsigned nb_spaces=4);
    enum Method {Declare,Set,Add,Sub,Return}; 
    void add( const Ex &ex, const std::string &name, Method method=Declare );
    unsigned node_count() const;
    std::string to_string();
    std::string to_asm();
    std::string asm_caller( std::string asm_function_name );
    void display_graphviz();
};
%extend Write_code {
    void add( int ex, const std::string &name, Method method ) { self->add( Codegen::number(ex),name,method ); }
    void add( double ex, const std::string &name, Method method ) { self->add( Codegen::number(ex),name,method ); }
    void add( const ExVector &vec, const std::string &name, Method method=Declare ) {
        for(unsigned i=0;i<vec.size();++i) {
            std::ostringstream ss; ss << name << "[" << i << "]";
            self->add( vec[i], ss.str(), method );
        }
    }
    void add( const ExMatrix &mat, const std::string &name, Method method=Declare ) {
        for(unsigned i=0;i<mat.nb_rows();++i) {
            for(unsigned j=0;j<mat.nb_cols();++j) {
                std::ostringstream ss; ss << name << "(" << i << "," << j << ")";
                self->add( mat(i,j), ss.str(), method );
            }
        }
    }
}
// --------------------------------


}

