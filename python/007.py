# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 007


class Solution:
    def Fibonacci(self, n):
        f1 = 0
        f2 = 1
        while n != 0:
            f2 += f1
            f1 = f2 - f1
            n -= 1
        return f1
