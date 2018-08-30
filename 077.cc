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
            auto count = 1;
            for (auto i = 1; i < n; i++)
            {
                if (A[i] == A[i - 1])
                {
                    ++count;
                    if (count <= 2)
                        A[len++] = A[i];
                }
                else
                {
                    A[len++] = A[i];
                    count = 1;
                }
            }
        }
        return len;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 1, 2, 2, 3};
    cout << (new Solution())->removeDuplicates(arr, sizeof arr / sizeof arr[0]) << endl; // 5
    cin.get();
    return 0;
}
