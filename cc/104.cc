#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        auto max = 0;
        if (!prices.empty())
        {
            auto min = prices.at(0);
            for (auto i = 1u; i < prices.size(); i++)
            {
                if (prices.at(i) < min)
                    min = prices.at(i);
                else
                {
                    auto tmp = prices.at(i) - min;
                    if (tmp > max)
                        max = tmp;
                }
            }
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {6, 5, 3, 8, 10, 7};
    vector<int> prices(arr, arr + sizeof arr / sizeof arr[0]);
    cout << (new Solution())->maxProfit(prices) << endl; // 7
    return 0;
}
