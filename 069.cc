#include <iostream>

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
    int run(TreeNode *root)
    {
        auto depth = 0;
        if (root)
        {
            auto left = this->run(root->left);
            auto right = this->run(root->right);
            if (left == 0 || right == 0)
                depth = 1 + left + right;
            else
                depth = left < right ? left + 1 : right + 1;
        }
        return depth;
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(4);
    p_root->left = new TreeNode(2);
    p_root->right = new TreeNode(6);
    p_root->right->left = new TreeNode(5);
    p_root->right->right = new TreeNode(7);
    std::cout << std::boolalpha << ((new Solution())->run(p_root) == 2) << std::endl;
    std::cin.get();
    return 0;
}
