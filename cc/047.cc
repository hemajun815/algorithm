#include <iostream>
#include <vector>
#include <climits>

class Solution
{
  public:
    std::vector<int> maxInWindows(const std::vector<int> &num, unsigned int size)
    {
        std::vector<int> *p_ret = new std::vector<int>();
        if (size > 0)
        {
            int max = INT32_MAX;
            for (unsigned i = 0; i + size <= num.size(); i++)
            {
                if (num.at(i + size - 1) >= max) // 新加入窗口的是最大值。
                {
                    max = num.at(i + size - 1);
                }
                else // 新加入窗口的不是最大值，循环窗口中元素寻找最大值。
                {
                    max = num.at(i);
                    for (unsigned j = 1; j < size; j++)
                    {
                        if (num.at(i + j) > max)
                            max = num.at(i + j);
                    }
                }
                p_ret->push_back(max);
            }
        }
        return *p_ret;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> *p_vct = new std::vector<int>();
    int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
    for (unsigned i = 0; i < sizeof arr / sizeof arr[0]; i++)
        p_vct->push_back(arr[i]);
    std::vector<int> out = (new Solution())->maxInWindows(*p_vct, 3);
    for (std::vector<int>::iterator it = out.begin(); it < out.end(); it++)
        std::cout << *it << std::endl;
    delete p_vct;
    std::cin.get();
    return 0;
}
