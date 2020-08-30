import sys
t = int(sys.stdin.readline())


def column(matrix, i):
    return [row[i] for row in matrix]

while t:
    i, n = 0, int(sys.stdin.readline())
    lis = [[0 for x in xrange(n)] for x in xrange(n)]

    while i != n:
        lis[i] = map(int, raw_input().split())
        i += 1

    summ = []
    for i in xrange(n):
        summ.append(sum(column(lis, i)))

    print max(summ) ^ (min(summ) / n)

    t -= 1
