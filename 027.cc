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
    vector<TreeNode*> m_vct;
    void PreOrder(TreeNode * node)
    {
        if (node)
        {
            this->PreOrder(node->left);
            this->m_vct.push_back(node);
            this->PreOrder(node->right);
        }
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return NULL;
        this->PreOrder(pRootOfTree);
        TreeNode * pList = this->m_vct.at(0);
        TreeNode * p = pList;
        p->left = NULL;
        for (int i=1; i<this->m_vct.size(); i++)
        {
            TreeNode * q = this->m_vct.at(i);
            p->right = q;
            q->left = p;
            p = q;
        }
        p->right = NULL;
        return pList;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode * pRoot = new TreeNode(3);
    pRoot->left = new TreeNode(1);
    pRoot->left->left = new TreeNode(0);
    pRoot->left->right = new TreeNode(2);
    pRoot->right = new TreeNode(5);
    pRoot->right->left = new TreeNode(4);
    pRoot->right->right = new TreeNode(6);
    /*
        3
       / \
      1   5
     / \ / \
     0 2 4 6
    */
    TreeNode * pList = (new Solution())->Convert(pRoot);
    return 0;
}
