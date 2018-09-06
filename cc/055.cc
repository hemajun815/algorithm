#include <iostream>
#include <vector>

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
  public:
    std::vector<std::vector<int>> Print(TreeNode *pRoot)
    {
        auto out = new std::vector<std::vector<int>>();
        if (pRoot)
        {
            auto queue = new std::vector<TreeNode *>();
            TreeNode *p = pRoot;
            queue->push_back(pRoot);
            TreeNode *q = queue->back();
            auto tmp = new std::vector<int>();
            while (true)
            {
                auto cur = queue->front();
                queue->erase(queue->begin());
                if (cur->left)
                {
                    queue->push_back(cur->left);
                    q = queue->back();
                }
                if (cur->right)
                {
                    queue->push_back(cur->right);
                    q = queue->back();
                }
                tmp->push_back(cur->val);
                if (p == cur)
                {
                    if (out->size() % 2 == 1)
                        out->push_back(std::vector<int>(tmp->rbegin(), tmp->rend()));
                    else
                        out->push_back(std::vector<int>(tmp->begin(), tmp->end()));
                    tmp->clear();
                    if (queue->empty())
                        break;
                    p = q;
                }
            }
            delete tmp;
            delete queue;
        }
        return *out;
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(1);
    p_root->left = new TreeNode(2);
    p_root->right = new TreeNode(3);
    p_root->left->left = new TreeNode(4);
    p_root->left->right = new TreeNode(5);
    p_root->right->left = new TreeNode(6);
    p_root->right->right = new TreeNode(7);
    auto out = (new Solution())->Print(p_root);
    for (auto it1 = out.begin(); it1 < out.end(); it1++)
    {
        for (auto it2 = it1->begin(); it2 < it1->end(); it2++)
            std::cout << *it2;
        std::cout << std::endl;
    }
    std::cin.get();
    return 0;
}
