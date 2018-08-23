#include <iostream>
#include <vector>
#include <ctime>
#include <random>

/**
 * 随机产生待排序数组
 * */
std::vector<int> random_data(const int &num_count)
{
    std::default_random_engine engine(time(NULL));
    std::uniform_int_distribution<int> distribution(0, 9);
    std::vector<int> vct(num_count);
    for (auto i = 0; i < num_count; i++)
        vct.at(i) = distribution(engine);
    return vct;
}

/**
 * 打印数组
 * */
void print(const std::vector<int> &vct)
{
    for (auto it = vct.begin(); it != vct.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

/**
 * 归并排序递归核心
 * */
void merge_sort_core(std::vector<int> &data, std::vector<int> tmp, const int &start, const int &end)
{
    if (start < end)
    {
        auto mid = start + (end - start) / 2;
        merge_sort_core(data, tmp, start, mid);   // 递归前半部分
        merge_sort_core(data, tmp, mid + 1, end); // 递归后半部分
        // 开始：合并前后两部分
        auto i = start, k = start, j = mid + 1;
        // 开始：循环取较小的放入tmp数组
        while (i != mid + 1 && j != end + 1)
        {
            if (data.at(i) > data.at(j))
                tmp.at(k++) = data.at(j++);
            else
                tmp.at(k++) = data.at(i++);
        }
        // 结束：循环取较小的放入tmp数组
        while (i != mid + 1) // 前半部分还有剩余
            tmp.at(k++) = data.at(i++);
        while (j != end + 1) // 后半部分还有剩余
            tmp.at(k++) = data.at(j++);
        // 结束：合并前后两部分
        for (auto idx = start; idx <= end; idx++) // 将排序好的数组拷贝到指定空间
            data.at(idx) = tmp.at(idx);
    }
}

/**
 * 归并排序
 * */
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

/**
 * 冒泡排序
 * */
std::vector<int> bubble_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    for (unsigned i = 0; i < ret->size(); i++)
        for (unsigned j = 0; j < ret->size() - i - 1; j++)
            if (ret->at(j) > ret->at(j + 1))
            {
                auto tmp = ret->at(j);
                ret->at(j) = ret->at(j + 1);
                ret->at(j + 1) = tmp;
            }
    return *ret;
}

/**
 * 选择排序
 * */
std::vector<int> selection_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    for (unsigned i = 0; i < ret->size(); i++)
    {
        auto idx = i;
        auto min = ret->at(i);
        for (unsigned j = i + 1; j < ret->size(); j++)
            if (ret->at(j) < min)
            {
                idx = j;
                min = ret->at(j);
            }
        auto tmp = ret->at(idx);
        ret->at(idx) = ret->at(i);
        ret->at(i) = tmp;
    }
    return *ret;
}

/**
 * 堆排序核心
 * */
void heap_sort_core(std::vector<int> &data, const int &start, const int &end)
{
    auto j = start;
    auto tmp = data.at(j);
    for (auto i = j * 2 + 1; i < end; i = i * 2 + 1)
    {
        if (i + 1 < end && data.at(i) < data.at(i + 1)) // 若右节点值大于左节点，i指向右节点。
            i++;
        if (data.at(i) > tmp) // 子节点大于父节点，将子节点赋值给父节点，并以子节点作为新的父节点。
        {
            data.at(j) = data.at(i);
            j = i;
        }
        else
            break;
    }
    data.at(j) = tmp;
}

/**
 * 堆排序
 * */
std::vector<int> heap_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    // 开始：构建大顶堆
    for (int i = ret->size() / 2 - 1; i >= 0; i--)
    {
        heap_sort_core(*ret, i, ret->size());
    }
    // 结束：构建大顶堆
    // 开始：调整堆结构
    for (auto i = ret->size() - 1; i > 0; i--)
    {
        // 开始：交换堆顶和末尾元素
        auto tmp = ret->at(0);
        ret->at(0) = ret->at(i);
        ret->at(i) = tmp;
        // 结束：交换堆顶和末尾元素
        heap_sort_core(*ret, 0, i);
    }
    // 结束：调整堆结构
    return *ret;
}

/**
 * 插入排序
 * */
std::vector<int> insertion_sort(const std::vector<int> &data)
{
    auto ret = new std::vector<int>(data.begin(), data.end());
    for (auto i = 1u; i < ret->size(); i++)
    {
        auto tmp = ret->at(i); // 记录有序部分后的一个数，作为待插入的元素。
        auto j = i;
        for (; j > 0 && ret->at(j - 1) > tmp; j--) // 从后往前循环，元素向后移动，直到不大于插入元素的位置。
        {
            ret->at(j) = ret->at(j - 1);
        }
        ret->at(j) = tmp; // 插入元素
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
    std::cout << "Bubble Sort: ";
    print(bubble_sort(data));
    std::cout << "Selection Sort: ";
    print(selection_sort(data));
    std::cout << "Heap Sort: ";
    print(heap_sort(data));
    std::cout << "Insertion Sort: ";
    print(insertion_sort(data));
    std::cin.get();
    return 0;
}
