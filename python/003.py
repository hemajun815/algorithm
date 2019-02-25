# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 003
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def printListFromTailToHead(self, listNode):
        l = []
        while listNode != None:
            l.append(listNode.val)
            listNode = listNode.next
        return l[::-1]