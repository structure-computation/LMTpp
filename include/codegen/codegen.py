# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _codegen

def _swig_setattr(self,class_type,name,value):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    self.__dict__[name] = value

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


class UnsignedVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, UnsignedVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, UnsignedVector, name)
    def __repr__(self):
        return "<C std::vector<(unsigned int)> instance at %s>" % (self.this,)
    def __init__(self, *args):
        _swig_setattr(self, UnsignedVector, 'this', _codegen.new_UnsignedVector(*args))
        _swig_setattr(self, UnsignedVector, 'thisown', 1)
    def __len__(*args): return _codegen.UnsignedVector___len__(*args)
    def __nonzero__(*args): return _codegen.UnsignedVector___nonzero__(*args)
    def clear(*args): return _codegen.UnsignedVector_clear(*args)
    def append(*args): return _codegen.UnsignedVector_append(*args)
    def pop(*args): return _codegen.UnsignedVector_pop(*args)
    def __getitem__(*args): return _codegen.UnsignedVector___getitem__(*args)
    def __getslice__(*args): return _codegen.UnsignedVector___getslice__(*args)
    def __setitem__(*args): return _codegen.UnsignedVector___setitem__(*args)
    def __setslice__(*args): return _codegen.UnsignedVector___setslice__(*args)
    def __delitem__(*args): return _codegen.UnsignedVector___delitem__(*args)
    def __delslice__(*args): return _codegen.UnsignedVector___delslice__(*args)
    def __del__(self, destroy=_codegen.delete_UnsignedVector):
        try:
            if self.thisown: destroy(self)
        except: pass

class UnsignedVectorPtr(UnsignedVector):
    def __init__(self, this):
        _swig_setattr(self, UnsignedVector, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, UnsignedVector, 'thisown', 0)
        _swig_setattr(self, UnsignedVector,self.__class__,UnsignedVector)
_codegen.UnsignedVector_swigregister(UnsignedVectorPtr)

class DoubleVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DoubleVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DoubleVector, name)
    def __repr__(self):
        return "<C std::vector<(double)> instance at %s>" % (self.this,)
    def __init__(self, *args):
        _swig_setattr(self, DoubleVector, 'this', _codegen.new_DoubleVector(*args))
        _swig_setattr(self, DoubleVector, 'thisown', 1)
    def __len__(*args): return _codegen.DoubleVector___len__(*args)
    def __nonzero__(*args): return _codegen.DoubleVector___nonzero__(*args)
    def clear(*args): return _codegen.DoubleVector_clear(*args)
    def append(*args): return _codegen.DoubleVector_append(*args)
    def pop(*args): return _codegen.DoubleVector_pop(*args)
    def __getitem__(*args): return _codegen.DoubleVector___getitem__(*args)
    def __getslice__(*args): return _codegen.DoubleVector___getslice__(*args)
    def __setitem__(*args): return _codegen.DoubleVector___setitem__(*args)
    def __setslice__(*args): return _codegen.DoubleVector___setslice__(*args)
    def __delitem__(*args): return _codegen.DoubleVector___delitem__(*args)
    def __delslice__(*args): return _codegen.DoubleVector___delslice__(*args)
    def __del__(self, destroy=_codegen.delete_DoubleVector):
        try:
            if self.thisown: destroy(self)
        except: pass

class DoubleVectorPtr(DoubleVector):
    def __init__(self, this):
        _swig_setattr(self, DoubleVector, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, DoubleVector, 'thisown', 0)
        _swig_setattr(self, DoubleVector,self.__class__,DoubleVector)
_codegen.DoubleVector_swigregister(DoubleVectorPtr)

