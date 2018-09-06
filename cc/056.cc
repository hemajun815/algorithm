#include <iostream>

class TreeLinkNode
{
  public:
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(const int &x) : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
  public:
    TreeLinkNode *GetNext(TreeLinkNode *pNode)
    {
        if (!pNode->right)
        {
            if (pNode->next)
            {
                if (pNode->next->left == pNode)
                    return pNode->next;
                else
                {
                    auto p = pNode->next;
                    while (p->next)
                    {
                        if (p == p->next->left)
                            return p->next;
                        p = p->next;
                    }
                    return NULL;
                }
            }
            else
                return NULL;
        }
        else
        {
            auto p = pNode->right;
            while (p->left)
            {
                p = p->left;
            }
            return p;
        }
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeLinkNode(1);
    auto p_root_left = new TreeLinkNode(2);
    p_root->left = p_root_left;
    p_root_left->next = p_root;
    auto p_root_right = new TreeLinkNode(3);
    p_root->right = p_root_left;
    p_root_right->next = p_root;
    auto p_root_left_left = new TreeLinkNode(4);
    p_root_left->left = p_root_left_left;
    p_root_left_left->next = p_root_left;
    auto p_root_left_right = new TreeLinkNode(5);
    p_root_left->right = p_root_left_right;
    p_root_left_right->next = p_root_left;
    auto p_root_right_left = new TreeLinkNode(6);
    p_root_right->left = p_root_right_left;
    p_root_right_left->next = p_root_right;
    auto p_root_right_right = new TreeLinkNode(7);
    p_root_right->right = p_root_right_right;
    p_root_right_right->next = p_root_right;
    std::cout << std::boolalpha << ((new Solution())->GetNext(p_root_left_left) == p_root_left) << std::endl;
    std::cout << std::boolalpha << ((new Solution())->GetNext(p_root_left_right) == p_root) << std::endl;
    std::cin.get();
    return 0;
}
