#include <iostream>

int solution(int **&arr, const int &height, const int &width, const int &water)
{
    bool **flag = new bool *[height]();
    for (auto i = 0; i < height; i++)
        flag[i] = new bool[width]();
    auto count = 0;
    // 水从上面来
    for (auto i = 0; i < height; i++)
        for (auto j = 0; j < width; j++)
            if (!flag[i][j] && water >= arr[i][j] && (i == 0 || flag[i - 1][j]))
            {
                flag[i][j] = true;
                count++;
            }
    // 水从下面来
    for (auto i = height - 1; i >= 0; i--)
        for (auto j = 0; j < width; j++)
            if (!flag[i][j] && water >= arr[i][j] && (i == height - 1 || flag[i + 1][j]))
            {
                flag[i][j] = true;
                count++;
            }
    // 水从左边来
    for (auto j = 0; j < width; j++)
        for (auto i = 0; i < height; i++)
            if (!flag[i][j] && water >= arr[i][j] && (j == 0 || flag[i][j - 1]))
            {
                flag[i][j] = true;
                count++;
            }
    // 水从右边来
    for (auto j = width - 1; j >= 0; j--)
        for (auto i = 0; i < height; i++)
            if (!flag[i][j] && water >= arr[i][j] && (j == width - 1 || flag[i][j + 1]))
            {
                flag[i][j] = true;
                count++;
            }
    return height * width - count;
}

int main(int argc, char const *argv[])
{
    int **arr = new int *[2]();
    int arr0[][3] = {3, 3, 3, 4, 3, 3};
    for (auto i = 0; i < 2; i++)
    {
        arr[i] = new int[3]();
        for (auto j = 0; j < 3; j++)
            arr[i][j] = arr0[i][j];
    }
    /**
     * 2 3 3
     * 3 3 3
     * 4 3 3
     * */
    std::cout << solution(arr, 2, 3, 3) << std::endl; // 1
    delete[] arr;
    arr = new int *[3]();
    int arr1[][3] = {3, 4, 3, 6, 1, 5, 3, 5, 2};
    for (auto i = 0; i < 3; i++)
    {
        arr[i] = new int[3]();
        for (auto j = 0; j < 3; j++)
            arr[i][j] = arr1[i][j];
    }
    /**
     * 3 3 3
     * 3 4 3
     * 6 1 5
     * 3 5 2
     * */
    std::cout << solution(arr, 3, 3, 3) << std::endl; // 5
    delete[] arr;
    arr = new int *[5]();
    int arr2[][4] = {2, 5, 4, 1, 4, 1, 1, 5, 5, 1, 1, 4, 1, 4, 5, 2};
    for (auto i = 0; i < 4; i++)
    {
        arr[i] = new int[4]();
        for (auto j = 0; j < 4; j++)
            arr[i][j] = arr2[i][j];
    }
    /**
     * 4 4 3
     * 2 5 4 1
     * 4 1 1 5
     * 5 1 1 4
     * 1 4 5 2
     * */
    std::cout << solution(arr, 4, 4, 3) << std::endl; // 12
    delete[] arr;
    arr = new int *[5]();
    int arr3[][4] = {2, 5, 4, 1, 4, 1, 1, 5, 5, 1, 1, 4, 1, 2, 5, 2};
    for (auto i = 0; i < 4; i++)
    {
        arr[i] = new int[4]();
        for (auto j = 0; j < 4; j++)
            arr[i][j] = arr3[i][j];
    }
    /**
     * 4 4 3
     * 2 5 4 1
     * 4 1 1 5
     * 5 1 1 4
     * 1 2 5 2
     * */
    std::cout << solution(arr, 4, 4, 3) << std::endl; // 7
    delete[] arr;
    std::cin.get();
    return 0;
}
