#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::string ReverseSentence(std::string str)
    {
        const std::string ch = " ";
        std::vector<std::string> words;
        std::string::size_type pos0 = 0, pos1 = str.find(ch);
        while (std::string::npos != pos1)
        {
            words.push_back(str.substr(pos0, pos1 - pos0));
            pos0 = pos1 + ch.size();
            pos1 = str.find(ch, pos0);
        }
        words.push_back(str.substr(pos0, str.size() - pos0));
        std::string ret = words[words.size() - 1];
        for (int i = words.size() - 2; i >= 0; i--)
            ret += " " + words[i];
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << (new Solution())->ReverseSentence("student. a am I") << std::endl;
    std::cin.get();
    return 0;
}
