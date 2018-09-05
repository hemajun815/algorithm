#include <iostream>
#include <vector>
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
     * 1. 将链表数据存入数组
     * 2. 对数组进行插入排序
     * 3. 更新链表节点的值
     * */
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        auto array = new vector<int>();
        for (auto p = head; p; p = p->next)
            array->push_back(p->val);
        for (auto i = 1u; i < array->size(); i++)
        {
            auto tmp = array->at(i);
            auto j = i;
            for (; j > 0 && array->at(j - 1) > tmp; j--)
            {
                array->at(j) = array->at(j - 1);
            }
            array->at(j) = tmp;
        }
        auto p = head;
        auto idx = 0u;
        while (p)
        {
            p->val = array->at(idx);
            p = p->next;
            idx++;
        }
        delete array;
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
    auto result = (new Solution())->insertionSortList(head);
    print(result);
    cin.get();
    return 0;
}
