# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 009


class Solution:
    def jumpFloorII(self, number):
        if number == 0 or number == 1:
            return number
        return 2 * self.jumpFloorII(number-1)
