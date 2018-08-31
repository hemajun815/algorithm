#include <iostream>
#include <vector>

using namespace std;

void solution(int list[], int n, int start, int k, vector<vector<int>> *result)
{
    for (auto i = start; i < n; i++)
    {
        k -= list[i];
        if (k == 0)
        {
            result->push_back(vector<int>());
        }
        else
        {
            solution(list, n, i + 1, k, result);
        }
        k += list[i];
    }
}

void solution_core(const int *list, const int &n, const int &i, int *tmp, int j, int k, vector<vector<int>> *result)
{
    for (auto pos = i; pos < n; pos++)
    {
        k -= list[pos];
        tmp[j++] = pos;
        if (k > 0)
            solution_core(list, n, pos + 1, tmp, j, k, result);
        else if (k == 0)
        {
            result->push_back(vector<int>());
            for (auto i = 0; i < j; i++)
                result->back().push_back(tmp[i]);
        }
        k += list[pos];
        j--;
    }
}

vector<vector<int>> solution(const int *list, const int &n, const int &k)
{
    auto result = new vector<vector<int>>();
    auto tmp = new int[n]();
    solution_core(list, n, 0, tmp, 0, k, result);
    return *result;
}

int main(int argc, char const *argv[])
{
    auto x = 0, a = 0, y = 0, b = 0, k = 0;
    cin >> x >> a >> y >> b >> k;
    auto list = new int[x + y]();
    for (auto i = 0; i < x + y; i++)
        list[i] = i < x ? a : b;
    auto result = solution(list, x + y, k);
    cout << result.size() << endl;
    for (auto it = result.begin(); it != result.end(); it++)
    {
        for (auto i = it->begin(); i != it->end(); i++)
            cout << *i << ":" << list[*i] << "  ";
        cout << endl;
    }
    return 0;
}
