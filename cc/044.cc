#include <iostream>
#include <regex>

class Solution
{
  public:
    bool match2(const char *str, const char *pattern)
    {
        std::regex *r = new std::regex(pattern);
        bool ret = std::regex_match(str, *r);
        delete r;
        return ret;
    }
    bool match(char *str, char *pattern)
    {
        const char ch_last = '\0';
        const char ch_one = '.';
        const char ch_more = '*';
        if (*pattern == ch_last)
            if (*str == ch_last)
                return true;
            else
                return false;
        if (*(pattern + 1) == ch_more)
            if (*str == *pattern || (*str != ch_last && *pattern == ch_one))
                return this->match(str + 1, pattern) || this->match(str, pattern + 2);
            else
                return this->match(str, pattern + 2);
        else
        {
            if (*str == *pattern || (*str != ch_last && *pattern == ch_one))
                return this->match(str + 1, pattern + 1);
            else
                return false;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    std::cout << std::boolalpha << p->match("aaa", "a.a") << std::endl;     // true
    std::cout << std::boolalpha << p->match("aaa", "ab*ac*a") << std::endl; // true
    std::cout << std::boolalpha << p->match("aaa", "aa.a") << std::endl;    // false
    std::cout << std::boolalpha << p->match("aaa", "ab*a") << std::endl;    // false
    std::cin.get();
    return 0;
}
