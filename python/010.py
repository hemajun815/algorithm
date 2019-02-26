# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 010


class Solution:
    def rectCover(self, number):
        if number <= 0:
            return 0
        f1 = 1
        f2 = 2
        while number - 1 != 0:
            f2 += f1
            f1 = f2 - f1
            number -= 1
        return f1
