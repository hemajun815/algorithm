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
    bool IsBalanced_Solution(TreeNode *pRoot, int &depth)
    {
        if (!pRoot)
        {
            depth = 0;
            return true;
        }
        auto left = 0, right = 0;
        if (this->IsBalanced_Solution(pRoot->left, left) && this->IsBalanced_Solution(pRoot->right, right))
        {
            auto d = left > right ? left - right : right - left;
            if (d < 2)
            {
                depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }

  public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        auto depth = 0;
        return this->IsBalanced_Solution(pRoot, depth);
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(1);
    p_root->right = new TreeNode(3);
    p_root->right->left = new TreeNode(6);
    p_root->right->right = new TreeNode(7);
    std::cout << std::boolalpha << (new Solution())->IsBalanced_Solution(p_root) << std::endl;
    std::cin.get();
    return 0;
}
