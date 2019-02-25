# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 001
class Solution:
    # array 二维列表
    def Find(self, target, array):
        row = len(array)
        if row > 0:
            col = len(array[0])
            i = row - 1
            j = 0
            while True:
                if j == col or i < 0:
                    return False
                elif target == array[i][j]:
                    return True
                elif target > array[i][j]:
                    j += 1
                else:
                    i -= 1
        return False