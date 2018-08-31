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
    /**
     * 解题思路：
     * 1. 快慢指针判断是否存在环，无环存在直接返回NULL；
     * 2. 链表如若存在环。两个指针一个从head出发，一个从快慢指针交点出发，第一次相遇点即为环起点；
     * 证明：
     * 令head到环起点距离为a，环起点到快慢指针相交点距离为b，环的长度为c，慢指针速度为1，快指针速度为2。
     * 由快慢指针相遇可得：(a + b + mc) / 1 = (a + b + nc) / 2……(其中m，n为常数)。
     * 化简得：a = (n - 2m - 1)c + (c - b)……(其中n-2m-1为常数)。
     * 可知：
     * */
    ListNode *detectCycle(ListNode *head)
    {
        auto fast = head, slow = head;
        while (fast && fast->next && slow)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) // 链表存在环。
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = head->next->next;
    cout << boolalpha << ((new Solution())->detectCycle(head) == head->next->next) << endl; // true
    cin.get();
    return 0;
}
