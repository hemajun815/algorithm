# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 从上往下打印出二叉树的每个节点，同层节点从左至右打印。


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # 返回从上到下每个节点值列表
    def PrintFromTopToBottom(self, root):
        result = []
        if root:
            q = [root]
            while len(q) != 0:
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                result.append(node.val)
        return result
