#include <iostream>

using namespace std;

class Solution
{
  public:
    int FirstNotRepeatingChar(string str)
    {
        const int max_len = 10000;
        const int num_len = 'z' - 'A' + 1;
        int idx[num_len];
        for (int i = 0; i < num_len; i++)
            idx[i] = max_len;
        int count[num_len] = {0};
        for (int i = 0; i < str.length(); i++)
        {
            idx[str.at(i) - 'A'] = i;
            count[str.at(i) - 'A']++;
        }
        int min = max_len;
        for (int i = 0; i < num_len; i++)
            if (count[i]==1 && min > idx[i]) 
                min = idx[i];
        return min==max_len ? -1 : min;
    }
};

int main(int argc, char const *argv[])
{
    cout << (new Solution())->FirstNotRepeatingChar("kYVmIJVzYWPQLtIdKMmvkVSoKtqJANOfCCOfLVJEjjhbnPrDOwKCDeqhts") << endl;
    return 0;
}
