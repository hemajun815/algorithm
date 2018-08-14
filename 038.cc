#include <iostream>
#include <regex>

class Solution
{
  public:
    bool isNumeric(const char *string)
    {
        std::regex *r1 = new std::regex("^[+-]?\\d*\\.?\\d*$");                           // 基本数字
        std::regex *r2 = new std::regex("^[+-]?[0-9]*\\.[0-9]*[eE]{1}[+-]?[1-9][0-9]*$"); // 带小数点的科学表达式
        std::regex *r3 = new std::regex("^[+-]?[1-9][0-9]*[eE]{1}[+-]?[1-9][0-9]*$");     // 不带小数点的科学表达式
        bool is_match = std::regex_match(string, *r1) || std::regex_match(string, *r2) || std::regex_match(string, *r3);
        delete r1;
        delete r2;
        delete r3;
        return is_match;
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    std::cout << std::boolalpha << p->isNumeric("+123") << std::endl;  // true
    std::cout << std::boolalpha << p->isNumeric("-123") << std::endl;  // true
    std::cout << std::boolalpha << p->isNumeric("+-123") << std::endl; // false
    std::cout << std::boolalpha << p->isNumeric("1.23") << std::endl;  // true
    std::cout << std::boolalpha << p->isNumeric("1.2.3") << std::endl; // false
    std::cout << std::boolalpha << p->isNumeric("1e23") << std::endl;  // true
    std::cout << std::boolalpha << p->isNumeric("12e") << std::endl;   // false
    std::cout << std::boolalpha << p->isNumeric("1a2.3") << std::endl; // false
    std::cout << std::boolalpha << p->isNumeric("-1E-3") << std::endl; // true
    std::cout << std::boolalpha << p->isNumeric("12e+3") << std::endl; // true
    std::cout << std::boolalpha << p->isNumeric("-.123") << std::endl; // true
    return 0;
}
