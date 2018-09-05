#include <iostream>
using namespace std;

class Solution
{
  public:
    /**
     * 思路：
     * 用ones来记录只出现过一次的bits，用twos来记录只出现过两次的bits。
     * ones&twos实际上就记录了出现过三次的bits，
     * 这时候我们来模拟进行出现3次就抵消为0的操作，抹去ones和twos中都为1的bits。
     * */
    int singleNumber(int A[], int n)
    {
        int ones = 0; //记录只出现过1次的bits
        int twos = 0; //记录只出现过2次的bits
        int threes;
        for (int i = 0; i < n; i++)
        {
            int t = A[i];
            twos |= ones & t; //要在更新ones前面更新twos
            ones ^= t;
            threes = ones & twos; //ones和twos中都为1即出现了3次
            ones &= ~threes;      //抹去出现了3次的bits
            twos &= ~threes;
        }
        return ones;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {3, 2, 3, 2, 3, 2, 1, 4, 4, 4};
    cout << (new Solution())->singleNumber(a, sizeof a / sizeof a[0]) << endl; // 1
    cin.get();
    return 0;
}
