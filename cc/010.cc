#include <iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number <= 0) return 0;
        int f1 = 1, f2 = 2;
        while(--number)
        {
            f2 += f1;
            f1 = f2 - f1;
        }
        return f1;
    }
};

int main(int argc, char const *argv[])
{
    Solution * p = new Solution();
    cout << p->rectCover(1) << endl;
    cout << p->rectCover(3) << endl;
    cout << p->rectCover(5) << endl;
    return 0;
}