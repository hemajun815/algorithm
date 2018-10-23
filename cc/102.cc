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
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        // 快慢指针找到中间节点
        auto slow = head, fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto left = head, right = slow->next;
        slow->next = NULL;
        // 前插法反转后半部分链表：反转right
        auto p = right;
        right = NULL;
        while (p)
        {
            auto tmp = p;
            p = p->next;
            tmp->next = right;
            right = tmp;
        }
        // 合并两部分链表：将right合并到left上
        while (right)
        {
            auto tmp = right;
            right = right->next;
            tmp->next = left->next;
            left->next = tmp;
            left = tmp->next;
        }
    }
};

class Helper
{
  public:
    static void print_list(struct ListNode *const head)
    {
        auto p = head;
        while (p)
        {
            cout << p->val;
            p = p->next;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    struct ListNode *head = new struct ListNode(1);
    head->next = new struct ListNode(2);
    head->next->next = new struct ListNode(3);
    head->next->next->next = new struct ListNode(4);
    head->next->next->next->next = new struct ListNode(5);
    Helper::print_list(head); // 12345
    (new Solution())->reorderList(head);
    Helper::print_list(head); // 15243
    return 0;
}
