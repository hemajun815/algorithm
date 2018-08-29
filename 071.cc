#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
  public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        auto len = s.length();
        auto flags = new bool[len + 1]; // flags[i]: s[0, i]是否可分。
        for (auto i = 0u; i <= len; i++)
            flags[i] = false;
        flags[0] = true;
        for (auto pos = 1u; pos <= len; pos++) // flags[pos] = s[0, i] && s[i+1, pos]
        {
            for (auto i = 0u; i < pos; i++)
            {
                if (flags[i] && dict.find(s.substr(i, pos - i)) != dict.end())
                {
                    flags[pos] = true;
                    break;
                }
            }
        }
        return flags[len];
    }
};

int main(int argc, char const *argv[])
{
    string s = "leetcode";
    unordered_set<string> dict = {"leet", "code"};
    cout << boolalpha << (new Solution())->wordBreak(s, dict) << endl;
    cin.get();
    return 0;
}
