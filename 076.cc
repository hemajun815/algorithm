#include <iostream>

using namespace std;

class Solution
{
  public:
    int removeDuplicates(int A[], int n)
    {
        auto len = 0;
        if (n > 0)
        {
            len = 1;
            for (auto i = 1; i < n; i++)
            {
                if (A[i] != A[i - 1])
                {
                    A[len++] = A[i];
                }
            }
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 2, 3, 3, 4};
    cout << (new Solution())->removeDuplicates(arr, sizeof arr / sizeof arr[0]) << endl; // 4
    cin.get();
    return 0;
}
