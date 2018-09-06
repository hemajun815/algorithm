#include <iostream>
#include <string>

class Solution
{
  public:
    std::string LeftRotateString(const std::string &str, const int &n)
    {
        if (n < 0 || n > str.length())
            return "";
        auto sub = str.substr(0, n);
        return str.substr(n) + sub;
    }
    std::string LeftRotateString2(const std::string &str, const int &n)
    {
        if (n < 0 || n > str.length())
            return "";
        return (str + str).substr(n, str.length());
    }
};

int main(int argc, char const *argv[])
{
    std::cout << (new Solution())->LeftRotateString2("abcXYZdef", 3) << std::endl;
    std::cin.get();
    return 0;
}
