# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 008


class Solution:
    def jumpFloor(self, number):
        if number == 0:
            return 0
        f1 = 1
        f2 = 1
        while number != 0:
            f2 += f1
            f1 = f2 - f1
            number -= 1
        return f1
