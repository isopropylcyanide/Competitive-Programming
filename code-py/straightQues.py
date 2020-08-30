
from __future__ import division


def matrixSub(n):
    totalSubMat = (n * (n + 1) * (2 * n + 1)) // 6
    unique = (n * (n + 1) * (n + 1) * (n + 2)) // 12
    print "%6d" % (unique // totalSubMat)


def main():
    for _ in xrange(input()):
        matrixSub(input())

if __name__ == '__main__':
    main()
