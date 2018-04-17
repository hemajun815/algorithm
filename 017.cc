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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool flag = false;
        if (pRoot1 && pRoot2)
        {
            if (pRoot1->val == pRoot2->val) flag = this->IsSubtree(pRoot1, pRoot2);
            if (!flag) flag = this->HasSubtree(pRoot1->left, pRoot2);
            if (!flag) flag = this->HasSubtree(pRoot1->right, pRoot2);
        }
        return flag;
    }
    bool IsSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        if (pRoot1->val != pRoot2->val) return false;
        return this->IsSubtree(pRoot1->left, pRoot2->left) && this->IsSubtree(pRoot1->right, pRoot2->right);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode * pRoot1 = new TreeNode(0);
    pRoot1->left = new TreeNode(1);
    pRoot1->right = new TreeNode(2);
    TreeNode * pRoot2 = new TreeNode(1);
    cout << (new Solution())->HasSubtree(pRoot1, pRoot2) << endl;
    return 0;
}
