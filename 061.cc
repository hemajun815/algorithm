#include <iostream>
#include <cstring>

class Solution
{
    char **chs;
    bool **flags;
    int rs, cs;
    bool hasPath(const int &i, const int &j, char *str, const int &idx)
    {
        if (idx == strlen(str) - 1)
            return true;
        auto result = false;
        this->flags[i][j] = false;
        if (i > 0 && this->flags[i - 1][j] && this->chs[i - 1][j] == str[idx + 1])
            result = this->hasPath(i - 1, j, str, idx + 1);
        if (result)
            return result;
        if (j > 0 && this->flags[i][j - 1] && this->chs[i][j - 1] == str[idx + 1])
            result = this->hasPath(i, j - 1, str, idx + 1);
        if (result)
            return result;
        if (i + 1 < this->rs && this->flags[i + 1][j] && this->chs[i + 1][j] == str[idx + 1])
            result = this->hasPath(i + 1, j, str, idx + 1);
        if (result)
            return result;
        if (j + 1 < this->cs && this->flags[i][j + 1] && this->chs[i][j + 1] == str[idx + 1])
            result = this->hasPath(i, j + 1, str, idx + 1);
        if (result)
            return result;
        this->flags[i][j] = true;
        return result;
    }

  public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        if (strlen(str) == 0)
            return true;
        if (strlen(matrix) < strlen(str))
            return false;
        this->rs = rows;
        this->cs = cols;
        this->chs = new char *[this->rs];
        this->flags = new bool *[this->cs];
        for (int i = 0; i < this->rs; i++)
        {
            this->chs[i] = new char[this->cs];
            this->flags[i] = new bool[this->cs];
            for (int j = 0; j < this->cs; j++)
            {
                this->chs[i][j] = matrix[i * this->cs + j];
                this->flags[i][j] = true;
            }
        }
        auto result = false;
        for (auto i = 0; i < this->rs; i++)
        {
            for (auto j = 0; j < this->cs; j++)
            {
                if (this->chs[i][j] == str[0])
                    result = this->hasPath(i, j, str, 0);
                if (result)
                    break;
            }
            if (result)
                break;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    char *arr = "abcesfcsadee";
    auto p = new Solution();
    std::cout << std::boolalpha << p->hasPath(arr, 3, 4, "bcced") << std::endl;
    std::cout << std::boolalpha << p->hasPath(arr, 3, 4, "abcd") << std::endl;
    std::cin.get();
    return 0;
}
