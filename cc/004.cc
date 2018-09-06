#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
}TreeNode;

TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin, int start_pre, int end_pre, int strat_vin, int end_vin)
{
    if (start_pre > end_pre || strat_vin > end_vin)
    {
        return NULL;
    }
    else
    {
        TreeNode * root = new TreeNode();
        root->val = pre[start_pre];
        for (int i = strat_vin; i <= end_vin; ++i)
        {
            if (vin[i] == pre[start_pre])
            {
                root->left = reConstructBinaryTree(pre, vin, start_pre + 1, start_pre + i - strat_vin, strat_vin, i - 1);
                root->right = reConstructBinaryTree(pre, vin, start_pre + 1 + i - strat_vin, end_pre, i + 1, end_vin);
                break;
            }
        }
        return root;
    }
}

TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    return reConstructBinaryTree(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
}

int main(int argc, char const *argv[])
{
    int arr_pre[] = {1,2,4,7,3,5,6,8};
    int arr_vin[] = {4,7,2,1,5,3,8,6};
    vector<int> pre(arr_pre, arr_pre + 8);
    vector<int> vin(arr_vin, arr_vin + 8);
    TreeNode * header = reConstructBinaryTree(pre, vin);
    return 0;
}