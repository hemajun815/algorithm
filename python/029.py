# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。


class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        result = 0
        if len(numbers) > 0:
            count = 0
            for num in numbers:
                result = num if count == 0 else result
                count = count + 1 if result == num else count - 1
            count = 0
            for num in numbers:
                count = count + 1 if result == num else count
            result = result if 2 * count > len(numbers) else 0
        return result
