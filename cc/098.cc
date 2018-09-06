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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || k == 0)
            return head;
        // 定义两个指针p、q
        auto p = head, q = head;
        // p先走k-1步
        while (k-- > 0)
        {
            p = p->next;
            if (!p)
                p = head;
        }
        // p、q同时向后知道p为尾节点
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        p->next = head; // 首尾相接
        head = q->next; // 更新头节点
        q->next = NULL; // 断开环
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head); // 1->2->3->4->5->null
    auto p = new Solution();
    head = p->rotateRight(head, 0);
    print(head); // 1->2->3->4->5->null
    head = p->rotateRight(head, 1);
    print(head); // 5->1->2->3->4->null
    head = p->rotateRight(head, 2);
    print(head); // 3->4->5->1->2->null
    head = p->rotateRight(head, 3);
    print(head); // 5->1->2->3->4->null
    head = p->rotateRight(head, 4);
    print(head); // 1->2->3->4->5->null
    head = p->rotateRight(head, 5);
    print(head); // 1->2->3->4->5->null
    head = p->rotateRight(head, 6);
    print(head); // 5->1->2->3->4->null
    delete p;
    cin.get();
    return 0;
}
