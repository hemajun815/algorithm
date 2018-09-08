#include <iostream>
using namespace std;

class Solution
{
  public:
    int jumpFloorII(int number)
    {
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;
        return 2 * this->jumpFloorII(number - 1);
    }
};
int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    cout << s->jumpFloorII(9) << endl;
    cin.get();
    return 0;
}
