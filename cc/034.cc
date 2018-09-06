#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;
        vector<int> numbers(index);
        numbers.at(0) = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; i++)
        {
            int tmp2 = numbers.at(t2) * 2;
            int tmp3 = numbers.at(t3) * 3;
            int tmp5 = numbers.at(t5) * 5;
            numbers.at(i) = min(tmp2, min(tmp3, tmp5));
            if (numbers.at(i) == tmp2)
                t2++;
            if (numbers.at(i) == tmp3)
                t3++;
            if (numbers.at(i) == tmp5)
                t5++;
        }
        return numbers.at(index - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    for (int i = 0; i < 100; i++)
        cout << p->GetUglyNumber_Solution(i) << endl;
    return 0;
}
