#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        sum -= root->val;
        if (sum == 0 && !root->left && !root->right)
            return true;
        return this->hasPathSum(root->left, sum) || this->hasPathSum(root->right, sum);
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
    cout << boolalpha << (new Solution())->hasPathSum(p_root, 8) << endl; // true: 1 + 2 + 5 = 8
    cin.get();
    return 0;
}
