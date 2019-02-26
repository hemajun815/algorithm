# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 015


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def FindKthToTail(self, head, k):
        p = head
        q = p
        idx = 0
        while p is not None:
            if idx >= k:
                q = q.next
            p = p.next
            idx += 1
        return None if idx < k else q
