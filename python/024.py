# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。


class Solution:
    def VerifySquenceOfBST(self, sequence):
        return False if len(sequence) == 0 else self.__VerifySquenceOfBST(sequence, 0, len(sequence)-1)

    def __VerifySquenceOfBST(self, sequence, start, end):
        if start >= end:
            return True
        split = start
        while split < end and sequence[split] < sequence[end]:
            split += 1
        for i in range(split, end):
            if sequence[i] <= sequence[end]:
                return False
        return self.__VerifySquenceOfBST(sequence, start, split-1) and self.__VerifySquenceOfBST(sequence, split, end-1)
