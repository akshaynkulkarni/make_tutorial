#include <iostream>
#include "somecpp.h"

int somecpp::print(const std::string& input) {
    std::cout << "somecpp: Print buffer is " << input << std::endl;
    return 0;
}