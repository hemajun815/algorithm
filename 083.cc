#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
    bool checkTransform(string start, string end)
    {
        auto result = false;
        if (start.length() == end.length())
        {
            auto count = 0;
            for (auto i = 0u; i < start.length(); i++)
            {
                if (start[i] != end[i])
                    ++count;
            }
            result = (count == 1);
        }
        return result;
    }

  public:
    /**
     * 1. 广度优先遍历；
     * 2. 删掉使用过的词；
     * */
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        auto q = new queue<string>();
        q->push(start);
        auto count = 1;
        while (!q->empty())
        {
            auto size = q->size();
            while (size--)
            {
                auto str = q->front();
                q->pop();
                if (this->checkTransform(str, end))
                {
                    delete q;
                    return count + 1;
                }
                for (auto it = dict.begin(); it != dict.end();)
                {
                    if (this->checkTransform(str, *it))
                    {
                        q->push(*it);
                        it = dict.erase(it);
                        continue;
                    }
                    it++;
                }
            }
            count++;
        }
        delete q;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    auto set0 = new unordered_set<string>({"hot", "dot", "dog", "lot", "log"});
    cout << (new Solution())->ladderLength("hit", "cog", *set0) << endl; // 5
    auto set1 = new unordered_set<string>({"hot", "dot", "dog", "lot", "log"});
    cout << (new Solution())->ladderLength("hit", "hmj", *set1) << endl; // 0
    auto set2 = new unordered_set<string>({"hot", "cog", "dot", "dog", "hit", "lot", "log"});
    cout << (new Solution())->ladderLength("hit", "cog", *set2) << endl; // 5
    cin.get();
    return 0;
}
