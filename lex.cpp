#include <stdexcept>
#include <sstream>

#include "lex.hpp"

Lexer::Lexer(const char* in) : pos(0), c(0)
{
    input = in;
    c = input.at(0);
}

const std::string& Lexer::getStringName(int i)
{
    return tokenName[i];
}

void Lexer::consume()
{
    pos++;
    if (input.length() <= pos) {
        c = _eof;
    } else {
        c = input.at(pos);
    }
}

void Lexer::match(char x)
{
    if (c == x) {
        consume();
    } else {
        std::stringstream str;
        str << "expecting " << x <<  "found " << c;
        throw std::runtime_error(str.str());
    }
}

bool Lexer::isLettter()
{
    return std::isalpha(c);
}

Token Lexer::name()
{
    std::vector<char> buf;
    do {
        buf.push_back(c);
        consume();
    } while (isLettter());

    return Token(_name, buf.data());
}

void Lexer::ws()
{
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        consume();
    }
}

Token Lexer::nextToken()
{
    while (c != _eof) {
        switch (c) {
            case ' ': case '\t': case '\r':
                ws();
                continue;
            case ',':
                consume();
                return Token(_comma, ",");
            case '[':
                consume();
                return Token(_lbrack, "[");
            case ']':
                consume();
                return Token(_rbrack, "]");
            default:
                if (isLettter()) {
                    return name();
                } else {
                    std::stringstream str;
                    str << "invalid character " << c;
                    throw std::runtime_error(str.str());
                }
        }
    }
    return Token(_eof, "<EOF>");
}
