#include <string>
#include <vector>

class Lexer
{
private:
    enum class type : int
    {
        NAME = 2,
        COMMA = 3,
        LBRACK = 4,
        RBRACK = 5,
    };
    std::string input;
    std::vector<std::string> tokenName = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBEACK"};

public:
    Lexer(const char* in);
    ~Lexer();
    std::string& getStringName(int i);

};
