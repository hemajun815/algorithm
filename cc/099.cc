#include <iostream>
#include <string>
using namespace std;

char findFirstRepeat(string A, int n)
{
    auto flag = new bool[128]();
    auto result = -1;
    for (auto i = 0; i < n; i++)
    {
        auto ch = A.at(i);
        if (flag[int(ch)])
        {
            result = ch;
            break;
        }
        else
            flag[int(ch)] = true;
    }
    delete[] flag;
    return result;
}

int main(int argc, char const *argv[])
{
    string str = "";
    cin >> str;
    cout << findFirstRepeat(str, str.length()) << endl;
    return 0;
}