class Ex(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Ex, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Ex, name)
    def __init__(self, *args):
        _swig_setattr(self, Ex, 'this', _codegen.new_Ex(*args))
        _swig_setattr(self, Ex, 'thisown', 1)
    def __del__(self, destroy=_codegen.delete_Ex):
        try:
            if self.thisown: destroy(self)
        except: pass
    def to_string(*args): return _codegen.Ex_to_string(*args)
    def graphviz_repr(*args): return _codegen.Ex_graphviz_repr(*args)
    def is_a_symbol(*args): return _codegen.Ex_is_a_symbol(*args)
    def is_a_number(*args): return _codegen.Ex_is_a_number(*args)
    def get_val(*args): return _codegen.Ex_get_val(*args)
    def set_val(*args): return _codegen.Ex_set_val(*args)
    def is_a_function_1(*args): return _codegen.Ex_is_a_function_1(*args)
    def is_a_function_2(*args): return _codegen.Ex_is_a_function_2(*args)
    def display_graphviz(*args): return _codegen.Ex_display_graphviz(*args)
    def depends_on(*args): return _codegen.Ex_depends_on(*args)
    def subs_with_test(*args): return _codegen.Ex_subs_with_test(*args)
    def diff(*args): return _codegen.Ex_diff(*args)
    def nb_children(*args): return _codegen.Ex_nb_children(*args)
    def child(*args): return _codegen.Ex_child(*args)
    def nb_parents(*args): return _codegen.Ex_nb_parents(*args)
    def parent(*args): return _codegen.Ex_parent(*args)
    def id(*args): return _codegen.Ex_id(*args)
    def __add__(*args): return _codegen.Ex___add__(*args)
    def __radd__(*args): return _codegen.Ex___radd__(*args)
    def __sub__(*args): return _codegen.Ex___sub__(*args)
    def __rsub__(*args): return _codegen.Ex___rsub__(*args)
    def __mul__(*args): return _codegen.Ex___mul__(*args)
    def __rmul__(*args): return _codegen.Ex___rmul__(*args)
    def __div__(*args): return _codegen.Ex___div__(*args)
    def __rdiv__(*args): return _codegen.Ex___rdiv__(*args)
    def __pow__(*args): return _codegen.Ex___pow__(*args)
    def __rpow__(*args): return _codegen.Ex___rpow__(*args)
    def __neg__(*args): return _codegen.Ex___neg__(*args)
    def __abs__(*args): return _codegen.Ex___abs__(*args)
    def __nonzero__(*args): return _codegen.Ex___nonzero__(*args)
    def __repr__(*args): return _codegen.Ex___repr__(*args)
    def __str__(*args): return _codegen.Ex___str__(*args)
    def subs(*args): return _codegen.Ex_subs(*args)

class ExPtr(Ex):
    def __init__(self, this):
        _swig_setattr(self, Ex, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Ex, 'thisown', 0)
        _swig_setattr(self, Ex,self.__class__,Ex)
_codegen.Ex_swigregister(ExPtr)


symbol = _codegen.symbol
class EM(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, EM, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, EM, name)
    def __repr__(self):
        return "<C std::map<(Codegen::Ex,Codegen::Ex)> instance at %s>" % (self.this,)
    def __init__(self, *args):
        _swig_setattr(self, EM, 'this', _codegen.new_EM(*args))
        _swig_setattr(self, EM, 'thisown', 1)
    def __len__(*args): return _codegen.EM___len__(*args)
    def clear(*args): return _codegen.EM_clear(*args)
    def __nonzero__(*args): return _codegen.EM___nonzero__(*args)
    def __getitem__(*args): return _codegen.EM___getitem__(*args)
    def __setitem__(*args): return _codegen.EM___setitem__(*args)
    def __delitem__(*args): return _codegen.EM___delitem__(*args)
    def has_key(*args): return _codegen.EM_has_key(*args)
    def keys(*args): return _codegen.EM_keys(*args)
    def values(*args): return _codegen.EM_values(*args)
    def items(*args): return _codegen.EM_items(*args)
    def __contains__(*args): return _codegen.EM___contains__(*args)
    def __iter__(*args): return _codegen.EM___iter__(*args)
    def __del__(self, destroy=_codegen.delete_EM):
        try:
            if self.thisown: destroy(self)
        except: pass

class EMPtr(EM):
    def __init__(self, this):
        _swig_setattr(self, EM, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, EM, 'thisown', 0)
        _swig_setattr(self, EM,self.__class__,EM)
_codegen.EM_swigregister(EMPtr)

number = _codegen.number

sqrt = _codegen.sqrt

exp = _codegen.exp

atan2 = _codegen.atan2

