# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个链表，反转链表后，输出新链表的表头。


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        p = pHead
        q = None
        while p:
            o = ListNode(p.val)
            o.next = q
            p = p.next
            q = o
        return q
