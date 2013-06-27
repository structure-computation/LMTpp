all:
	#cd ../include/codegen; scons
	cd src; make -j4
	cd ..; doc/src/main . c++ doc; cp doc/src/red.png ../html; cp doc/src/green.png ../html; 

clean:
	rm -fr html
