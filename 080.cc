#include <iostream>

using namespace std;

void solution(const int &dividend, const int &divisor)
{
    auto a = dividend, b = divisor;
    // 循环去掉整数部分。
    auto c = a % b;
    while (a > b)
    {
        a = c;
        c = a % b;
    }

    auto cs = new int[b]();  // 记录余数。
    auto pos = new int[b](); // 记录余数的位置。
    auto count = 0;          // 记录当前小数长度。

    // 循环产生余数作为新的被除数。
    while (c != 0)
    {
        if (cs[c] == 1) // 出现重复的余数。
        {
            cout << pos[c] << " " << count - pos[c] << endl;
            return;
        }
        cs[c] = 1;
        pos[c] = count++;
        a = c * 10;
        c = a % b;
    }
    cout << count << " 0" << endl;
}

int main(int argc, char const *argv[])
{
    auto dividend = 0, divisor = 0;
    cin >> dividend >> divisor;
    solution(dividend, divisor);
    return 0;
}
