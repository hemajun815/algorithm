#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> vct;
        int len = input.size();
        if (len > 0 && k <= len)
        {
            QuickSort(input, 0, input.size()-1);
            for (int i=0; i<k; ++i)
            {
                vct.push_back(input.at(i));
            }
        }
        return vct;
    }
private:
    void QuickSort(vector<int> &vct, const int & start, const int & end)
    {
        if (start < end)
        {
            int i = start, j = end, tmp = vct.at(i);
            while (i < j)
            {
                while (i < j && tmp <= vct.at(j)) --j;
                if (i < j) vct.at(i++) = vct.at(j);
                while (i < j && tmp >= vct.at(i)) ++i;
                if (i < j) vct.at(j--) = vct.at(i);
            }
            vct.at(i) = tmp;
            this->QuickSort(vct, start, i-1);
            this->QuickSort(vct, i+1, end);
        }
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> vct_in(a, a+8);
    vector<int> vct_out = (new Solution())->GetLeastNumbers_Solution(vct_in, 4);
    for (int i=0; i<vct_out.size(); ++i)
    {
        cout << vct_out.at(i) << endl;
    }
    return 0;
}
