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
        if (!pHead)
            return NULL;
        std::vector<int> history;
        history.push_back(pHead->val);
        std::vector<bool> flag;
        flag.push_back(true);
        ListNode *p = pHead->next;
        while (p)
        {
            std::vector<int>::iterator result = std::find(history.begin(), history.end(), p->val);
            if (result != history.end())
            {
                int idx = std::distance(history.begin(), result);
                flag[idx] = false;
                flag.push_back(false);
            }
            else
                flag.push_back(true);
            history.push_back(p->val);
            p = p->next;
        }
        for (int i = flag.size() - 1; i >= 0; i--)
        {
            if (!flag[i])
                history.erase(history.begin() + i);
        }
        if (history.size() == 0)
            return NULL;
        ListNode *newList = new ListNode(history[0]);
        p = newList;
        for (unsigned i = 1; i < history.size(); i++)
        {
            ListNode *q = new ListNode(history[i]);
            p->next = q;
            p = p->next;
        }
        return newList;
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
