# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。


class Solution:
    def __init__(self):
        self.__data = []
        self.__min = None

    def push(self, node):
        self.__data.append(node)
        self.__min = node if self.__min is None or self.__min > node else self.__min

    def pop(self):
        result = None
        if self.__data:
            result = self.__data.pop()
            self.__min = min(
                self.__data) if result == self.__min else self.__min
        return result

    def top(self):
        return self.__data[0] if self.__data else None

    def min(self):
        return self.__min
