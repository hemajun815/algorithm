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
    int sumNumbers(TreeNode *node, int sum)
    {
        if (!node)
            return 0;
        sum = sum * 10 + node->val;
        if (!node->left && !node->right)
            return sum;
        return this->sumNumbers(node->left, sum) + this->sumNumbers(node->right, sum);
    }

  public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        if (root)
            sum = this->sumNumbers(root, sum);
        return sum;
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
    cout << (new Solution())->sumNumbers(p_root) << endl; // 124 + 125 + 136 + 137
    cin.get();
    return 0;
}
