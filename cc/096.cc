#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        auto origin = new ListNode(-1);
        auto pre = origin, p = l1, q = l2;
        while (p && q)
        {
            if (p->val > q->val)
            {
                pre->next = q;
                q = q->next;
            }
            else
            {
                pre->next = p;
                p = p->next;
            }
            pre = pre->next;
        }
        pre->next = p ? p : q;
        auto head = origin->next;
        delete origin;
        return head;
    }
};

void print(const ListNode *head)
{
    auto p = head;
    while (p)
    {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "null" << endl;
}

int main(int argc, char const *argv[])
{
    auto l1 = new ListNode(0);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(6);
    print(l1);
    auto l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(5);
    print(l2);
    print((new Solution)->mergeTwoLists(l1, l2));
    cin.get();
    return 0;
}
