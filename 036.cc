#include <iostream>
#include <regex>
#include <cmath>

using namespace std;

class Solution
{
    int CharArrayToInt(const char *arr, const int &start, const int &end)
    {
        int ret = 0;
        for (int i = end - 1; i >= start; i--)
            ret += (arr[i] - '0') * pow(10, end - 1 - i);
        return ret;
    }

  public:
    int StrToInt(string str)
    {
        regex *r = new regex("^[+-]?[0-9]+$");
        if (regex_match(str, *r))
        {
            if (str.data()[0] == '+')
                return this->CharArrayToInt(str.data(), 1, strlen(str.data()));
            else if (str.data()[0] == '-')
                return -this->CharArrayToInt(str.data(), 1, strlen(str.data()));
            else
                return this->CharArrayToInt(str.data(), 0, strlen(str.data()));
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution *solution = new Solution();
    cout << solution->StrToInt("+123") << endl;
    cout << solution->StrToInt("123") << endl;
    cout << solution->StrToInt("-123") << endl;
    cout << solution->StrToInt("+12a3") << endl;
    return 0;
}
