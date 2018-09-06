#include <iostream>
#include <vector>

class Solution
{
    int rs, cs;
    std::vector<std::vector<bool>> flags;
    int getSum(const int &n)
    {
        auto sum = 0;
        auto num = n;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    void count(const int &i, const int &j, const int &threshold)
    {
        if (this->getSum(i) + this->getSum(j) > threshold)
            return;
        this->flags[i][j] = true;
        if (i > 0 && !this->flags[i - 1][j])
            this->count(i - 1, j, threshold);
        if (j > 0 && !this->flags[i][j - 1])
            this->count(i, j - 1, threshold);
        if (i + 1 < this->rs && !this->flags[i + 1][j])
            this->count(i + 1, j, threshold);
        if (j + 1 < this->cs && !this->flags[i][j + 1])
            this->count(i, j + 1, threshold);
    }

  public:
    int movingCount(int threshold, int rows, int cols)
    {
        this->rs = rows;
        this->cs = cols;
        for (auto i = 0; i < this->rs; i++)
            this->flags.push_back(std::vector<bool>(this->cs, false));
        this->count(0, 0, threshold);
        auto sum = 0;
        for (auto i = 0; i < this->rs; i++)
            for (auto j = 0; j < this->cs; j++)
                if (this->flags[i][j])
                    sum++;
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << (new Solution())->movingCount(18, 100, 100) << std::endl;
    std::cin.get();
    return 0;
}
