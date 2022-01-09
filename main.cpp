#include <iostream>
#include <string>

#include "lex.hpp"
#include "Token.hpp"
#include "parser.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cerr << "prog paramater not found." << std::endl;
        exit(-1);
    }

    Lexer lex(argv[1]);
    Parser parser(lex, 2);

    parser.start();

    return 0;
}
