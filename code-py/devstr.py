import sys

t = int(sys.stdin.readline())

while t:
    n, k = map(int, raw_input().split())
    lis, count = map(int, raw_input().split()), 0

    if k == n:
        print 0
        print lis
    else:
        for i in xrange(n - k):
            if lis[i + k - 1] == lis[i + k]:
                count += 1
                lis[i + k] = int(not lis[i + k - 1])
        print count
        print lis
    t -= 1
