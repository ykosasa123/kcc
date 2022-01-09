#include <iostream>
#include <lex.hpp>
#include <Token.hpp>
#include <string>
#include <cassert>

template<typename T>
int assert_eq(T actual, T expected)
{
    if (actual != expected) {
        std::cout << __FILE__ << ":faild actual=" << actual <<  " expected=" <<  expected << std::endl;
        exit(-1); 
    }
    return 0;
}

void do_lex_correct_grammer()
{
    Lexer lex("[a, b]");

    Token tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'[',LBRACK>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'a',NAME>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<',',COMMA>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'b',NAME>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<']',RBRACK>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'<EOF>',<EOF>>"));
}

void do_lex_invalid_grammer()
{
    Lexer lex("[a123, b]");

    Token tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'[',LBRACK>"));
    tk = lex.nextToken();
    assert_eq(tk.toString(), std::string("<'a',NAME>"));
    try {
        tk = lex.nextToken();
    } catch (std::runtime_error& ex) {
        return;
    }

    exit(-1);
}

void do_getInputLength()
{
    Lexer lex("[abc]");

    assert_eq(lex.getInputLengh(), 5);
}

int main(int argc, char *argv[])
{
    do_lex_correct_grammer();

    do_lex_invalid_grammer();

    do_getInputLength();

    return 0;
}