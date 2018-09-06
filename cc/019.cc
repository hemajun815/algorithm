#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int> > matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
            cout << matrix.at(i).at(j) << " ";
        cout << endl;
    }
}

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        ret.insert(ret.end(), matrix.at(0).begin(), matrix.at(0).end());
        matrix.erase(matrix.begin());
        if (matrix.size() > 0)
        {
            vector<vector<int> > new_matrix;
            for (int i = matrix.at(0).size() - 1; i >= 0; i--)
            {
                vector<int> row;
                for (int j = 0; j < matrix.size(); j++)
                    row.push_back(matrix.at(j).at(i));
                new_matrix.push_back(row);
            }
            vector<int> next_ret = printMatrix(new_matrix);
            ret.insert(ret.end(), next_ret.begin(), next_ret.end());
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > vct;
    for (int i = 0; i < 4; i++)
    {
        vector<int> row;
        for (int j = 0; j < 4; j++)
            row.push_back(i * 4 + j + 1);
        vct.push_back(row);
    }
    print(vct);
    vector<int> ret = (new Solution())->printMatrix(vct);
    vct.clear();
    vct.push_back(ret);
    print(vct);
    return 0;
}
