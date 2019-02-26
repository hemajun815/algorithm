# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 013


class Solution:
    def Power(self, base, exponent):
        abs_e = exponent if exponent > 0 else -exponent
        if abs_e == 0:
            return 1
        result = base
        for _ in range(abs_e - 1):
            result *= base
        return result if exponent > 0 else 1 / result
