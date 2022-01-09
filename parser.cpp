#include <sstream>

#include "parser.hpp"

Parser::Parser(Lexer lex) : input(lex), lookAhead(0, "")
{
    lookAhead = input.nextToken();
};

void Parser::start()
{
    match(input._lbrack);
    elements();
    match(input._rbrack);
}

void Parser::elements()
{
    element();
    while ( lookAhead.type == input._comma) {
        match(input._comma);
        element();
    }
}

void Parser::element()
{
    if (lookAhead.type == input._name) {
        match(input._name);
    } else if (lookAhead.type == input._lbrack) {
        start();
    } else {
        std::stringstream str;
        str << "expecting name or list, found " << lookAhead.toString();
        throw std::runtime_error(str.str());
    }
}

void Parser::match(int type)
{
    if (lookAhead.type == type) {
        consume();
    } else {
        std::stringstream str;
        str << "expecting " << input.getStringName(type) << "found " << lookAhead.toString();
        throw std::runtime_error(str.str());
    }
}

void Parser::consume()
{
    lookAhead = input.nextToken();
}
