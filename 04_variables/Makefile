# variables: type is always string.
# 0 is string here, it can also be specified
# as "0" or even '0'

RELEASE_BUILD = 0

PRJ_NAME = main

# `make -p`: gives pre-defined variables of make. Examples:
# CC: C Compiler, default: cc
# CXX: C++ Compiler, default: g++
# CFLAGS: C Compiler flags
# CXXFLAGS: C++ Compiler flags
# CPPFLAGS: Pre Processor flags
# LDFLAGS: Linker flags
# These can be overrided in the Makefile by setting them!

CC = gcc
CXX = g++
CXX_STD = c++17
CXX_WARNINGS = -Wall -Wextra -Wpedantic 
#-Wall: Warn all, -Wextra: all + some more,
#-Wpedantic: warns strict non compliance of C/C++ stds
CXXFLAGS = $(CXX_WARNINGS) -std=$(CXX_STD)

ifeq ($(RELEASE_BUILD),1)
CXXFLAGS += -O3
else
CXXFLAGS += -O0 -g
endif

LIBNAME = libPRINT
LIBDIR = libPRINT
LDLIBS = -lPRINT
LDFLAGS = -L./libPRINT $(LDLIBS)

# -shared: create dynamic library .so
LIBFLAGS = -shared
# fPIC: Position independent code, -c: generate obj only, no linking
CXXPICFLAG = -fPIC
# export is required, to be visible in other makefiles,
# as LIBFLAGS/CXXPICFLAG is not a pre-defined make variable
# that is visible accross.
export LIBFLAGS
export CXXPICFLAG
export LIBNAME

INCLUDE_DIRS += -Iinc -I$(LIBDIR)/inc
CXXFLAGS += $(INCLUDE_DIRS)

# wildcard function
CXX_SRC = $(wildcard *.cpp)
#change %.cpp to %.o in CXX_SRC
CXX_OJS = $(patsubst %.cpp, %.o, $(CXX_SRC))

run:
# && is important here, both must run in single shell session
# @: suppress the display of command/output
	@export LD_LIBRARY_PATH=$(shell pwd)/$(LIBDIR)/:$LD_LIBRARY_PATH && ./$(PRJ_NAME)

#main: main.o #-L<pwd_of_libXYZ.so> -l<libname>
#	$(CXX) $(CXX_OJS) $(CXXFLAGS) $(LDFLAGS) -o $(PRJ_NAME)

build: $(CXX_OJS) $(LIBDIR)/$(LIBNAME).so #build and run
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $(PRJ_NAME)
	$(MAKE) run

main: $(CXX_OJS) #build and run
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $(PRJ_NAME)
	$(MAKE) run

# some targets are just names,
# ideally they are file names, hence make "main.o"
# now, use wildcard operator % to build files.o
# for each cpp, generate .o
%.o: %.cpp
# no need to specify -o main.o as we are saying "make main.o"
	$(CXX) -c $< $(CXXFLAGS) -I$(INCLUDE_DIRS) -o $@

# example target:
# %.o : %.cpp
# $@ : file name of the target (main.o, somecpp.o)
# $< : first dependency names	(main.cpp for main.o, somecpp.cpp for somecpp.o)
# $^ : all the dependency names (we could have %.cpp )


$(LIBDIR)/$(LIBNAME).so:
	$(MAKE) -C $(LIBDIR) -f ../$(LIBDIR)/Makefile $(LIBNAME).so

clean:
	rm -rf *.o ./$(PRJ_NAME)
	$(MAKE) -C $(LIBDIR) -f ../$(LIBDIR)/Makefile clean

# Ensure target clean/build/run is executed, ignoring respecitve dir if any
# as target (if they were directory)
# otherwise, it doesn't build since there is no changes to dir.
.PHONY: build clean run