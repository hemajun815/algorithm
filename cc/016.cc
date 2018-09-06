#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode * pHead3 = pHead1->val < pHead2->val ? pHead1 : pHead2;
        pHead3->next = pHead1->val < pHead2->val ? this->Merge(pHead1->next, pHead2) : this->Merge(pHead1, pHead2->next);
        return pHead3;
    }
};

int main(int argc, char const *argv[])
{
    int vals1[] = {1, 2, 3, 5, 7, 9};
    ListNode * l1 = new ListNode(vals1[0]);
    ListNode * p = l1;
    for (int i = 1; i < 6; i++)
    {
        p->next = new ListNode(vals1[i]);
        p = p->next;
    }
    int vals2[] = {2, 4, 5, 6, 8, 10};
    ListNode * l2 = new ListNode(vals2[0]);
    p = l2;
    for (int i = 1; i < 6; i++)
    {
        p->next = new ListNode(vals2[i]);
        p = p->next;
    }
    Solution * s = new Solution();
    p = s->Merge(l1, l2);
    while (p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
