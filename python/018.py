# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 操作给定的二叉树，将其变换为源二叉树的镜像。


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if root:
            # node = root.left
            # root.left = root.right
            # root.right = node
            # self.Mirror(root.left)
            # self.Mirror(root.right)
            root.left, root.right = self.Mirror(
                root.right), self.Mirror(root.left)
        return root
