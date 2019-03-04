# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）


class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None


class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead):
        # copy
        p = pHead
        while p:
            node = RandomListNode(p.label)
            node.next = p.next
            p.next = node
            p = node.next
        # update
        p = pHead
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        # split
        clone = None
        if pHead:
            clone = pHead.next
            p = pHead
            q = clone
            while p:
                p.next = p.next.next
                q.next = None if not p.next else p.next.next
                q = q.next
                p = p.next
        return clone
