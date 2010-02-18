
namespace LMT {

/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Plus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator+( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Plus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Plus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Plus>::T,STO1 > operator+( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Plus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Plus>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Plus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Plus>::T,STO1 > operator+( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Plus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Plus>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Minus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator-( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Minus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Minus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Minus>::T,STO1 > operator-( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Minus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Minus>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Minus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Minus>::T,STO1 > operator-( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Minus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Minus>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Modulus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator%( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Modulus, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Modulus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Modulus>::T,STO1 > operator%( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Modulus, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Modulus>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Modulus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Modulus>::T,STO1 > operator%( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Modulus, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Modulus>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Multiplies, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Multiplies>::T,STO1 > operator*( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Multiplies, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Multiplies>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Multiplies, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Multiplies>::T,STO1 > operator*( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Multiplies, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Multiplies>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Divides, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Divides>::T,STO1 > operator/( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Divides, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Divides>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Divides, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Divides>::T,STO1 > operator/( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Divides, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Divides>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Equal, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator==( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Equal, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Equal, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Equal>::T,STO1 > operator==( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Equal, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Equal>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Equal, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Equal>::T,STO1 > operator==( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Equal, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Equal>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< NotEqual, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator!=( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< NotEqual, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< NotEqual, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,NotEqual>::T,STO1 > operator!=( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< NotEqual, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,NotEqual>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< NotEqual, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,NotEqual>::T,STO1 > operator!=( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< NotEqual, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,NotEqual>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Less, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator<( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Less, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Less, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Less>::T,STO1 > operator<( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Less, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Less>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Less, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Less>::T,STO1 > operator<( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Less, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Less>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Greater, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator>( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Greater, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Greater, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Greater>::T,STO1 > operator>( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Greater, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Greater>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Greater, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Greater>::T,STO1 > operator>( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Greater, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Greater>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< LessEq, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator<=( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< LessEq, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< LessEq, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,LessEq>::T,STO1 > operator<=( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< LessEq, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,LessEq>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< LessEq, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,LessEq>::T,STO1 > operator<=( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< LessEq, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,LessEq>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< GreaterEq, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator>=( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< GreaterEq, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< GreaterEq, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,GreaterEq>::T,STO1 > operator>=( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< GreaterEq, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,GreaterEq>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< GreaterEq, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,GreaterEq>::T,STO1 > operator>=( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< GreaterEq, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,GreaterEq>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< And, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator&( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< And, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< And, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,And>::T,STO1 > operator&( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< And, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,And>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< And, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,And>::T,STO1 > operator&( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< And, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,And>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Or, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator|( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Or, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Or, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Or>::T,STO1 > operator|( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Or, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Or>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Or, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Or>::T,STO1 > operator|( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Or, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Or>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Xor, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator^( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Xor, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Xor, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Xor>::T,STO1 > operator^( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Xor, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Xor>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Xor, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Xor>::T,STO1 > operator^( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Xor, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Xor>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< AndAnd, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator&&( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< AndAnd, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< AndAnd, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,AndAnd>::T,STO1 > operator&&( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< AndAnd, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,AndAnd>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< AndAnd, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,AndAnd>::T,STO1 > operator&&( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< AndAnd, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,AndAnd>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< OrOr, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operator||( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< OrOr, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< OrOr, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,OrOr>::T,STO1 > operator||( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< OrOr, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,OrOr>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< OrOr, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,OrOr>::T,STO1 > operator||( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< OrOr, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,OrOr>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Min, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > min( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Min, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Min, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Min>::T,STO1 > min( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Min, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Min>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Min, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Min>::T,STO1 > min( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Min, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Min>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>
Mat<MatOp< Max, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> > operatormax( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {
    return Mat<MatOp< Max, 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >( v1, v2 );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Max, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Max>::T,STO1 > operatormax( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {
    return Mat<MatOp< Max, 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,Max>::T,STO1 >( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );
}


/** \relates Vec */
template<class T1,class STR1,class STO1,class T2>
Mat<MatOp< Max, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Max>::T,STO1 > operatormax( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {
    return Mat<MatOp< Max, 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,Max>::T,STO1 >(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);
}


};
