#include <iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        if(number == 0) return 0;
        int f1 = 1, f2 = 1;
        while(number--)
        {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f1;
    }
};

int main(int argc, char const *argv[])
{
    Solution * s = new Solution();
    cout << s->jumpFloor(0) << endl;
    cout << s->jumpFloor(1) << endl;
    cout << s->jumpFloor(2) << endl;
    cout << s->jumpFloor(3) << endl;
}