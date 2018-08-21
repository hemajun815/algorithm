#include <iostream>
#include <vector>
#include <ctime>
#include <random>

std::vector<int> random_data(const int &num_count)
{
    std::default_random_engine engine(time(NULL));
    std::uniform_int_distribution<int> distribution(0, 9);
    std::vector<int> vct(num_count);
    for (auto i = 0; i < num_count; i++)
        vct.at(i) = distribution(engine);
    return vct;
}

void print(const std::vector<int> &vct)
{
    for (auto it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void merge_sort_core(std::vector<int> &data, std::vector<int> tmp, const int &start, const int &end)
{
    if (start < end)
    {
        auto mid = start + (end - start) / 2;
        merge_sort_core(data, tmp, start, mid);
        merge_sort_core(data, tmp, mid + 1, end);
        auto i = start, k = start, j = mid + 1;
        while (i != mid + 1 && j != end + 1)
        {
            if (data.at(i) > data.at(j))
                tmp.at(k++) = data.at(j++);
            else
                tmp.at(k++) = data.at(i++);
        }
        while (i != mid + 1)
            tmp.at(k++) = data.at(i++);
        while (j != end + 1)
            tmp.at(k++) = data.at(j++);
        for (auto idx = start; idx <= end; idx++)
            data.at(idx) = tmp.at(idx);
    }
}

std::vector<int> merge_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    if (data.size() > 0)
    {
        auto tmp = new std::vector<int>(data.size());
        merge_sort_core(*ret, *tmp, 0, data.size() - 1);
        delete tmp;
    }
    return *ret;
}

int main(int argc, char const *argv[])
{
    const auto num_count = 15;
    auto data = random_data(num_count);
    std::cout << "Original input: ";
    print(data);
    std::cout << "Merge Sort: ";
    print(merge_sort(data));
    std::cin.get();
    return 0;
}
