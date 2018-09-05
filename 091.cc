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
        if (!head || !head->next)
            return head;
        if (head->val != head->next->val)
        {
            head->next = this->deleteDuplicates(head->next);
            return head;
        }
        auto val = head->val;
        while (val == head->val)
        {
            auto p = head;
            head = head->next;
            delete p;
            if (!head)
                return NULL;
        }
        return this->deleteDuplicates(head);
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
