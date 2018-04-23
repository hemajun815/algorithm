#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void process(TreeNode * src, TreeNode * dest)
    {
        if (src->left)
        {
            dest->right = new TreeNode(src->left->val);
            process(src->left, dest->right);
        }
        if (src->right)
        {
            dest->left = new TreeNode(src->right->val);
            process(src->right, dest->left);
        }
        delete src;
    }
    void Mirror(TreeNode *pRoot) {
        if (pRoot)
        {
            TreeNode * dest = new TreeNode(pRoot->val);
            process(pRoot, dest);
            pRoot->left = dest->left;
            pRoot->right = dest->right;
            delete dest;
        }
    }
};

int main(int argc, char const *argv[])
{
    TreeNode * pRoot = new TreeNode(0);
    pRoot->left = new TreeNode(1);
    pRoot->left->left = new TreeNode(2);
    pRoot->left->right = new TreeNode(3);
    pRoot->right = new TreeNode(4);
    pRoot->right->left = new TreeNode(5);
    pRoot->right->right = new TreeNode(6);
    /*
       0
      / \
     1   4
    / \ / \
    2 3 5 6
    */
   (new Solution())->Mirror(pRoot);
    /*
       0
      / \
     4   1
    / \ / \
    6 5 3 2
    */
    return 0;
}
