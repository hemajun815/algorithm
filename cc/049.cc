#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> FindNumbersWithSum(const std::vector<int> &array, const int &sum)
    {
        auto p_ret = new std::vector<int>();
        unsigned left = 0, right = array.size() - 1;
        if (sum > array[left] * 2 && sum < array[right] * 2)
        {
            while (left < right)
            {
                auto tmp = array[left] + array[right];
                if (tmp == sum)
                {
                    p_ret->push_back(array[left]);
                    p_ret->push_back(array[right]);
                    break;
                }
                else if (tmp > sum)
                    right--;
                else
                    left++;
            }
        }
        return *p_ret;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> *p_vct = new std::vector<int>();
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6};
    for (unsigned i = 0; i < sizeof arr / sizeof arr[0]; i++)
        p_vct->push_back(arr[i]);
    std::vector<int> out = (new Solution())->FindNumbersWithSum(*p_vct, 7);
    for (std::vector<int>::iterator it = out.begin(); it < out.end(); it++)
        std::cout << *it << std::endl;
    delete p_vct;
    std::cin.get();
    return 0;
}
