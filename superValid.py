
if __name__ == '__main__':
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        if N % 2 == 1:
            print 0
        else:
            print N / K - 1
