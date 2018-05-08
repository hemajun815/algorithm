#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strings;
        for(int i = 0; i < numbers.size(); i++)
        {
            stringstream ss;
            ss << numbers.at(i);
            strings.push_back(ss.str());
        }
        sort(strings.begin(), strings.end(), [](string str1, string str2){
            if (!str1.compare(0, str2.length(), str2)) return true;
            return str1.compare(str2) < 0;
        });
        string str = "";
        for (int i = 0; i < strings.size(); i++)
        {
            str += strings.at(i);
        }
        return str;
    }
};


int main(int argc, char const *argv[])
{
    int a[] = {3, 32, 321};
    cout << (new Solution())->PrintMinNumber(vector<int>(a, a+3)) << endl;
    return 0;
}
