namespace LMT {
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Conj,1,Vec<T,s>,true>,s> conj(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Abs,1,Vec<T,s>,true>,s> abs(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Acos,1,Vec<T,s>,true>,s> acos(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Asin,1,Vec<T,s>,true>,s> asin(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Atan,1,Vec<T,s>,true>,s> atan(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Cos,1,Vec<T,s>,true>,s> cos(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Cosh,1,Vec<T,s>,true>,s> cosh(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Exp,1,Vec<T,s>,true>,s> exp(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Log,1,Vec<T,s>,true>,s> log(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Log10,1,Vec<T,s>,true>,s> log10(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Sin,1,Vec<T,s>,true>,s> sin(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Sinh,1,Vec<T,s>,true>,s> sinh(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Sqrt,1,Vec<T,s>,true>,s> sqrt(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Tan,1,Vec<T,s>,true>,s> tan(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Tanh,1,Vec<T,s>,true>,s> tanh(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Real,1,Vec<T,s>,true>,s> real(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Imag,1,Vec<T,s>,true>,s> imag(const Vec<T,s> &v) { return v; }
/*!
    \relates Vec
    \keyword Mathématiques/Fonction
*/
template<class T,int s>
Vec<VecOp<Arg,1,Vec<T,s>,true>,s> arg(const Vec<T,s> &v) { return v; }
};
