#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vct;
        if (root)
        {
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty())
            {
                TreeNode * node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                vct.push_back(node->val);
                delete node;
            }
        }
        return vct;
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
    vector<int> vct = (new Solution())->PrintFromTopToBottom(pRoot);
    for (int i = 0; i < vct.size(); i++)
        cout << vct.at(i) << endl;
    return 0;
}
