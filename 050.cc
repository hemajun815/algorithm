#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<std::vector<int>> FindContinuousSequence(const int &sum)
    {
        auto p_out = new std::vector<std::vector<int>>();
        for (int i = sum / 2 + 1; i > 1; i--)
        {
            int flag = sum / i, left = sum % i;
            if (i % 2 == 1 && left == 0 && flag - i / 2 > 0)
            {
                auto p_v = new std::vector<int>();
                for (int j = 0; j < i; j++)
                    p_v->push_back(flag - i / 2 + j);
                p_out->push_back(*p_v);
            }
            if (i % 2 == 0 && left == i / 2 && flag - i / 2 + 1 > 0)
            {
                auto p_v = new std::vector<int>();
                for (int j = 0; j < i; j++)
                    p_v->push_back(flag - i / 2 + j + 1);
                p_out->push_back(*p_v);
            }
        }
        return *p_out;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> out = (new Solution)->FindContinuousSequence(1);
    for (auto i = out.begin(); i < out.end(); i++)
    {
        for (auto j = i->begin(); j < i->end(); j++)
            std::cout << *j << "\t";
        std::cout << std::endl;
    }
    std::cin.get();
    return 0;
}
