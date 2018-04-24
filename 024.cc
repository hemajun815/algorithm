#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool Verify(const vector<int> & sequence, const int & start, const int & end)
    {
        if (start >= end) return true;
        int idx = start;
        while(idx < end && sequence.at(idx) < sequence.at(end))
            ++idx;
        for (int i=idx; i<end; i++)
            if(sequence.at(i) <= sequence.at(end))
                return false;
        return this->Verify(sequence, start, idx-1) && this->Verify(sequence, idx, end-1);
    }
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        return this->Verify(sequence, 0, sequence.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    /*
        3
       / \
      1   5
     / \ / \
     0 2 4 6
    */
    int sequence[] = {0, 2, 1, 4, 6, 5, 3};
    vector<int> vct(sequence, sequence+7);
    cout << (new Solution())->VerifySquenceOfBST(vct) << endl;
    return 0;
}
