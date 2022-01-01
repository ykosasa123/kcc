#include "lex.hpp"

Lexer::Lexer(const char* in)
{
     input = in;
}

Lexer::~Lexer()
{
}

std::string& Lexer::getStringName(int i)
{
     return tokenName[i];
}
