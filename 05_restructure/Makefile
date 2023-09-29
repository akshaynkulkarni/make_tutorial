# variables: type is always string.
# 0 is string here, it can also be specified
# as "0" or even '0'
# "?=" operator: only set the variable if it hasn't been set yet
RELEASE_BUILD ?= 0

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


INCLUDE_DIRS += -Iinc
CXXFLAGS += $(INCLUDE_DIRS)

SRC_DIR = src
# wildcard function
CXX_SRC = $(wildcard $(SRC_DIR)/*.cpp)
#change %.cpp to %.o in CXX_SRC
CXX_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(CXX_SRC))

ifndef BUILD_DIR
$(info defining  build dir....)
endif

ifeq ($(RELEASE_BUILD),1)
CXXFLAGS += -O3
BUILD_DIR = $(shell pwd)/build/release
else
CXXFLAGS += -O0 -g
BUILD_DIR = $(shell pwd)/build/debug
endif
export BUILD_DIR

#Check Empty variable:
ifeq ($(strip $(BUILD_DIR)),)
$(error BUILD_DIR empty)
endif

LIBNAME = libPRINT
LIBDIR := $(wildcard lib*)
LDLIBS = -lPRINT
LDFLAGS = -L$(BUILD_DIR)/$(LIBNAME)/ $(LDLIBS)

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


all:  create build run

run:
# && is important here, both must run in single shell session
# @: suppress the display of command/output
	@export LD_LIBRARY_PATH=$(BUILD_DIR)/$(LIBNAME)/:$LD_LIBRARY_PATH && $(BUILD_DIR)/$(PRJ_NAME)

#main: main.o #-L<pwd_of_libXYZ.so> -l<libname>
#	$(CXX) $(CXX_OBJS) $(CXXFLAGS) $(LDFLAGS) -o $(PRJ_NAME)
create:
	@mkdir -p $(BUILD_DIR)/$(LIBNAME)

build: $(BUILD_DIR)/$(LIBNAME)/$(LIBNAME).so $(CXX_OBJS)  #build and run
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $(BUILD_DIR)/$(PRJ_NAME)

main: $(CXX_OBJS) #build and run
	$(CXX) $^ $(CXXFLAGS) $(LDFLAGS) -o $(BUILD_DIR)/$(PRJ_NAME)
	$(MAKE) run

# some targets are just names,
# ideally they are file names, hence make "main.o"
# now, use wildcard operator % to build files.o
# for each cpp, generate .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
# no need to specify -o main.o as we are saying "make main.o"
	$(CXX) -c $< $(CXXFLAGS) -I$(INCLUDE_DIRS) -o $@

# example target:
# %.o : %.cpp
# $@ : file name of the target (main.o, somecpp.o)
# $< : first dependency names	(main.cpp for main.o, somecpp.cpp for somecpp.o)
# $^ : all the dependency names (we could have %.cpp )

$(LIBNAME): $(BUILD_DIR)/$(LIBNAME)/$(LIBNAME).so


$(BUILD_DIR)/$(LIBNAME)/$(LIBNAME).so:
	$(MAKE) -C $(LIBNAME) -f ../$(LIBNAME)/Makefile $@

clean:
	rm -rf build

# Ensure target clean/build/run is executed, ignoring respecitve dir if any
# as target (if they were directory)
# otherwise, it doesn't build since there is no changes to dir.
.PHONY: create build clean run $(LIBNAME) 