#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> vct;
        if (str.length())
        {
            this->Permutation(vct, str, 0);
            sort(vct.begin(), vct.end());
        }
        return vct;
    }

private:
    void Permutation(vector<string> &vct, string &str, int k)
    {
        if (k == str.length())
        {
            vct.push_back(string(str));
        }
        for (int i = k; i < str.length(); i++)
        {
            if (i != k && str.at(k) == str.at(i))
            {
                continue;
            }
            char ch = str.at(i);
            str.at(i) = str.at(k);
            str.at(k) = ch;
            this->Permutation(vct, str, k+1);
            str.at(k) = str.at(i);
            str.at(i) = ch;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<string> vct = (new Solution())->Permutation("aca");
    return 0;
}
