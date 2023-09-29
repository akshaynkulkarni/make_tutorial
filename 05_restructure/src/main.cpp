#include <iostream>
#include <string>

#include "libPRINT.h"
#include "somecpp.h"


int main() {
    std::string input{"Hello World!!"};
    print(input);
    somecpp::print(input);
    return 0;
}


