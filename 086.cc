#include <iostream>

int solution(int **&arr, const int &height, const int &width, const int &water)
{
    bool **flag = new bool *[height]();
    for (auto i = 0; i < height; i++)
        flag[i] = new bool[width]();
    auto count = 0;
    for (auto i = 0; i < height; i++)
    {
        for (auto j = 0; j < width; j++)
        {
            if (water >= arr[i][j])
            {
                auto up = ((i == 0 || flag[i - 1][j]));          // 水从上面来
                auto down = (i == height - 1 || flag[i + 1][j]); // 水从下面来
                auto left = (j == 0 || flag[i][j - 1]);          // 水从左边来
                auto right = (j == width - 1) || flag[i][j + 1]; // 水从右边来
                if (up || down || left || right)
                {
                    flag[i][j] = true;
                    count++;
                }
            }
        }
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
    std::cin.get();
    return 0;
}
