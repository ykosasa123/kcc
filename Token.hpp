#include <string>

class Token
{
public:
    int type;
    std::string text;
    
    Token(int type, std::string text);
    ~Token(void);
    std::string toString();

private:

};