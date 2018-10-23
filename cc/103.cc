#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class BinTreeNode
{
  public:
    int value;
    BinTreeNode *lchild, *rchild;
    BinTreeNode(int const &val) : value(val), lchild(NULL), rchild(NULL)
    {
    }
};

class Helper
{
  public:
    static BinTreeNode *create_bin_tree()
    {
        BinTreeNode *root = new BinTreeNode(0);
        root->lchild = new BinTreeNode(1);
        root->rchild = new BinTreeNode(2);
        root->rchild->lchild = new BinTreeNode(3);
        root->rchild->rchild = new BinTreeNode(4);
        return root;
    }
    static BinTreeNode *create_bin_search_tree()
    {
        BinTreeNode *root = new BinTreeNode(10);
        root->lchild = new BinTreeNode(8);
        root->rchild = new BinTreeNode(20);
        root->rchild->lchild = new BinTreeNode(15);
        root->rchild->rchild = new BinTreeNode(25);
        return root;
    }
};

class Solution
{
  public:
    static bool solution1(BinTreeNode *const &root)
    {
        function<void(BinTreeNode *const &root, vector<int> &vct)> LDR;
        LDR = [&LDR](BinTreeNode *const &root, vector<int> &vct) {
            if (!root)
                return;
            LDR(root->lchild, vct);
            vct.push_back(root->value);
            LDR(root->rchild, vct);
        };
        vector<int> vct;
        LDR(root, vct);
        auto result = true;
        for (auto i = 0u; i + 1 < vct.size(); i++)
        {
            if (vct[i] >= vct[i + 1])
            {
                result = false;
                break;
            }
        }
        return result;
    }
    static bool solution2(BinTreeNode *const &root)
    {
        function<bool(BinTreeNode *const &root, int &last_visit)> LDR;
        LDR = [&LDR](BinTreeNode *const &root, int &last_visit) {
            if (!root)
                return true;
            if (!LDR(root->lchild, last_visit))
                return false;
            if (root->value <= last_visit)
                return false;
            last_visit = root->value;
            if (!LDR(root->rchild, last_visit))
                return false;
            return true;
        };
        int last_visit = INT_MIN;
        return LDR(root, last_visit);
    }
};

int main(int argc, char const *argv[])
{
    auto bTree = Helper::create_bin_tree();
    auto bsTree = Helper::create_bin_search_tree();
    cout << boolalpha << Solution::solution1(bTree) << endl;  // false
    cout << boolalpha << Solution::solution2(bTree) << endl;  // false
    cout << boolalpha << Solution::solution1(bsTree) << endl; // true
    cout << boolalpha << Solution::solution2(bsTree) << endl; // true
    return 0;
}
