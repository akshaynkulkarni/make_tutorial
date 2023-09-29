run:
# && is important here, both must run in single shell session
	export LD_LIBRARY_PATH=$(shell pwd)/libPRINT/:$LD_LIBRARY_PATH && ./main

main: main.o #-L<pwd_of_libXYZ.so> -l<libname>
	g++ main.o -L./libPRINT -lPRINT -o main

build: main.o libPRINT.so #build and run
	g++ main.o -L./libPRINT -lPRINT -o main
	$(MAKE) run

#some targets are just names,
#ideally they are file names, hence make "main.o"
main.o: main.cpp
#no need to specify -o main.o as we are saying "make main.o"
	g++ -c main.cpp -I ./libPRINT

libPRINT.so:
	$(MAKE) -C libPRINT -f ../libPRINT/Makefile libPRINT.so

clean:
	rm -rf ./main.o ./main
	$(MAKE) -C libPRINT -f ../libPRINT/Makefile clean

# Ensure target clean/build/run is executed, ignoring respecitve dir if any
# as target (if they were directory)
# otherwise, it doesn't build since there is no changes to dir.
.PHONY: build clean run