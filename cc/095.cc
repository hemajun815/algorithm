#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    bool isNumber(const char *s)
    {
        auto str = string(s);
        if (0u == str.length()) // 字符串为空，返回false
            return false;
        // 去除字符串前后空格（trim）
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        auto number = false;          // 是否出现过数字
        auto eOrE = false;            // 是否出现过e或者E
        auto numberAfterE = false;    // e或者E后面是否有数字
        auto sign = false;            // 是否出现过+或者-
        auto numberAfterSign = false; // +或者-后面是否有数字
        auto point = false;           // 是否出现过小数点
        // 循环每个字符
        for (auto i = 0u; i < str.length(); i++)
        {
            auto ch = str.at(i);
            // 数字
            if ('0' <= ch && ch <= '9')
            {
                numberAfterE = eOrE;
                numberAfterSign = sign;
                number = true;
            }
            // e或者E
            else if (ch == 'e' || ch == 'E')
            {
                // 第二个E/e，返回false
                if (eOrE)
                    return false;
                // 没有出现过数字
                if (!number)
                    return false;
                eOrE = true;
            }
            // +或者-
            else if (ch == '+' || ch == '-')
            {
                // +/-不在首位或者前一位不是E/e
                if (i != 0 && str.at(i - 1) != 'e' && str.at(i - 1) != 'E')
                    return false;
                sign = true;
            }
            // 小数点
            else if (ch == '.')
            {
                // 第二个小数点，返回false
                if (point)
                    return false;
                // E/e后面不允许小数点
                if (eOrE)
                    return false;
                point = true;
            }
            // 非法字符，返回false
            else
                return false;
        }
        // 最后保证合法
        if (eOrE && !numberAfterE)
            return false;
        if (sign && !numberAfterSign)
            return false;
        return number;
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    cout << boolalpha << p->isNumber("+123") << endl;       // true
    cout << boolalpha << p->isNumber(".") << endl;          // false
    cout << boolalpha << p->isNumber("+-123") << endl;      // false
    cout << boolalpha << p->isNumber("1.23") << endl;       // true
    cout << boolalpha << p->isNumber("1.2.3") << endl;      // false
    cout << boolalpha << p->isNumber("1e23") << endl;       // true
    cout << boolalpha << p->isNumber("4e.9-") << endl;      // false
    cout << boolalpha << p->isNumber("2e+60++604") << endl; // false
    cout << boolalpha << p->isNumber("1a2.3") << endl;      // false
    cout << boolalpha << p->isNumber("-1E-3") << endl;      // true
    cout << boolalpha << p->isNumber("12e+3") << endl;      // true
    cout << boolalpha << p->isNumber(".e1") << endl;        // false
    cout << boolalpha << p->isNumber("6e6.5") << endl;      // false
    cout << boolalpha << p->isNumber("-.123") << endl;      // true
    cin.get();
    return 0;
}
