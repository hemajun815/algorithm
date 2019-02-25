# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 006


class Solution:
    def minNumberInRotateArray(self, rotateArray):
        length = len(rotateArray)
        if length != 0:
            for i in range(length - 2):
                if rotateArray[i] > rotateArray[i+1]:
                    return rotateArray[i+1]
        return 0
