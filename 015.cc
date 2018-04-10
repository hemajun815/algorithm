#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode {
	int val;
	struct ListNode *next;
} ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    vector<ListNode*> * vct = new vector<ListNode*>();
    ListNode * p = pListHead;
    while(p)
    {
        vct->push_back(p);
        p = p->next;
    }
    int idx = vct->size() - k;
    if (idx < 0 || k == 0)
        return NULL;
    p = vct->at(idx);
    vct->clear();
    return p;
}

ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k) {
    ListNode * p = pListHead;
    ListNode * q = p;
    int i = 0;
    for (; p != NULL; i++)
    {
        if (i >= k)
            q = q->next;
        p = p->next;
    }
    return i < k ? NULL : q;
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListNode * header = new ListNode();
    header->val = a[0];
    header->next = NULL;
    ListNode * p = header;
    for (int i = 1; i < sizeof(a)/sizeof(int); i++)
    {
        p->next = new ListNode();
        p = p->next;
        p->val = a[i];
        p->next = NULL;

    }
    p = header;
    while(p)
    {
        cout << p->val;
        p = p->next;
    }
    cout << endl << FindKthToTail(header, 3)->val;
    cout << endl << FindKthToTail2(header, 3)->val;
    cout << endl << FindKthToTail(header, 5)->val;
    cout << endl << FindKthToTail2(header, 5)->val;
    cout << endl << FindKthToTail(header, 7)->val << endl;
    return 0;
}