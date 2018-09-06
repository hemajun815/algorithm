#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
  public:
    bool IsContinuous(const std::vector<int> &numbers)
    {
        if (numbers.size() != 5)
            return false;
        int count_zero = 0;
        for (auto it = numbers.begin(); it < numbers.end(); it++)
            if (*it == 0)
                count_zero++;
        if (count_zero >= 4)
            return true;
        auto max = std::max_element(numbers.begin(), numbers.end());
        if (*max < 5)
            return false;
        for (int i = *max - 1; i > *max - 5; i--)
        {
            if (std::find(numbers.begin(), numbers.end(), i) != numbers.end())
                continue;
            else
            {
                count_zero--;
                if (count_zero < 0)
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 0, 0, 5};
    std::vector<int> *p_vct = new std::vector<int>();
    for (unsigned i = 0; i < sizeof arr / sizeof arr[0]; i++)
        p_vct->push_back(arr[i]);
    std::cout << std::boolalpha << (new Solution())->IsContinuous(*p_vct) << std::endl;
    std::cin.get();
    return 0;
}
