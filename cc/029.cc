#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        auto result = 0;
        if (!numbers.empty())
        {
            auto count = 0;
            for (auto it = numbers.begin(); it != numbers.end(); it++)
            {
                result = count == 0 ? *it : result;
                count = result == *it ? count + 1 : count - 1;
            }
            count = 0;
            for (auto it = numbers.begin(); it != numbers.end(); it++)
                count = *it == result ? count + 1 : count;
            result = count * 2 > (int)numbers.size() ? result : 0;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vct0 = {1, 2, 1, 3, 1};
    cout << (new Solution())->MoreThanHalfNum_Solution(vct0) << endl; // 1
    vector<int> vct1 = {1, 2, 2, 3, 1};
    cout << (new Solution())->MoreThanHalfNum_Solution(vct1) << endl; // 0
    return 0;
}
