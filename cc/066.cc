#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
  public:
    void FindNumsAppearOnce(std::vector<int> data, int *num1, int *num2)
    {
        auto max = std::max_element(data.begin(), data.end());
        auto min = std::min_element(data.begin(), data.end());
        auto counts = new std::vector<int>(*max - *min + 1, 0);
        for (auto it = data.begin(); it != data.end(); it++)
            counts->at(*it - *min)++;
        auto pos = std::find(counts->begin(), counts->end(), 1);
        *num1 = std::distance(counts->begin(), pos) + *min;
        pos = std::find(pos + 1, counts->end(), 1);
        *num2 = std::distance(counts->begin(), pos) + *min;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 3, 4, 4, 2, 5};
    auto vct = new std::vector<int>(arr, arr + sizeof arr / sizeof arr[0]);
    auto num1 = new int(), num2 = new int();
    (new Solution())->FindNumsAppearOnce(*vct, num1, num2);
    std::cout << *num1 << std::endl
              << *num2 << std::endl;
    std::cin.get();
    return 0;
}
