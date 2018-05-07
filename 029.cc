#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int number = numbers.at(i);
            map<int, int>::iterator iter = m.find(number);
            if (iter->first == number)
                iter->second += 2;
            else
                m.insert(pair<int, int>(number, 2));
        }
        for (map<int, int>::iterator iter=m.begin(); iter!=m.end(); iter++)
        {
            if (iter->second > numbers.size())
                return iter->first;
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1};
    vector<int> vct(a, a+5);
    cout << (new Solution())->MoreThanHalfNum_Solution(vct) << endl;
    return 0;
}
