#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> multiply(const std::vector<int> &A)
    {
        std::vector<int> B;
        for (unsigned i = 0; i < A.size(); i++)
        {
            int ret = 1;
            for (unsigned j = 0; j < A.size(); j++)
            {
                if (i == j)
                    continue;
                ret *= A[j];
            }
            B.push_back(ret);
        }
        return B;
    }
};

class Helper
{
  public:
    std::vector<int> create_vector(const int arr[], const int &len)
    {
        std::vector<int> in;
        for (int i = 0; i < len; i++)
            in.push_back(arr[i]);
        return in;
    }
    void print_vector(const std::vector<int> &vct)
    {
        for (unsigned i = 0; i < vct.size(); i++)
            std::cout << vct[i] << " ";
        std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Helper *helper = new Helper();
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> in = helper->create_vector(arr, sizeof arr / sizeof arr[0]);
    helper->print_vector(in);
    std::vector<int> out = (new Solution())->multiply(in);
    helper->print_vector(out);
    delete helper;
    std::cin.get();
    return 0;
}
