#include <iostream>
#include <vector>

class Solution
{
  private:
    int BiSearch(const std::vector<int> &data, const float &num)
    {
        int s = 0, e = data.size() - 1;
        while (s <= e)
        {
            int m = (e - s) / 2 + s;
            if (data.at(m) < num)
                s = m + 1;
            else if (data.at(m) > num)
                e = m - 1;
        }
        return s;
    }

  public:
    int GetNumberOfK(std::vector<int> data, int k)
    {
        return this->BiSearch(data, k + 0.1) - this->BiSearch(data, k - 0.1);
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 4, 5};
    std::cout << (new Solution())->GetNumberOfK(std::vector<int>(arr, arr + sizeof arr / sizeof arr[0]), 5);
    std::cin.get();
    return 0;
}
