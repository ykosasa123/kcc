#include <sstream>

#include "parser.hpp"

Parser::Parser(Lexer lex, int k) : input(lex), lookAhead{}, buf_size(0), p(0)
{
    buf_size = k;
    lookAhead.reserve(buf_size);
    for (int i = 0; i < k; i++) {
        lookAhead.push_back(input.nextToken());
    }
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
    while (lookAhead[p].type == input._comma) {
        match(input._comma);
        element();
    }
}

void Parser::element()
{
    if (LA(1) == input._name && LA(2) == input._equel) {
        match(input._name);
        match(input._equel);
        match(input._name);
    } else if (LA(1) == input._name) {
        match(input._name);
    } else if (LA(1) == input._lbrack){
        start();
    } else {
        std::stringstream str;
        str << __FILE__ << " " << __func__ << ":" << __LINE__ << " expecting name or list, found " << LT(1).toString();
        throw std::runtime_error(str.str());
    }
}

void Parser::match(int type)
{
    if (lookAhead[p].type == type) {
        consume();
    } else {
        std::stringstream str;
        str << __FILE__ << " " << __func__ << ":" << __LINE__ << " expecting " << input.getStringName(type) << ",found " << LT(1).toString();
        throw std::runtime_error(str.str());
    }
}

void Parser::consume()
{
    lookAhead[p] = input.nextToken();
    p = (p + 1) % buf_size;
}

Token Parser::LT(int i)
{
    return lookAhead[(p + i -1) % buf_size]; 
}

int Parser::LA(int i)
{
    return LT(i).type; 
}
