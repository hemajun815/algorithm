#include <iostream>
using namespace std;

class Solution
{
  public:
    int removeElement(int A[], int n, int elem)
    {
        auto len = 0;
        if (n > 0)
        {
            auto count = 0;
            for (auto i = 0; i < n; i++)
            {
                if (A[i] == elem)
                    ++count;
                else
                {
                    A[i - count] = A[i];
                    ++len;
                }
            }
        }
        return len;
    }
    int removeElement2(int A[], int n, int elem)
    {
        for (auto i = 0; i < n; ++i)
        {
            if (A[i] == elem)
            {
                while (i < n && A[--n] == elem)
                    ;
                A[i] = A[n];
            }
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 2, 4, 5, 3, 2};
    cout << (new Solution())->removeElement2(arr, sizeof arr / sizeof arr[0], 2) << endl; // 4
    return 0;
}
