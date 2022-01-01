#include <lex.hpp>
#include <iostream>

int main()
{
    Lexer lex("aaa");

    std::cout << lex.getStringName(0) << std::endl;

    return 0;
}