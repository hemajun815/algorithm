# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。


class Solution:
    def PrintMinNumber(self, numbers):
        ss = [str(num) for num in numbers]
        # ss.sort(cmp=lambda x, y: cmp(x + y, y + x))
        for i in range(len(ss)-1):
            for j in range(i, len(ss)):
                if ss[i] + ss[j] > ss[j] + ss[i]:
                    ss[i], ss[j] = ss[j], ss[i]
        return ''.join(ss)


if __name__ == "__main__":
    s = Solution()
    print(s.PrintMinNumber([1, 2, 3, 4, 5]))
