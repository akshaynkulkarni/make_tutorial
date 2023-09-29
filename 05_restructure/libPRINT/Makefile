# wildcard function
CXX_SRC = $(wildcard *.cpp)
#change %.cpp to %.o in CXX_SRC
CXX_OJS = $(patsubst %.cpp, $(BUILD_DIR)/$(LIBNAME)/%.o, $(CXX_SRC))

$(BUILD_DIR)/$(LIBNAME)/$(LIBNAME).so: $(CXX_OJS)
# for lib creation, we need all .o, so use $^
# -shared: create dynamic library .so
	$(CXX) $^ $(CXXFLAGS) $(LIBFLAGS) -o $@

# for each cpp, generate .o
$(BUILD_DIR)/$(LIBNAME)/%.o: %.cpp
# fPIC: Position independent code, -c: generate obj only, no linking
	$(CXX) -c $< $(CXXFLAGS) $(CXXPICFLAG) -o $@