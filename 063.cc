#include <iostream>

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
    int GetLength(const ListNode *pHead)
    {
        auto p = pHead;
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }
    ListNode *Next(ListNode *p, const int &step = 1)
    {
        for (int i = 0; i < step; i++)
            p = p->next;
        return p;
    }

  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        auto len1 = this->GetLength(pHead1);
        auto len2 = this->GetLength(pHead2);
        auto p = pHead1, q = pHead2;
        if (len1 > len2)
            p = this->Next(p, len1 - len2);
        else
            q = this->Next(q, len2 - len1);
        while (p && q)
        {
            if (p == q)
                return p;
            p = this->Next(p);
            q = this->Next(q);
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    auto *p0 = new ListNode(0);
    auto *p1 = new ListNode(1);
    auto *p2 = new ListNode(2);
    auto *p3 = new ListNode(3);
    auto pHead1 = p0;
    p0->next = p1;
    p1->next = p2;
    p2->next = p3;
    auto *q0 = new ListNode(4);
    auto *q1 = new ListNode(5);
    auto pHead2 = q0;
    q0->next = q1;
    auto node = new ListNode(6);
    node->next = new ListNode(7);
    p3->next = q1->next = node;
    std::cout << std::boolalpha << (6 == (new Solution())->FindFirstCommonNode(pHead1, pHead2)->val) << std::endl;
    std::cin.get();
    return 0;
}
