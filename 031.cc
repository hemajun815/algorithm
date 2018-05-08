#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int num = 0x80000000;
        int cur_sum = array.at(0);
        for(int i = 1; i < array.size(); i++)
        {
            if (cur_sum > 0)
                cur_sum += array.at(i);
            else
                cur_sum = array.at(i);
            if (cur_sum > num)
                num = cur_sum;
        }        
        return num;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {-2,-8,-1,-5,-9};
    cout << (new Solution())->FindGreatestSumOfSubArray(vector<int>(a, a+5)) << endl;
    int b[] = {6,-3,-2,7,-15,1,2,2};
    cout << (new Solution())->FindGreatestSumOfSubArray(vector<int>(b, b+8)) << endl;
    return 0;
}
