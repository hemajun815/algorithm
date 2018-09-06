#include <iostream>
using namespace std;

class Solution
{
  public:
    /**
     * 异或操作：相同两个数异或为0，任何数与0异或还是自身。
     * */
    int singleNumber(int A[], int n)
    {
        while (--n, n > 0)
            A[n - 1] ^= A[n];
        return A[0];
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {2, 3, 4, 3, 4, 2, 5, 0, 5};
    cout << (new Solution())->singleNumber(a, sizeof a / sizeof a[0]) << endl; // 0
    cin.get();
    return 0;
}
