#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
    int pow(const int &base, const int &exp)
    {
        auto ret = 1;
        for (auto i = 0; i < exp; i++)
            ret *= base;
        return ret;
    }
    bool str_to_int(const string &str, int &v)
    {
        v = 0;
        bool is_positive = true;
        string s = str;
        if (str.at(0) == '+')
        {
            is_positive = true;
            s = str.substr(1);
        }
        else if (str.at(0) == '-')
        {
            is_positive = false;
            s = str.substr(1);
        }
        auto count = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            if ('0' <= *it && *it <= '9')
            {
                v += (*it - '0') * this->pow(10, count++);
                continue;
            }
            v = 0;
            return false;
        }
        v = is_positive ? v : -v;
        return true;
    }

  public:
    int evalRPN(vector<string> &tokens)
    {
        auto stack = new vector<int>();
        auto tmp = 0;
        auto num1 = 0, num2 = 0;
        for (auto it = tokens.begin(); it != tokens.end(); it++)
        {
            if (it->compare("+") == 0)
            {
                num2 = stack->back();
                stack->pop_back();
                num1 = stack->back();
                stack->pop_back();
                stack->push_back(num1 + num2);
            }
            else if (it->compare("-") == 0)
            {
                num2 = stack->back();
                stack->pop_back();
                num1 = stack->back();
                stack->pop_back();
                stack->push_back(num1 - num2);
            }
            else if (it->compare("*") == 0)
            {
                num2 = stack->back();
                stack->pop_back();
                num1 = stack->back();
                stack->pop_back();
                stack->push_back(num1 * num2);
            }
            else if (it->compare("/") == 0)
            {
                num2 = stack->back();
                stack->pop_back();
                num1 = stack->back();
                stack->pop_back();
                stack->push_back(num1 / num2);
            }
            else if (this->str_to_int(*it, tmp))
            {
                stack->push_back(tmp);
            }
            else
                return 0;
        }
        return stack->size() == 1 ? stack->front() : 0;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> test1 = {"2", "1", "+", "3", "*"};
    vector<string> test2 = {"4", "13", "5", "/", "+"};
    auto p = new Solution();
    cout << p->evalRPN(test1) << endl;
    cout << p->evalRPN(test2) << endl;
    delete p;
    cin.get();
    return 0;
}
