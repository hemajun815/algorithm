# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 004


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __reConstructBinaryTree(self, pre, tin, pre_start, pre_end, tin_start, tin_end):
        if pre_start > pre_end or tin_start > tin_end:
            return None
        node = TreeNode(pre[pre_start])
        for i in range(tin_start, tin_end+1):
            if tin[i] == pre[pre_start]:
                node.left = self.__reConstructBinaryTree(
                    pre, tin, pre_start+1, pre_start + i - tin_start, tin_start, i-1)
                node.right = self.__reConstructBinaryTree(
                    pre, tin, pre_start + 1 + i - tin_start, pre_end, i+1, tin_end)
                break
        return node

    # 返回构造的TreeNode根节点
    def reConstructBinaryTree(self, pre, tin):
        return self.__reConstructBinaryTree(pre, tin, 0, len(pre)-1, 0, len(tin)-1)


if __name__ == "__main__":
    pre = [1, 2, 4, 7, 3, 5, 6, 8]
    tin = [4, 7, 2, 1, 5, 3, 8, 6]
    s = Solution()
    node = s.reConstructBinaryTree(pre, tin)
