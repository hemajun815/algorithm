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
    int InversePairsByMergeSort(std::vector<int> &data, const int &start, const int &end)
    {
        if (start < end)
        {
            auto mid = start + (end - start) / 2;
            auto left = this->InversePairsByMergeSort(data, start, mid);
            auto right = this->InversePairsByMergeSort(data, mid + 1, end);
            auto count = (left + right) % this->mod;
            auto tmp = new std::vector<int>(end - start + 1);
            auto k = 0, i = start, j = mid + 1;
            while (i != mid + 1 && j != end + 1)
            {
                if (data.at(i) > data.at(j))
                {
                    tmp->at(k++) = data.at(j++);
                    count = (count + (mid - i + 1)) % this->mod;
                }
                else
                    tmp->at(k++) = data.at(i++);
            }
            while (i != mid + 1)
                tmp->at(k++) = data.at(i++);
            while (j != end + 1)
                tmp->at(k++) = data.at(j++);
            for (unsigned idx = 0; idx < tmp->size(); idx++)
                data.at(start + idx) = tmp->at(idx);
            return count;
        }
        return 0;
    }

  public:
    int InversePairs(std::vector<int> data)
    {
        if (data.size() == 0)
            return 0;
        // return this->InversePairs(data, 0);
        // return this->InversePairs(data, 0, data.size());
        return this->InversePairsByMergeSort(data, 0, data.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575};
    auto data = new std::vector<int>(arr, arr + sizeof arr / sizeof arr[0]);
    std::cout << (new Solution())->InversePairs(*data) << std::endl;
    std::cin.get();
    return 0;
}
