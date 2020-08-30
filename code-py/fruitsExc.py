
def main():
    for _ in xrange(input()):
        N, M, K = map(int, raw_input().split())

        curDiff = abs(M - N)
        if K >= curDiff:
            print 0
        elif K < curDiff:
            print curDiff - K


if __name__ == '__main__':
    main()
