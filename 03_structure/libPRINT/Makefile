
libPRINT.so: PRINT.o
# -shared: create dynamic library .so
	g++ -shared ./PRINT.o -o ./libPRINT.so

PRINT.o: PRINT.cpp
#fPIC: Position independent code, -c: generate obj only, no linking
	g++ -fPIC -c ./PRINT.cpp

clean:
	rm -rf ./PRINT.o ./libPRINT.so