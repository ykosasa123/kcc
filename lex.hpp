#pragma once
#include <string>
#include <vector>
#include <cstddef>

#include "Token.hpp"

class Lexer
{
public:
    Lexer(const char* in);
    ~Lexer();
    Token nextToken();
    const std::string& getStringName(int i);

private:
    std::size_t pos;
    char c;
    std::string input;
    const int _eof = 1;
    const int _name = 2;
    const int _comma = 3;
    const int _lbrack = 4;
    const int _rbrack = 5;
    const std::vector<std::string> tokenName = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

    void consume();
    void match(char x);
    bool isLettter();
    Token name();
    void ws();
};