class PEX(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, PEX, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, PEX, name)
    def __repr__(self):
        return "<C std::pair<(Codegen::Ex,Codegen::Ex)> instance at %s>" % (self.this,)
    __swig_setmethods__["first"] = _codegen.PEX_first_set
    __swig_getmethods__["first"] = _codegen.PEX_first_get
    if _newclass:first = property(_codegen.PEX_first_get, _codegen.PEX_first_set)
    __swig_setmethods__["second"] = _codegen.PEX_second_set
    __swig_getmethods__["second"] = _codegen.PEX_second_get
    if _newclass:second = property(_codegen.PEX_second_get, _codegen.PEX_second_set)
    def __init__(self, *args):
        _swig_setattr(self, PEX, 'this', _codegen.new_PEX(*args))
        _swig_setattr(self, PEX, 'thisown', 1)
    def __del__(self, destroy=_codegen.delete_PEX):
        try:
            if self.thisown: destroy(self)
        except: pass

class PEXPtr(PEX):
    def __init__(self, this):
        _swig_setattr(self, PEX, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, PEX, 'thisown', 0)
        _swig_setattr(self, PEX,self.__class__,PEX)
_codegen.PEX_swigregister(PEXPtr)

class ExVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ExVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ExVector, name)
    def __init__(self, *args):
        _swig_setattr(self, ExVector, 'this', _codegen.new_ExVector(*args))
        _swig_setattr(self, ExVector, 'thisown', 1)
    def push_back(*args): return _codegen.ExVector_push_back(*args)
    def resize(*args): return _codegen.ExVector_resize(*args)
    def size(*args): return _codegen.ExVector_size(*args)
    def to_string(*args): return _codegen.ExVector_to_string(*args)
    def graphviz_repr(*args): return _codegen.ExVector_graphviz_repr(*args)
    def is_null(*args): return _codegen.ExVector_is_null(*args)
    def diff(*args): return _codegen.ExVector_diff(*args)
    def max(*args): return _codegen.ExVector_max(*args)
    def sum(*args): return _codegen.ExVector_sum(*args)
    def __getitem__(*args): return _codegen.ExVector___getitem__(*args)
    def __setitem__(*args): return _codegen.ExVector___setitem__(*args)
    def __add__(*args): return _codegen.ExVector___add__(*args)
    def __radd__(*args): return _codegen.ExVector___radd__(*args)
    def __sub__(*args): return _codegen.ExVector___sub__(*args)
    def __rsub__(*args): return _codegen.ExVector___rsub__(*args)
    def __mul__(*args): return _codegen.ExVector___mul__(*args)
    def __rmul__(*args): return _codegen.ExVector___rmul__(*args)
    def __div__(*args): return _codegen.ExVector___div__(*args)
    def __rdiv__(*args): return _codegen.ExVector___rdiv__(*args)
    def __pow__(*args): return _codegen.ExVector___pow__(*args)
    def __rpow__(*args): return _codegen.ExVector___rpow__(*args)
    def __neg__(*args): return _codegen.ExVector___neg__(*args)
    def __abs__(*args): return _codegen.ExVector___abs__(*args)
    def __repr__(*args): return _codegen.ExVector___repr__(*args)
    def __str__(*args): return _codegen.ExVector___str__(*args)
    def subs(*args): return _codegen.ExVector_subs(*args)
    def __del__(self, destroy=_codegen.delete_ExVector):
        try:
            if self.thisown: destroy(self)
        except: pass

class ExVectorPtr(ExVector):
    def __init__(self, this):
        _swig_setattr(self, ExVector, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ExVector, 'thisown', 0)
        _swig_setattr(self, ExVector,self.__class__,ExVector)
_codegen.ExVector_swigregister(ExVectorPtr)


norm = _codegen.norm

