#include "lex.hpp"
#include <iostream>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "prog paramater not found." << std::endl;
        exit(-1);
    }

    std::cout << argv[1] << std::endl;

    return 0;
}