#include <iostream>
#include <list>

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
    int TreeDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        auto l = this->TreeDepth(pRoot->left);
        auto r = this->TreeDepth(pRoot->right);
        return 1 + (l > r ? l : r);
    }

    int TreeDepth2(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        auto queue = new std::list<TreeNode *>();
        queue->push_back(pRoot);
        auto p = pRoot;
        auto q = queue->back();
        int depth = 0;
        while (!queue->empty())
        {
            auto cur = queue->front();
            queue->pop_front();
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
            if (p == cur)
            {
                p = q;
                depth++;
            }
        }
        return depth;
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(1);
    p_root->right = new TreeNode(3);
    p_root->right->left = new TreeNode(6);
    p_root->right->right = new TreeNode(7);
    std::cout << (new Solution())->TreeDepth(p_root) << std::endl;
    std::cout << (new Solution())->TreeDepth2(p_root) << std::endl;
    std::cin.get();
    return 0;
}
