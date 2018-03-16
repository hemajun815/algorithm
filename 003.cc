#include <iostream>
#include <vector>

using namespace std;

typedef struct ListNode
{
    int val;
    struct ListNode * next;
}ListNode;

vector<int> func(ListNode * head)
{
    vector<int> vct;
    ListNode * p = head;
    ListNode * q = NULL;
    while (p)
    {
        ListNode * o = new ListNode();
        o->val = p->val;
        o->next = q;
        p = p->next;
        q = o;
    }
    while (q)
    {
        vct.push_back(q->val);
        q = q->next;
    }
    return vct;
}

int main(int argc, char const *argv[])
{
    ListNode node3 = {3, NULL};
    ListNode node2 = {2, &node3};
    ListNode node1 = {1, &node2};
    ListNode node0 = {0, &node1};
    vector<int> v = func(&node0);
    cout << v.size();
    return 0;
}