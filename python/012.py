# -*- coding: utf-8 -*-
# /usr/bin/python3
# Creator: Hemajun
# Description: 012


def solution(a, b):
    count = 0
    sum = 0
    for i in range(1, a):
        sum += i
    for j in range(a, b+1):
        sum += j
        if sum % 3 == 0:
            count += 1
    return count


if __name__ == "__main__":
    print(solution(1, 5))
