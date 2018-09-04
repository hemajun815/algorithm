#include <iostream>
using namespace std;

class Solution
{
  public:
    int singleNumber(int A[], int n)
    {
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {3, 2, 3, 2, 3, 2, 1, 4, 4, 4};
    cout << (new Solution())->singleNumber(a, sizeof a / sizeof a[0]) << endl; // 1
    return 0;
}
