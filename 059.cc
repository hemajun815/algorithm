#include <iostream>
#include <list>
#include <string>
#include <cmath>

class TreeNode
{
  public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(const int &x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
    const std::string elem_split = " ";
    const std::string null_elem = "N";
    int StrToInt(const std::string &str)
    {
        auto n = 0;
        auto count = 0.f;
        for (auto it = str.begin(); it < str.end(); it++)
            n += (*it - '0') * pow(10.f, count++);
        return n;
    }
    std::string IntToStr(const int &n)
    {
        std::string str = "";
        auto num = n;
        while (num)
        {
            str += (num % 10) + '0';
            num /= 10;
        }
        return str;
    }

  public:
    char *Serialize(TreeNode *root)
    {
        std::string str = "";
        if (root)
        {
            auto l = new std::list<TreeNode *>();
            l->push_back(root);
            while (true)
            {
                auto cur = l->front();
                l->pop_front();
                if (!cur)
                {
                    str += this->null_elem;
                    l->push_back(NULL);
                    l->push_back(NULL);
                }
                else
                {
                    l->push_back(cur->left);
                    l->push_back(cur->right);
                    str += this->IntToStr(cur->val);
                }
                str += this->elem_split;
                auto is_finish = true;
                for (auto it = l->begin(); it != l->end(); it++)
                    if (*it)
                    {
                        is_finish = false;
                        break;
                    }
                if (is_finish)
                    break;
            }
        }
        auto s = new char[str.length() + 1];
        str.copy(s, str.length());
        s[str.length()] = '\0';
        return s;
    }
    TreeNode *Deserialize(char *s)
    {
        std::string str(s);
        TreeNode *p = NULL;
        if (str.length() > 0)
        {
            auto l = new std::list<TreeNode *>();
            std::string::size_type pos0 = 0;
            std::string::size_type pos1 = str.find(this->elem_split, pos0);
            p = new TreeNode(this->StrToInt(str.substr(pos0, pos1 - pos0)));
            l->push_back(p);
            auto flag = true;
            while (true)
            {
                auto q = l->front();
                l->pop_front();
                pos0 = pos1 + 1;
                pos1 = str.find(this->elem_split, pos0);
                if (pos1 > str.length())
                    flag = false;
                auto left = flag ? str.substr(pos0, pos1 - pos0) : "";
                if (left == this->null_elem || left.length() == 0)
                {
                    if (q)
                        q->left = NULL;
                    l->push_back(NULL);
                }
                else
                {
                    q->left = new TreeNode(this->StrToInt(left));
                    l->push_back(q->left);
                }
                pos0 = pos1 + 1;
                pos1 = str.find(this->elem_split, pos0);
                if (pos1 > str.length())
                    flag = false;
                auto right = flag ? str.substr(pos0, pos1 - pos0) : "";
                if (right == this->null_elem || right.length() == 0)
                {
                    if (q)
                        q->right = NULL;
                    l->push_back(NULL);
                }
                else
                {
                    q->right = new TreeNode(this->StrToInt(right));
                    l->push_back(q->right);
                }
                auto is_finish = true;
                for (auto it = l->begin(); it != l->end(); it++)
                    if (*it)
                    {
                        is_finish = false;
                        break;
                    }
                if (is_finish)
                    break;
            }
        }
        return p;
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(1);
    p_root->right = new TreeNode(3);
    p_root->right->left = new TreeNode(6);
    p_root->right->right = new TreeNode(7);
    auto p = new Solution();
    auto str = p->Serialize(p_root);
    std::cout << str << std::endl;
    std::cout << std::boolalpha << (p->Deserialize(str)->val == p_root->val) << std::endl;
    delete p;
    std::cin.get();
    return 0;
}
