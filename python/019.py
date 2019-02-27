# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。


class Solution:
    # matrix类型为二维列表，需要返回列表
    def printMatrix(self, matrix):
        result = []
        while matrix:
            # 第一行按顺序加入
            result += matrix.pop(0)
            # 最后一列顺序加入
            if matrix and matrix[0]:
                for row in matrix:
                    result.append(row.pop())
            # 最后一行逆序加入
            if matrix:
                result += matrix.pop()[::-1]
            # 第一列逆序加入
            if matrix and matrix[0]:
                for row in matrix[::-1]:
                    result.append(row.pop())
        return result
