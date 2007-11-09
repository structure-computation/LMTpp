# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.
# This file is compatible with both classic and new-style classes.

import _codegen
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


class PySwigIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, PySwigIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, PySwigIterator, name)
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _codegen.delete_PySwigIterator
    __del__ = lambda self : None;
    def value(*args): return _codegen.PySwigIterator_value(*args)
    def incr(*args): return _codegen.PySwigIterator_incr(*args)
    def decr(*args): return _codegen.PySwigIterator_decr(*args)
    def distance(*args): return _codegen.PySwigIterator_distance(*args)
    def equal(*args): return _codegen.PySwigIterator_equal(*args)
    def copy(*args): return _codegen.PySwigIterator_copy(*args)
    def next(*args): return _codegen.PySwigIterator_next(*args)
    def previous(*args): return _codegen.PySwigIterator_previous(*args)
    def advance(*args): return _codegen.PySwigIterator_advance(*args)
    def __eq__(*args): return _codegen.PySwigIterator___eq__(*args)
    def __ne__(*args): return _codegen.PySwigIterator___ne__(*args)
    def __iadd__(*args): return _codegen.PySwigIterator___iadd__(*args)
    def __isub__(*args): return _codegen.PySwigIterator___isub__(*args)
    def __add__(*args): return _codegen.PySwigIterator___add__(*args)
    def __sub__(*args): return _codegen.PySwigIterator___sub__(*args)
    def __iter__(self): return self
PySwigIterator_swigregister = _codegen.PySwigIterator_swigregister
PySwigIterator_swigregister(PySwigIterator)

class UnsignedVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, UnsignedVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, UnsignedVector, name)
    __repr__ = _swig_repr
    def iterator(*args): return _codegen.UnsignedVector_iterator(*args)
    def __iter__(self): return self.iterator()
    def __nonzero__(*args): return _codegen.UnsignedVector___nonzero__(*args)
    def __len__(*args): return _codegen.UnsignedVector___len__(*args)
    def pop(*args): return _codegen.UnsignedVector_pop(*args)
    def __getslice__(*args): return _codegen.UnsignedVector___getslice__(*args)
    def __setslice__(*args): return _codegen.UnsignedVector___setslice__(*args)
    def __delslice__(*args): return _codegen.UnsignedVector___delslice__(*args)
    def __delitem__(*args): return _codegen.UnsignedVector___delitem__(*args)
    def __getitem__(*args): return _codegen.UnsignedVector___getitem__(*args)
    def __setitem__(*args): return _codegen.UnsignedVector___setitem__(*args)
    def append(*args): return _codegen.UnsignedVector_append(*args)
    def empty(*args): return _codegen.UnsignedVector_empty(*args)
    def size(*args): return _codegen.UnsignedVector_size(*args)
    def clear(*args): return _codegen.UnsignedVector_clear(*args)
    def swap(*args): return _codegen.UnsignedVector_swap(*args)
    def get_allocator(*args): return _codegen.UnsignedVector_get_allocator(*args)
    def begin(*args): return _codegen.UnsignedVector_begin(*args)
    def end(*args): return _codegen.UnsignedVector_end(*args)
    def rbegin(*args): return _codegen.UnsignedVector_rbegin(*args)
    def rend(*args): return _codegen.UnsignedVector_rend(*args)
    def pop_back(*args): return _codegen.UnsignedVector_pop_back(*args)
    def erase(*args): return _codegen.UnsignedVector_erase(*args)
    def __init__(self, *args): 
        this = _codegen.new_UnsignedVector(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(*args): return _codegen.UnsignedVector_push_back(*args)
    def front(*args): return _codegen.UnsignedVector_front(*args)
    def back(*args): return _codegen.UnsignedVector_back(*args)
    def assign(*args): return _codegen.UnsignedVector_assign(*args)
    def resize(*args): return _codegen.UnsignedVector_resize(*args)
    def insert(*args): return _codegen.UnsignedVector_insert(*args)
    def reserve(*args): return _codegen.UnsignedVector_reserve(*args)
    def capacity(*args): return _codegen.UnsignedVector_capacity(*args)
    __swig_destroy__ = _codegen.delete_UnsignedVector
    __del__ = lambda self : None;
UnsignedVector_swigregister = _codegen.UnsignedVector_swigregister
UnsignedVector_swigregister(UnsignedVector)

class DoubleVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DoubleVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DoubleVector, name)
    __repr__ = _swig_repr
    def iterator(*args): return _codegen.DoubleVector_iterator(*args)
    def __iter__(self): return self.iterator()
    def __nonzero__(*args): return _codegen.DoubleVector___nonzero__(*args)
    def __len__(*args): return _codegen.DoubleVector___len__(*args)
    def pop(*args): return _codegen.DoubleVector_pop(*args)
    def __getslice__(*args): return _codegen.DoubleVector___getslice__(*args)
    def __setslice__(*args): return _codegen.DoubleVector___setslice__(*args)
    def __delslice__(*args): return _codegen.DoubleVector___delslice__(*args)
    def __delitem__(*args): return _codegen.DoubleVector___delitem__(*args)
    def __getitem__(*args): return _codegen.DoubleVector___getitem__(*args)
    def __setitem__(*args): return _codegen.DoubleVector___setitem__(*args)
    def append(*args): return _codegen.DoubleVector_append(*args)
    def empty(*args): return _codegen.DoubleVector_empty(*args)
    def size(*args): return _codegen.DoubleVector_size(*args)
    def clear(*args): return _codegen.DoubleVector_clear(*args)
    def swap(*args): return _codegen.DoubleVector_swap(*args)
    def get_allocator(*args): return _codegen.DoubleVector_get_allocator(*args)
    def begin(*args): return _codegen.DoubleVector_begin(*args)
    def end(*args): return _codegen.DoubleVector_end(*args)
    def rbegin(*args): return _codegen.DoubleVector_rbegin(*args)
    def rend(*args): return _codegen.DoubleVector_rend(*args)
    def pop_back(*args): return _codegen.DoubleVector_pop_back(*args)
    def erase(*args): return _codegen.DoubleVector_erase(*args)
    def __init__(self, *args): 
        this = _codegen.new_DoubleVector(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(*args): return _codegen.DoubleVector_push_back(*args)
    def front(*args): return _codegen.DoubleVector_front(*args)
    def back(*args): return _codegen.DoubleVector_back(*args)
    def assign(*args): return _codegen.DoubleVector_assign(*args)
    def resize(*args): return _codegen.DoubleVector_resize(*args)
    def insert(*args): return _codegen.DoubleVector_insert(*args)
    def reserve(*args): return _codegen.DoubleVector_reserve(*args)
    def capacity(*args): return _codegen.DoubleVector_capacity(*args)
    __swig_destroy__ = _codegen.delete_DoubleVector
    __del__ = lambda self : None;
DoubleVector_swigregister = _codegen.DoubleVector_swigregister
DoubleVector_swigregister(DoubleVector)

class Ex(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Ex, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Ex, name)
    def __init__(self, *args): 
        this = _codegen.new_Ex(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _codegen.delete_Ex
    __del__ = lambda self : None;
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
Ex_swigregister = _codegen.Ex_swigregister
Ex_swigregister(Ex)

class EM(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, EM, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, EM, name)
    __repr__ = _swig_repr
    def iterator(*args): return _codegen.EM_iterator(*args)
    def __iter__(self): return self.iterator()
    def __nonzero__(*args): return _codegen.EM___nonzero__(*args)
    def __len__(*args): return _codegen.EM___len__(*args)
    def __getitem__(*args): return _codegen.EM___getitem__(*args)
    def __setitem__(*args): return _codegen.EM___setitem__(*args)
    def __delitem__(*args): return _codegen.EM___delitem__(*args)
    def has_key(*args): return _codegen.EM_has_key(*args)
    def keys(*args): return _codegen.EM_keys(*args)
    def values(*args): return _codegen.EM_values(*args)
    def items(*args): return _codegen.EM_items(*args)
    def __contains__(*args): return _codegen.EM___contains__(*args)
    def key_iterator(*args): return _codegen.EM_key_iterator(*args)
    def value_iterator(*args): return _codegen.EM_value_iterator(*args)
    def __iter__(self): return self.key_iterator()
    def iterkeys(self): return self.key_iterator()
    def itervalues(self): return self.value_iterator()
    def iteritems(self): return self.iterator()
    def __init__(self, *args): 
        this = _codegen.new_EM(*args)
        try: self.this.append(this)
        except: self.this = this
    def empty(*args): return _codegen.EM_empty(*args)
    def size(*args): return _codegen.EM_size(*args)
    def clear(*args): return _codegen.EM_clear(*args)
    def swap(*args): return _codegen.EM_swap(*args)
    def get_allocator(*args): return _codegen.EM_get_allocator(*args)
    def begin(*args): return _codegen.EM_begin(*args)
    def end(*args): return _codegen.EM_end(*args)
    def rbegin(*args): return _codegen.EM_rbegin(*args)
    def rend(*args): return _codegen.EM_rend(*args)
    def count(*args): return _codegen.EM_count(*args)
    def erase(*args): return _codegen.EM_erase(*args)
    def find(*args): return _codegen.EM_find(*args)
    def lower_bound(*args): return _codegen.EM_lower_bound(*args)
    def upper_bound(*args): return _codegen.EM_upper_bound(*args)
    __swig_destroy__ = _codegen.delete_EM
    __del__ = lambda self : None;
EM_swigregister = _codegen.EM_swigregister
EM_swigregister(EM)
symbol = _codegen.symbol
number = _codegen.number
sqrt = _codegen.sqrt
exp = _codegen.exp
atan2 = _codegen.atan2

class PEX(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, PEX, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, PEX, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _codegen.new_PEX(*args)
        try: self.this.append(this)
        except: self.this = this
    __swig_setmethods__["first"] = _codegen.PEX_first_set
    __swig_getmethods__["first"] = _codegen.PEX_first_get
    if _newclass:first = property(_codegen.PEX_first_get, _codegen.PEX_first_set)
    __swig_setmethods__["second"] = _codegen.PEX_second_set
    __swig_getmethods__["second"] = _codegen.PEX_second_get
    if _newclass:second = property(_codegen.PEX_second_get, _codegen.PEX_second_set)
    def __len__(self): return 2
    def __repr__(self): return str((self.first, self.second))
    def __getitem__(self, index): 
      if not (index % 2): 
        return self.first
      else:
        return self.second
    def __setitem__(self, index, val):
      if not (index % 2): 
        self.first = val
      else:
        self.second = val
    __swig_destroy__ = _codegen.delete_PEX
    __del__ = lambda self : None;
PEX_swigregister = _codegen.PEX_swigregister
PEX_swigregister(PEX)

class ExVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ExVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ExVector, name)
    def __init__(self, *args): 
        this = _codegen.new_ExVector(*args)
        try: self.this.append(this)
        except: self.this = this
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
    __swig_destroy__ = _codegen.delete_ExVector
    __del__ = lambda self : None;
ExVector_swigregister = _codegen.ExVector_swigregister
ExVector_swigregister(ExVector)

vect_prod = _codegen.vect_prod
class ExMatrix(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, ExMatrix, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, ExMatrix, name)
    def __init__(self, *args): 
        this = _codegen.new_ExMatrix(*args)
        try: self.this.append(this)
        except: self.this = this
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
    __swig_destroy__ = _codegen.delete_ExMatrix
    __del__ = lambda self : None;
ExMatrix_swigregister = _codegen.ExMatrix_swigregister
ExMatrix_swigregister(ExMatrix)
norm = _codegen.norm

class Write_code(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Write_code, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Write_code, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _codegen.new_Write_code(*args)
        try: self.this.append(this)
        except: self.this = this
    Declare = _codegen.Write_code_Declare
    Set = _codegen.Write_code_Set
    Add = _codegen.Write_code_Add
    Sub = _codegen.Write_code_Sub
    Return = _codegen.Write_code_Return
    def to_string(*args): return _codegen.Write_code_to_string(*args)
    def add(*args): return _codegen.Write_code_add(*args)
    __swig_destroy__ = _codegen.delete_Write_code
    __del__ = lambda self : None;
Write_code_swigregister = _codegen.Write_code_swigregister
Write_code_swigregister(Write_code)
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



