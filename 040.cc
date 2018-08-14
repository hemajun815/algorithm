#include <iostream>
#include <vector>
#include <algorithm>

class ListNode
{
  public:
    int val;
    ListNode *next;
    ListNode(const int &x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    ListNode *deleteDuplication(ListNode *pHead)
    {
        std::vector<int> history;
        std::vector<ListNode *> pointer;
        ListNode *pre = pHead, *p = pHead->next;
        history.push_back(pHead->val);
        while (p)
        {
            if (std::find(history.begin(), history.end(), p->val) != history.end())
            {
                pointer.push_back(pre);
            }
            else
            {
                history.push_back(p->val);
            }
            pre = p;
            p = p->next;
        }
        for (unsigned i = 0; i < pointer.size(); i++)
        {
            ListNode *p = pointer[i];
            ListNode *q = p->next;
            p->next = q->next;
            delete q;
        }
        return pHead;
    }
};

class Helper
{
  public:
    ListNode *createList(const int arr[], const int &n)
    {
        ListNode *pHead = new ListNode(arr[0]);
        ListNode *p = pHead;
        for (int i = 1; i < n; i++)
        {
            ListNode *q = new ListNode(arr[i]);
            p->next = q;
            p = p->next;
        }
        return pHead;
    }
    void printList(ListNode *&pHead)
    {
        ListNode *p = pHead;
        while (p)
        {
            std::cout << p->val;
            p = p->next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Helper *helper = new Helper();
    int vals[] = {1, 2, 3, 3, 4, 4, 5};
    ListNode *pHead = helper->createList(vals, sizeof vals / sizeof vals[0]);
    helper->printList(pHead);
    ListNode *newList = (new Solution())->deleteDuplication(pHead);
    helper->printList(newList);
    delete helper;
    return 0;
}
