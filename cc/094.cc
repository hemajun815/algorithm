#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.size() > 0)
        {
            auto advance = true; // 进位标志
            auto it = digits.rbegin();
            while (advance && it != digits.rend())
            {
                *it = (*it + 1) % 10; // 当前位加1
                if (*it != 0)         // 更新进位标志
                    advance = false;
                it++;
            }
            if (advance) // 循环结束，进位标志仍然存在，最高位置1
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

void print(const vector<int> &vct)
{
    for (auto i : vct)
    {
        cout << i << "->";
    }
    cout << "null" << endl;
}

int main(int argc, char const *argv[])
{
    auto p = new Solution();
    vector<int> vct0 = {1, 2, 3, 4};
    print(vct0);
    print(p->plusOne(vct0)); // 1, 2, 3, 5
    vector<int> vct1 = {2, 4, 9, 9};
    print(vct1);
    print(p->plusOne(vct1)); // 2, 5, 0, 0
    vector<int> vct2 = {9, 9, 9};
    print(vct2);
    print(p->plusOne(vct2)); // 1, 0, 0, 0
    delete p;
    cin.get();
    return 0;
}
