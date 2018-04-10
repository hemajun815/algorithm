#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> * vct_odd = new vector<int>();
        vector<int> * vct_even = new vector<int>();
        for (vector<int>::iterator i = array.begin(); i != array.end(); i++)
        {
            if (*i % 2 == 0)
                vct_even->push_back(*i);
            else
                vct_odd->push_back(*i);
        }
        array.clear();
        for (vector<int>::iterator i = vct_odd->begin(); i != vct_odd->end(); i++)
            array.push_back(*i);
        for (vector<int>::iterator i = vct_even->begin(); i != vct_even->end(); i++)
            array.push_back(*i);
    }
};

int main(int argc, char const *argv[])
{
    Solution * p = new Solution();
    vector<int> * vct = new vector<int>();
    for (int i = 1; i <= 7; i++)
        vct->push_back(i);
    p->reOrderArray(*vct);
    for (vector<int>::iterator i = vct->begin(); i != vct->end(); i++)
        cout << *i << endl;
    return 0;
}