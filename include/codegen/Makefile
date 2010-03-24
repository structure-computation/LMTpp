SOURCES     = ex.cpp op.cpp write_code.cpp write_graphviz.cpp exmatrix.cpp exvector.cpp read_ex.cpp write_code_language_cpp.cpp codegen_wrap.cc
OBJECTS     = ex.o   op.o   write_code.o   write_graphviz.o   exmatrix.o   exvector.o   read_ex.o   write_code_language_cpp.o   codegen_wrap.o
CXXFLAGS    = -O3 -fPIC -I/usr/include/python2.6 -I/usr/include/python2.5 -I/usr/include/python2.4 -I/usr/include/python2.3

all: _codegen.so

_codegen.so: ${OBJECTS}
	${CXX} -shared -o _codegen.so ${OBJECTS}
	
codegen_wrap.cc: codegen.i
	swig -o codegen_wrap.cc -python -c++ codegen.i
	
clean:
	rm -f *.o *.so codegen_wrap.cc
	
depend:
	makedepend ${SOURCES}

# DO NOT DELETE

ex.o: ex.h read_ex_error.h op.h codegen_vector.h read_ex.h write_graphviz.h
ex.o: /usr/include/math.h /usr/include/features.h /usr/include/sys/cdefs.h
ex.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
ex.o: /usr/include/gnu/stubs-64.h /usr/include/bits/huge_val.h
ex.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
ex.o: /usr/include/stdlib.h /usr/include/sys/types.h
ex.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
ex.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
ex.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
ex.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
ex.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
ex.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
ex.o: /usr/include/assert.h
op.o: op.h codegen_vector.h /usr/include/string.h /usr/include/features.h
op.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
op.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
op.o: /usr/include/math.h /usr/include/bits/huge_val.h
op.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
op.o: /usr/include/assert.h /usr/include/stdlib.h /usr/include/sys/types.h
op.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
op.o: /usr/include/time.h /usr/include/endian.h /usr/include/bits/endian.h
op.o: /usr/include/bits/byteswap.h /usr/include/sys/select.h
op.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
op.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
op.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
write_code.o: op.h codegen_vector.h ex.h read_ex_error.h write_code.h
write_code.o: write_code_language_cpp.h write_code_language.h
write_code.o: /usr/include/assert.h /usr/include/features.h
write_code.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
write_code.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
write_code.o: /usr/include/stdlib.h /usr/include/sys/types.h
write_code.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
write_code.o: /usr/include/time.h /usr/include/endian.h
write_code.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
write_code.o: /usr/include/sys/select.h /usr/include/bits/select.h
write_code.o: /usr/include/bits/sigset.h /usr/include/bits/time.h
write_code.o: /usr/include/sys/sysmacros.h /usr/include/bits/pthreadtypes.h
write_code.o: /usr/include/alloca.h MakeAsm.h SimpleSplittedVec.h
write_graphviz.o: write_graphviz.h ex.h read_ex_error.h
exmatrix.o: exmatrix.h exvector.h ex.h read_ex_error.h /usr/include/assert.h
exmatrix.o: /usr/include/features.h /usr/include/sys/cdefs.h
exmatrix.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
exmatrix.o: /usr/include/gnu/stubs-64.h
exvector.o: exvector.h ex.h read_ex_error.h /usr/include/assert.h
exvector.o: /usr/include/features.h /usr/include/sys/cdefs.h
exvector.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
exvector.o: /usr/include/gnu/stubs-64.h
read_ex.o: read_ex.h ex.h read_ex_error.h /usr/include/assert.h
read_ex.o: /usr/include/features.h /usr/include/sys/cdefs.h
read_ex.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
read_ex.o: /usr/include/gnu/stubs-64.h
write_code_language_cpp.o: write_code_language_cpp.h write_code_language.h
write_code_language_cpp.o: write_code.h ex.h read_ex_error.h
codegen_wrap.o: /usr/include/string.h /usr/include/features.h
codegen_wrap.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
codegen_wrap.o: /usr/include/gnu/stubs.h /usr/include/gnu/stubs-64.h
codegen_wrap.o: /usr/include/math.h /usr/include/bits/huge_val.h
codegen_wrap.o: /usr/include/bits/mathdef.h /usr/include/bits/mathcalls.h
codegen_wrap.o: codegen.h ex.h read_ex_error.h exmatrix.h exvector.h
codegen_wrap.o: /usr/include/assert.h write_code.h read_ex.h
codegen_wrap.o: /usr/include/limits.h /usr/include/bits/posix1_lim.h
codegen_wrap.o: /usr/include/bits/local_lim.h /usr/include/linux/limits.h
codegen_wrap.o: /usr/include/bits/posix2_lim.h
