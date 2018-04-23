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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode * p = pHead;
        ListNode * q = NULL;
        while (p)
        {
            ListNode * o = new ListNode(p->val);
            o->next = q;
            p = p->next;
            q = o;
        }
        return q;
    }
};

int main(int argc, char const *argv[])
{
    int vals[] = {1, 2, 3, 5, 7, 9};
    ListNode * l = new ListNode(vals[0]);
    ListNode * p = l;
    for (int i = 1; i < 6; i++)
    {
        p->next = new ListNode(vals[i]);
        p = p->next;
    }
    p = l;
    while (p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    p = (new Solution())->ReverseList(l);
    while (p)
    {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
