# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 014


class Solution:
    def reOrderArray(self, array):
        l_odd = []
        l_even = []
        for i in array:
            if i % 2 != 0:
                l_odd.append(i)
            else:
                l_even.append(i)
        return l_odd + l_even
