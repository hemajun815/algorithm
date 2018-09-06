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
            out->push_back(std::vector<int>());
            TreeNode *p = NULL, *q = pRoot;
            auto queue = new std::vector<TreeNode *>();
            queue->push_back(pRoot);
            p = queue->back();
            while (true)
            {
                auto cur = queue->front();
                queue->erase(queue->begin());
                if (cur->left)
                {
                    queue->push_back(cur->left);
                    p = queue->back();
                }
                if (cur->right)
                {
                    queue->push_back(cur->right);
                    p = queue->back();
                }
                out->back().push_back(cur->val);
                if (cur == q)
                {
                    if (queue->size() == 0)
                        break;
                    q = p;
                    out->push_back(std::vector<int>());
                }
            }
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
