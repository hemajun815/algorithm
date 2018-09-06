#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    /**
     * 1 2   y=0    2 1   y=x    3 1
     * 3 4  =====>  4 3  =====>  4 2
     * 
     * 
     * 1 2 3       3 2 1       7 4 1
     * 4 5 6  ==>  6 5 4  ==>  8 5 2
     * 7 8 9       9 8 7       9 6 3
     * */
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        auto tmp = 0;
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n / 2; j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = tmp;
            }
        }
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < n - i - 1; j++)
            {
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][n - i - 1];
                matrix[n - j - 1][n - i - 1] = tmp;
            }
        }
    }
};

class Helper
{
  public:
    static void printMatrix(const vector<vector<int>> &matrix)
    {
        for (auto row = matrix.begin(); row != matrix.end(); row++)
        {
            for (auto col = row->begin(); col != row->end(); col++)
            {
                cout << *col << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    auto matrix = new vector<vector<int>>();
    matrix->push_back({1, 2, 3});
    matrix->push_back({4, 5, 6});
    matrix->push_back({7, 8, 9});
    Helper::printMatrix(*matrix);
    (new Solution())->rotate(*matrix);
    Helper::printMatrix(*matrix);
    matrix->clear();
    delete matrix;
    cin.get();
    return 0;
}
