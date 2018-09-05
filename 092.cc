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
    /**
     * 思路：
     * 整体使用归并排序。
     * 其中获取中间节点时使用快慢指针。
     * */
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        // get mid
        auto fast = head->next, slow = head;
        while (fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // sort right
        auto right = this->sortList(slow->next);
        // sort left
        slow->next = NULL;
        auto left = this->sortList(head);
        // merge left and right
        auto origin = new ListNode(0);
        auto pre = origin, p = left, q = right;
        while (p && q)
        {
            if (p->val < q->val)
            {
                pre->next = p;
                p = p->next;
            }
            else
            {
                pre->next = q;
                q = q->next;
            }
            pre = pre->next;
        }
        while (p)
        {
            pre->next = p;
            p = p->next;
            pre = pre->next;
        }
        while (q)
        {
            pre->next = q;
            q = q->next;
            pre = pre->next;
        }
        head = origin->next;
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
    auto head = new ListNode(3);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    print(head);
    auto result = (new Solution())->sortList(head);
    print(result);
    cin.get();
    return 0;
}
