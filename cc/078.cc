#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return head;
        ListNode *o = new ListNode(-1);
        o->next = head;
        auto p = o;
        ++n;
        while (n--)
            p = p->next;
        auto q = o;
        while (p)
        {
            p = p->next;
            q = q->next;
        }
        auto r = q->next;
        q->next = r->next;
        delete r;
        head = o->next;
        delete o;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(arr[0]);
    auto p = head;
    for (auto i = 1u; i < sizeof arr / sizeof arr[0]; i++)
    {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    head = (new Solution())->removeNthFromEnd(head, 5);
    return 0;
}
