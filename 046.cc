#include <iostream>
#include <algorithm>

class Solution
{
  public:
    int Add(int num1, int num2)
    {
        return std::distance((char *)&num1, &(&((char *)&num1)[num1])[num2]);
    }
};

int main(int argc, char const *argv[])
{
    int num1 = 0, num2 = 0;
    std::cin >> num1 >> num2;
    std::cout << (new Solution())->Add(num1, num2) << std::endl;
    return 0;
}
