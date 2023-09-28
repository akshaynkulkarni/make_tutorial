
libPRINT: ./PRINT.cpp
#fPIC: Position independent code, -c: generate obj only, no linking
	g++ -fPIC -c ./PRINT.cpp -o ./PRINT.o
# -shared: create dynamic library .so
	g++ -shared ./PRINT.o -o ./libPRINT.so

clean:
	rm -rf ./PRINT.o ./libPRINT.so