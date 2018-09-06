#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    std::vector<char> history;

  public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        std::vector<char>::iterator it = std::find(this->history.begin(), this->history.end(), ch);
        if (it == this->history.end())
            this->history.push_back(ch);
        else
            this->history.erase(it);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int ch = '#';
        if (this->history.size() > 0)
            ch = this->history.front();
        return ch;
    }
};

int main(int argc, char const *argv[])
{
    Solution *p = new Solution();
    std::cout << p->FirstAppearingOnce() << std::endl;
    p->Insert('g');
    p->Insert('o');
    std::cout << p->FirstAppearingOnce() << std::endl;
    p->Insert('o');
    p->Insert('g');
    p->Insert('l');
    p->Insert('e');
    std::cout << p->FirstAppearingOnce() << std::endl;
    std::cin.get();
    return 0;
}
