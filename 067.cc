#include <iostream>
#include <vector>

class Solution
{
    const int mod = 1000000007;
    int InversePairs(const std::vector<int> &data, const unsigned &start)
    {
        auto count = 0;
        if (start != data.size() - 1)
        {
            for (auto i = start + 1; i != data.size(); i++)
                if (data.at(start) > data.at(i))
                    count = (count + 1) % this->mod;
            count = (count + this->InversePairs(data, start + 1)) % this->mod;
        }
        return count;
    }

    int InversePairs(const std::vector<int> &data, const int &start, const int &end)
    {
        if (start == end - 1)
            return 0;
        auto mid = (end - start) / 2 + start;
        auto left = this->InversePairs(data, start, mid);
        auto right = this->InversePairs(data, mid, end);
        auto count = 0;
        for (auto i = start; i < mid; i++)
            for (auto j = mid; j < end; j++)
                if (data[i] > data[j])
                    count = (count + 1) % this->mod;
        return (left + right + count) % this->mod;
    }

  public:
    int InversePairs(std::vector<int> data)
    {
        if (data.size() == 0)
            return 0;
        // return this->InversePairs(data, 0);
        return this->InversePairs(data, 0, data.size());
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 0};
    auto data = new std::vector<int>(arr, arr + sizeof arr / sizeof arr[0]);
    std::cout << (new Solution())->InversePairs(*data) << std::endl;
    std::cin.get();
    return 0;
}
