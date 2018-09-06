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
    std::vector<TreeNode *> nodes;
    void LNR(TreeNode *node)
    {
        if (!node)
            return;
        this->LNR(node->left);
        this->nodes.push_back(node);
        this->LNR(node->right);
    }

  public:
    TreeNode *KthNode(TreeNode *pRoot, int k)
    {
        if (k < 1)
            return NULL;
        this->LNR(pRoot);
        if (this->nodes.size() >= unsigned(k))
            return this->nodes.at(k - 1);
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    auto p_root = new TreeNode(4);
    p_root->left = new TreeNode(2);
    p_root->right = new TreeNode(6);
    p_root->left->left = new TreeNode(1);
    p_root->left->right = new TreeNode(3);
    p_root->right->left = new TreeNode(5);
    p_root->right->right = new TreeNode(7);
    std::cout << std::boolalpha << ((new Solution())->KthNode(p_root, 3) == p_root->left->right) << std::endl;
    std::cin.get();
    return 0;
}
