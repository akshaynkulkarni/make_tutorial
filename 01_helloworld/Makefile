
#TARGET: DEPENDENCY1 DEPENDENCY2 TARGET1 TARGET2
#<tab, not space>commands

all: main run

main: main.cpp
	g++ main.cpp -o main

mainobj: main.cpp
	g++ -c main.cpp -o main.o

main.exe: mainobj
	g++	main.o -o main

run: main
	./main

clean:
	rm -rf ./main ./main.o
