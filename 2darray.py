#!/bin/python

import sys


def f(a):
    ones, twos = 0, 0
    for i in xrange(len(a)):
        twos |= (ones & a[i])
        ones ^= a[i]

        cbm = ~(ones & twos)
        ones &= cbm
        twos &= cbm
    return ones


def hourGlass(a):
    maxm = -sys.maxint
    for i in xrange(len(arr) - 3 + 1):
        summ = 0
        for j in xrange(1, len(arr[0]) - 1):
            summ = sum([arr[i][j - 1], arr[i][j], arr[i][j + 1], arr[i + 1]
                        [j], arr[i + 2][j - 1], arr[i + 2][j], arr[i + 2][j + 1]])
            if maxm < summ:
                maxm = summ
    print maxm

arr = []
for _ in xrange(6):
    arr_temp = map(int, raw_input().split())
    arr.append(arr_temp)
hourGlass(arr)
