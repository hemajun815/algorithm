# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个字符串，按字典序打印出该字符串中字符的所有排列。例如输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符串abc，acb，bac，bca，cab和cba。输入字符串长度不超过9(可能有字符重复)，字符只包括大小写字母。


class Solution:
    def Permutation(self, ss):
        results = []
        if len(ss) > 0:
            self.__Permutation(results, list(ss), 0)
            results.sort()
        return results

    def __Permutation(self, results, chs, pos):
        if pos == len(chs):
            results.append(''.join(chs))
        for i in range(pos, len(chs)):
            if i != pos and chs[i] == chs[pos]:
                continue
            chs[i], chs[pos] = chs[pos], chs[i]
            self.__Permutation(results, chs, pos+1)
            chs[i], chs[pos] = chs[pos], chs[i]


if __name__ == "__main__":
    s = Solution()
    print(s.Permutation('aca'))
