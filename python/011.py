# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 011


class Solution:
    def NumberOf1(self, n):
        return bin(n).count('1') if n >= 0 else bin(2**32 + n).count('1')
