#include <iostream>

class Solution
{
    int Sum1(const int &n)
    {
        int ret = n;
        ret && (ret += this->Sum1(n - 1));
        return ret;
    }

    int Sum2(const int &n)
    {
        char arr[n][n + 1];
        return sizeof arr >> 1;
    }

  public:
    int Sum_Solution(const int &n)
    {
        return this->Sum1(n);
        return this->Sum2(n);
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    std::cout << p->Sum_Solution(10) << std::endl;
    std::cout << p->Sum_Solution(4) << std::endl;
    return 0;
}
