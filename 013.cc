#include <iostream>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        double abs_exponent = exponent > 0 ? exponent : -exponent;
        double ret = 1.0;
        while(abs_exponent--)
        {
            ret *= base;
        }
        return exponent > 0 ? ret : 1/ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution * p = new Solution();
    cout << p->Power(4.0, -1) << endl;
    cout << p->Power(2.0, -4) << endl;
    cout << p->Power(2.0, 4) << endl;
    cout << p->Power(4.0, 4) << endl;
    cout << p->Power(3.0, 10) << endl;
    return 0;
}