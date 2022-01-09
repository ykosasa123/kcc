#include "lex.hpp"
#include "Token.hpp"

class Parser
{
public:
    Parser(Lexer lex);
    ~Parser() = default;
    void start();

private:
    Lexer input;
    Token lookAhead;

    void elements();
    void element();
    void match(int type);
    void consume();
};