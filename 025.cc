#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<vector<int> > paths;
    vector<int> path;
public:
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
    {
        if (root)
        { 
            path.push_back(root->val);
            expectNumber -= root->val;
            if (!expectNumber && !root->left && !root->right)
            {
                vector<int> copy(this->path);
                this->paths.push_back(copy);
            }
            this->FindPath(root->left, expectNumber);
            this->FindPath(root->right, expectNumber);
            this->path.pop_back();
            expectNumber += root->val;
        }
        return this->paths;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode * pRoot = new TreeNode(0);
    pRoot->left = new TreeNode(3);
    pRoot->left->left = new TreeNode(2);
    pRoot->left->right = new TreeNode(6);
    pRoot->right = new TreeNode(4);
    pRoot->right->left = new TreeNode(5);
    pRoot->right->right = new TreeNode(1);
     /*
        0
       / \
      3   4
     / \ / \
     2 6 5 1
     */
    (new Solution())->FindPath(pRoot, 9);
    return 0;
}
