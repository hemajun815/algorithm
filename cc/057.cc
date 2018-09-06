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
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return this->isMirror(p->left, q->right) && this->isMirror(p->right, q->left);
    }

  public:
    bool isSymmetrical(TreeNode *pRoot)
    {
        if (!pRoot)
            return false;
        return this->isMirror(pRoot->left, pRoot->right);
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(1);
    p_root->left = new TreeNode(2);
    p_root->right = new TreeNode(2);
    p_root->left->left = new TreeNode(3);
    p_root->left->right = new TreeNode(4);
    p_root->right->left = new TreeNode(4);
    p_root->right->right = new TreeNode(3);
    std::cout << std::boolalpha << (new Solution())->isSymmetrical(p_root) << std::endl;
    std::cin.get();
    return 0;
}
