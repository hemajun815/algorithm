#include <iostream>

using namespace std;

class Solution
{
  public:
    int search(int A[], int n, int target)
    {
        auto left = 0, right = n - 1;
        while (left <= right)
        {
            auto mid = left + (right - left) / 2;
            if (A[mid] == target)
                return mid;
            if (A[left] <= A[mid])
            {
                if (A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (A[mid] < target && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1};
    cout << (new Solution())->search(arr, sizeof arr / sizeof arr[0], 1) << endl; // 1
    cin.get();
    return 0;
}
