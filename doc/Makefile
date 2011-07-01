all:
	#cd ../include/codegen; scons
	cd src; make -j4
	cd ..; rm -fr doc/html; doc/src/main . c++ doc; cp doc/src/red.png doc/html; cp doc/src/green.png doc/html; 

clean:
	rm -fr html
