# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 005


class Solution:
    def __init__(self):
        self.__s1 = []
        self.__s2 = []

    def push(self, node):
        self.__s1.append(node)

    def pop(self):
        if len(self.__s2) == 0:
            self.__s2 = self.__s1[::-1]
            self.__s1.clear()
        return self.__s2.pop()
