#include <iostream>
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

int main()
{
    Token tk(1, "test");

    assert_eq(tk.type, 1);
    assert_eq(tk.text, std::string("test"));
    assert_eq(tk.toString(), std::string("<'test',<EOF>>"));

    return 0;
}
