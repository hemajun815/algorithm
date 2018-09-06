#include <iostream>
using namespace std;

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        auto p = head;
        if (p)
        {
            auto q = p->next;
            while (q)
            {
                if (q->val != p->val) // 不同，p、q同时后移。
                {
                    p = q;
                    q = p->next;
                }
                else // 相同，删除q节点。
                {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }
        }
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
    auto head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    print(head);
    auto result = (new Solution())->deleteDuplicates(head);
    print(result);
    cin.get();
    return 0;
}
