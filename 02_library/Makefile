run:
# && is important here, both must run in single shell session
	export LD_LIBRARY_PATH=$(shell pwd)/libPRINT/:$LD_LIBRARY_PATH && ./main

main: main.cpp #-L<pwd_of_libXYZ.so> -l<libname>
	g++ main.cpp -L./libPRINT -I ./libPRINT -lPRINT -o main

libPRINT:
	$(MAKE) -C libPRINT -f ../libPRINT/Makefile libPRINT

clean:
	rm -rf ./main.o ./main
	$(MAKE) -C libPRINT -f ../libPRINT/Makefile clean

# Ensure target libPRINT is executed, ignoring libPRINT
# as target (file/dir, in ourcase we have libPRINT as directory)
# otherwise, it doesn't build since there is no changes to dir.
.PHONY: libPRINT clean