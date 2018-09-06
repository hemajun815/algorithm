#include <iostream>
#include <vector>

class Solution
{
    std::vector<int> data;

  public:
    void Insert(int num)
    {
        bool is_ok = false;
        for (unsigned i = 0; i < this->data.size(); i++)
        {
            if (this->data.at(i) > num)
            {
                this->data.insert(this->data.begin() + i, num);
                is_ok = true;
                break;
            }
        }
        if (!is_ok)
            this->data.push_back(num);
    }

    double GetMedian()
    {
        unsigned len = this->data.size();
        if (len == 0)
            return 0;
        else if (len % 2 == 1)
            return this->data.at(len / 2);
        else
            return double(this->data.at(len / 2 - 1) + this->data.at(len / 2)) / 2;
    }
};

int main(int argc, char const *argv[])
{
    Solution *solution = new Solution();
    int arr[] = {1, 3, 4, 5, 2, 6, 0, 7};
    for (unsigned i = 0; i < sizeof arr / sizeof arr[0]; i++)
        solution->Insert(arr[i]);
    std::cout << solution->GetMedian() << std::endl;
    delete solution;
    std::cin.get();
    return 0;
}
