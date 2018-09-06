#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = gas.size() - 1, end = 0, remain = gas[start] - cost[start];
        while (start > end)
            if (remain > 0)
                remain += gas[end] - cost[end++];
            else
                remain += gas[--start] - cost[start];
        return remain < 0 ? -1 : start;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> gas = {2, 3, 5, 2, 1};
    vector<int> cost = {3, 2, 2, 1, 4};
    cout << (new Solution())->canCompleteCircuit(gas, cost) << endl; // 1
    cin.get();
    return 0;
}
