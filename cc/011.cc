#include <iostream>
using namespace std;

class Solution
{
  public:
    int NumberOf1(int n)
    {
        int count = 0;
        while (n)
        {
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    cout << p->NumberOf1(1) << endl;
    cout << p->NumberOf1(5) << endl;
    cout << p->NumberOf1(15) << endl;
    cout << p->NumberOf1(-1) << endl;
    cout << p->NumberOf1(-5) << endl;
    cout << p->NumberOf1(-15) << endl;
    return 0;
}