vect_prod = _codegen.vect_prod
class ExMatrix(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ExMatrix, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ExMatrix, name)
    def __init__(self, *args):
        _swig_setattr(self, ExMatrix, 'this', _codegen.new_ExMatrix(*args))
        _swig_setattr(self, ExMatrix, 'thisown', 1)
    def copy(*args): return _codegen.ExMatrix_copy(*args)
    def __call__(*args): return _codegen.ExMatrix___call__(*args)
    def nb_rows(*args): return _codegen.ExMatrix_nb_rows(*args)
    def nb_cols(*args): return _codegen.ExMatrix_nb_cols(*args)
    def to_string(*args): return _codegen.ExMatrix_to_string(*args)
    def graphviz_repr(*args): return _codegen.ExMatrix_graphviz_repr(*args)
    def is_null(*args): return _codegen.ExMatrix_is_null(*args)
    def depends_on(*args): return _codegen.ExMatrix_depends_on(*args)
    def diff(*args): return _codegen.ExMatrix_diff(*args)
    def max(*args): return _codegen.ExMatrix_max(*args)
    def trace(*args): return _codegen.ExMatrix_trace(*args)
    def transpose(*args): return _codegen.ExMatrix_transpose(*args)
    def determinant(*args): return _codegen.ExMatrix_determinant(*args)
    def row(*args): return _codegen.ExMatrix_row(*args)
    def col(*args): return _codegen.ExMatrix_col(*args)
    def without_col(*args): return _codegen.ExMatrix_without_col(*args)
    def without_row(*args): return _codegen.ExMatrix_without_row(*args)
    def inverse(*args): return _codegen.ExMatrix_inverse(*args)
    def __getitem__(*args): return _codegen.ExMatrix___getitem__(*args)
    def __setitem__(*args): return _codegen.ExMatrix___setitem__(*args)
    def __add__(*args): return _codegen.ExMatrix___add__(*args)
    def __radd__(*args): return _codegen.ExMatrix___radd__(*args)
    def __sub__(*args): return _codegen.ExMatrix___sub__(*args)
    def __rsub__(*args): return _codegen.ExMatrix___rsub__(*args)
    def __mul__(*args): return _codegen.ExMatrix___mul__(*args)
    def __rmul__(*args): return _codegen.ExMatrix___rmul__(*args)
    def __div__(*args): return _codegen.ExMatrix___div__(*args)
    def __rdiv__(*args): return _codegen.ExMatrix___rdiv__(*args)
    def __pow__(*args): return _codegen.ExMatrix___pow__(*args)
    def __rpow__(*args): return _codegen.ExMatrix___rpow__(*args)
    def __neg__(*args): return _codegen.ExMatrix___neg__(*args)
    def __abs__(*args): return _codegen.ExMatrix___abs__(*args)
    def __repr__(*args): return _codegen.ExMatrix___repr__(*args)
    def __str__(*args): return _codegen.ExMatrix___str__(*args)
    def subs(*args): return _codegen.ExMatrix_subs(*args)
    def __del__(self, destroy=_codegen.delete_ExMatrix):
        try:
            if self.thisown: destroy(self)
        except: pass

class ExMatrixPtr(ExMatrix):
    def __init__(self, this):
        _swig_setattr(self, ExMatrix, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, ExMatrix, 'thisown', 0)
        _swig_setattr(self, ExMatrix,self.__class__,ExMatrix)
_codegen.ExMatrix_swigregister(ExMatrixPtr)

class Write_code(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Write_code, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Write_code, name)
    def __repr__(self):
        return "<C Codegen::Write_code instance at %s>" % (self.this,)
    def __init__(self, *args):
        _swig_setattr(self, Write_code, 'this', _codegen.new_Write_code(*args))
        _swig_setattr(self, Write_code, 'thisown', 1)
    Declare = _codegen.Write_code_Declare
    Set = _codegen.Write_code_Set
    Add = _codegen.Write_code_Add
    Sub = _codegen.Write_code_Sub
    Return = _codegen.Write_code_Return
    def to_string(*args): return _codegen.Write_code_to_string(*args)
    def add(*args): return _codegen.Write_code_add(*args)
    def __del__(self, destroy=_codegen.delete_Write_code):
        try:
            if self.thisown: destroy(self)
        except: pass

class Write_codePtr(Write_code):
    def __init__(self, this):
        _swig_setattr(self, Write_code, 'this', this)
        if not hasattr(self,"thisown"): _swig_setattr(self, Write_code, 'thisown', 0)
        _swig_setattr(self, Write_code,self.__class__,Write_code)
_codegen.Write_code_swigregister(Write_codePtr)

abs = _codegen.abs

heavyside = _codegen.heavyside

heavyside_if = _codegen.heavyside_if

eqz = _codegen.eqz

sin = _codegen.sin

cos = _codegen.cos

sgn = _codegen.sgn

tan = _codegen.tan

log = _codegen.log

neg = _codegen.neg

asin = _codegen.asin

acos = _codegen.acos

atan = _codegen.atan

pow = _codegen.pow

max = _codegen.max

dot = _codegen.dot


