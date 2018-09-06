#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
  public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:
    //        true if the input is valid, and there are some duplications in the array number, otherwise false
    bool duplicate(int numbers[], int length, int *duplication)
    {
        if (length > 0)
        {
            std::vector<int> vct;
            for (int i = 0; i < length; i++)
            {
                if (std::find(vct.begin(), vct.end(), numbers[i]) == vct.end())
                    vct.push_back(numbers[i]);
                else
                {
                    *duplication = numbers[i];
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 1, 0, 2, 5, 3};
    int len = sizeof arr / sizeof arr[0];
    int *duplication = new int();
    bool is_duplicated = (new Solution())->duplicate(arr, len, duplication);
    std::cout << std::boolalpha << is_duplicated << std::endl;
    if (is_duplicated)
        std::cout << *duplication << std::endl;
    return 0;
}
