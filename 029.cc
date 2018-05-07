#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> m;
        int num = 0, count = 0;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int number = numbers.at(i);
            map<int, int>::iterator iter = m.find(number);
            if (iter->first == number)
            {
                iter->second += 2;
                if (iter->second > count)
                {
                    num = number;
                    count = iter->second;
                }
            }
            else
            {
                m.insert(pair<int, int>(number, 2));
                if (2 > count)
                {
                    num = number;
                    count = 2;
                }
            }
        }
        if (count > numbers.size())
            return num;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vct;
    vct.push_back(1);
    vct.push_back(2);
    vct.push_back(1);
    vct.push_back(3);
    vct.push_back(1);
    cout << (new Solution())->MoreThanHalfNum_Solution(vct) << endl;
    return 0;
}
