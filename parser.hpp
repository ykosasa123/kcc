#include "lex.hpp"
#include "Token.hpp"

class Parser
{
public:
    Parser(Lexer lex, int k);
    ~Parser() = default;
    void start();

private:
    Lexer input;
    std::vector<Token> lookAhead;
    int buf_size;
    int p;

    void elements();
    void element();
    void match(int type);
    void consume();
    Token LT(int i);
    int LA(int i);
};