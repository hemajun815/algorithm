#include <iostream>
#include <string>
using namespace std;

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        string result = "";
        auto advance = 0;
        // 从后面向前循环，按位操作
        int i = a.length() - 1, j = b.length() - 1;
        while (i >= 0 || j >= 0 || advance > 0)
        {
            auto tmp = advance;
            if (i >= 0)
                tmp += a.at(i--) - '0';
            if (j >= 0)
                tmp += b.at(j--) - '0';
            advance = tmp / 2;
            result += ('0' + tmp % 2);
        }
        return string(result.rbegin(), result.rend());
    }
};

int main(int argc, char const *argv[])
{
    cout << ((new Solution())->addBinary("11", "1")) << endl; // 100
    cin.get();
    return 0;
}
