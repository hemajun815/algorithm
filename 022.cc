#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty() || pushV.size() != popV.size()) return false;
        vector<int> stack;
        for (int i = 0, j = 0; i < pushV.size(); i++)
        {
            stack.push_back(pushV.at(i));
            while(j < popV.size() && stack.back() == popV[j])
            {
                stack.pop_back();
                j++;
            }
        }
        return stack.empty();
    }
};

int main(int argc, char const *argv[])
{
    int pushV_initializer[] = {1, 2, 3, 4, 5};
    vector<int> pushV(pushV_initializer, pushV_initializer + 5);
    int popV1_initializer[] = {4, 5, 3, 2, 1};
    vector<int> popV1(popV1_initializer, popV1_initializer + 5);
    int popV2_initializer[] = {4, 3, 5, 1, 2};
    vector<int> popV2(popV2_initializer, popV2_initializer + 5);
    Solution * p = new Solution();
    cout << p->IsPopOrder(pushV, popV1) << endl;
    cout << p->IsPopOrder(pushV, popV2) << endl;
    delete p;
    return 0;
}
