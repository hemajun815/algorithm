#include <iostream>
#include <vector>

class Solution
{
  public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n <= 0 || m <= 0)
            return -1;
        auto p_vct = new std::vector<int>();
        for (int i = 0; i < n; i++)
            p_vct->push_back(i);
        int idx_n = 0, idx_m = 0;
        while (p_vct->size() != 1)
        {
            if (idx_m == m - 1)
            {
                p_vct->erase(p_vct->begin() + idx_n);
                idx_m = 0;
            }
            idx_n = (idx_n + 1) % p_vct->size();
            idx_m++;
        }
        return p_vct->at(0);
    }
};

int main(int argc, char const *argv[])
{
    std::cout << (new Solution())->LastRemaining_Solution(0, 4) << std::endl;
    std::cin.get();
    return 0;
}
