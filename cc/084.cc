#include <iostream>
using namespace std;

/**
 * 思路：
 * 令连续2m个数字为一组，则整个数组共n/2m组。
 * 对于每个组内部，前m个数字为负，后m个数字为正。
 * 任取第i组：-(im+1)-(im+2)-...-(im+m)+(im+m+1)+(im+m+2)+...+(im+m+m)=m*m。
 * 则前n项和为：(n/2m) * (m*m) = n / 2 * m。
 * */
unsigned long solution(const unsigned long &n, const unsigned long &m)
{
    return n / 2 * m;
}

int main(int argc, char const *argv[])
{
    auto n = 0uL, m = 0ul;
    cin >> n >> m;
    cout << solution(n, m) << endl;
    return 0;
}
