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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (!pHead)
            return NULL;
        std::vector<ListNode *> pointers;
        pointers.push_back(pHead);
        ListNode *p = pHead->next;
        while (p)
        {
            std::vector<ListNode *>::iterator it = std::find(pointers.begin(), pointers.end(), p->next);
            if (it != pointers.end())
                return *it;
            pointers.push_back(p);
            p = p->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *pHead = new ListNode(0);
    ListNode *p1 = new ListNode(1);
    pHead->next = p1;
    ListNode *p2 = new ListNode(2);
    p1->next = p2;
    ListNode *p3 = new ListNode(3);
    p2->next = p3;
    p3->next = p1;
    std::cout << std::boolalpha << (p1 == (new Solution())->EntryNodeOfLoop(pHead)) << std::endl;
    std::cin.get();
    return 0;
}
