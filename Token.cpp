#include <sstream>

#include "Token.hpp"
#include "lex.hpp"

Token::Token(int type, std::string text)
{
    this->type = type;
    this->text = text;
}

Token::~Token(void)
{

}

std::string Token::toString()
{
    std::stringstream str;
    Lexer lex("aaaa");

    str << "<'" << text << "'," <<  lex.getStringName(type) << ">";

    return str.str();
}
