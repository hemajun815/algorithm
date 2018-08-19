#include <iostream>
#include <cstring>

class Solution
{
    char *chs;
    int rs, cs;
    bool *flag;
    int getIndex(const int &i, const int &j)
    {
        if (0 <= i && i < this->rs && 0 <= j && j < this->cs)
            return i * this->cs + j;
        return -1;
    }

  public:
    bool hasPath(char *matrix, int rows, int cols, char *str)
    {
        this->chs = matrix;
        this->rs = rows;
        this->cs = cols;
        this->flag = new bool[this->rs * this->cs];
        memset(this->flag, false, this->rs * this->cs);
        return false;
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
