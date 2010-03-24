namespace LMT {
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Conj,1,Mat<T,STR,STO>,true>,STR,STO> conj(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Abs,1,Mat<T,STR,STO>,true>,STR,STO> abs(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Acos,1,Mat<T,STR,STO>,true>,STR,STO> acos(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Asin,1,Mat<T,STR,STO>,true>,STR,STO> asin(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Atan,1,Mat<T,STR,STO>,true>,STR,STO> atan(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Cos,1,Mat<T,STR,STO>,true>,STR,STO> cos(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Cosh,1,Mat<T,STR,STO>,true>,STR,STO> cosh(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Exp,1,Mat<T,STR,STO>,true>,STR,STO> exp(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Log,1,Mat<T,STR,STO>,true>,STR,STO> log(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Log10,1,Mat<T,STR,STO>,true>,STR,STO> log10(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Sin,1,Mat<T,STR,STO>,true>,STR,STO> sin(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Sinh,1,Mat<T,STR,STO>,true>,STR,STO> sinh(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Sqrt,1,Mat<T,STR,STO>,true>,STR,STO> sqrt(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Tan,1,Mat<T,STR,STO>,true>,STR,STO> tan(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Tanh,1,Mat<T,STR,STO>,true>,STR,STO> tanh(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Real,1,Mat<T,STR,STO>,true>,STR,STO> real(const Mat<T,STR,STO> &v) { return v; }
/** \relates Vec */
template<class T,class STR,class STO>
Mat<MatOp<Imag,1,Mat<T,STR,STO>,true>,STR,STO> imag(const Mat<T,STR,STO> &v) { return v; }
};
