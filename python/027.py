# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def Convert(self, pRootOfTree):
        if not pRootOfTree:
            return None

        def pre(results, root):
            if root:
                pre(results, root.left)
                results.append(root)
                pre(results, root.right)
        nodes = []
        pre(nodes, pRootOfTree)
        dl = nodes[0]
        p = dl
        p.left = None
        for i in range(1, len(nodes)):
            q = nodes[i]
            q.left = p
            p.right = q
            p = q
        p.right = None
        return dl
