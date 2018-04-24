#include <iostream>
using namespace std;

class RandomListNode {
public:
    int label;
    RandomListNode * next;
    RandomListNode * random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*
 * 思路：
 * 1、遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
 * 2、重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
 * 3、拆分链表，将链表拆分为原链表和复制后的链表
 */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        // step1: 复制链表节点
        RandomListNode * p = pHead;
        while(p)
        {
            RandomListNode * node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = node->next;
        }
        // step2: 更新random指针
        p = pHead;
        while(p)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        // step3: 拆分链表
        RandomListNode * clone = NULL;
        if (pHead)
        {
            clone = pHead->next;
            RandomListNode * q = clone;
            p = pHead;
            while(p)
            {
                p->next = p->next->next;
                q->next = !p->next ? NULL : p->next->next;
                q = q->next;
                p = p->next;
            }
        }
        return clone;
    }
};

int main(int argc, char const *argv[])
{
    RandomListNode * pHead = new RandomListNode(0);
    RandomListNode * node1 = new RandomListNode(1);
    RandomListNode * node2 = new RandomListNode(2);
    pHead->next = node1;
    node1->next = node2;
    pHead->random = node2;
    node2->random = node1;
    /*
                          |<-----random------|
     pHead(0) --next--> node1(1) --next--> node2(2)
       |---------------random--------------->|
     */
    RandomListNode * clone = (new Solution())->Clone(pHead);
    cout << clone->random->random->next->label << endl; // cout << 2
    return 0;
}
