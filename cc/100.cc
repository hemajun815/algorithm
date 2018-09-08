/**
 * 题目：
 * 定义三种符号：[]表示可选，<>表示必选，|表示或者。
 * 判断给定字符串是否满足三种符号组成的表达式。
 * 如“abcde”满足“<a[b|bc]>[d]e”。
 * */
#include <iostream>
#include <string>
#include <list>

char const ch_and = '&';
char const ch_or = '|';
char const ch_null = '#';

/**
 * 处理正则表达式
 * */
std::string process(std::string const &str)
{
    std::string tmp = "";
    for (auto i = 0u; i < str.size(); i++)
    {
        auto ch = str[i];
        if (ch == '[' || ch == '<' || ch == '>')
            tmp += ch_and;
        else if (ch == ']')
        {
            tmp += ch_or;
            tmp += ch_null;
            tmp += ch_and;
        }
        else
            tmp += ch;
    }
    auto result = tmp.substr(0, 1);
    for (auto it = tmp.begin() + 1; it != tmp.end(); it++)
    {
        if (*it != result.back())
            result += *it;
    }
    return result;
}

/**
 * 使用处理后的正则表达式生成DAG
 * */
std::list<std::list<std::string> *> *create_dag(std::string const &reg)
{
    auto dag = new std::list<std::list<std::string> *>();
    std::size_t start = reg.find_first_not_of(ch_and), end = reg.find(ch_and, start);
    end = end > reg.size() ? reg.size() : end;
    if (end > reg.size())
        end = reg.size();
    while (start < reg.size())
    {
        dag->push_back(new std::list<std::string>());
        auto tmp = reg.substr(start, end - start);
        std::size_t pos0 = tmp.find_first_not_of(ch_or), pos1 = tmp.find(ch_or, pos0);
        pos1 = pos1 > tmp.size() ? tmp.size() : pos1;
        while (pos0 < tmp.size())
        {
            auto chs = tmp.substr(pos0, pos1 - pos0);
            dag->back()->push_back(chs);
            pos0 = pos1 + 1;
            pos1 = tmp.find(ch_or, pos0);
            pos1 = pos1 > tmp.size() ? tmp.size() : pos1;
        }
        start = end + 1;
        end = reg.find(ch_and, start);
        end = end > reg.size() ? reg.size() : end;
    }
    return dag;
}

/**
 * 使用DAG递归检测输入字符串是否匹配
 * */
bool check_core(std::string const &str, unsigned const &pos, std::list<std::list<std::string> *>::iterator const &start, std::list<std::list<std::string> *>::iterator const &end)
{
    if (start == end && pos == str.length())
        return true;
    if (start != end && pos != str.length())
    {
        for (auto iter = (*start)->begin(); iter != (*start)->end(); iter++)
        {
            if (0 == str.substr(pos, iter->length()).compare(*iter))
            {
                auto it = start;
                auto result = check_core(str, pos + iter->length(), ++it, end);
                if (result)
                    return result;
            }
        }
    }
    return false;
}

/**
 * 使用DAG检测输入字符串是否匹配
 * */
bool check(std::string const &str, std::list<std::list<std::string> *> *const &dag)
{
    return check_core(str, 0, dag->begin(), dag->end());
}

int main(int argc, char const *argv[])
{
    std::string str = "abcde";
    std::string reg = "<a[b|bc]>[d]e";
    auto process_reg = process(reg);
    auto dag = create_dag(process_reg);
    std::cout << std::boolalpha << check(str, dag) << std::endl;
    delete dag;
    return 0;
}
