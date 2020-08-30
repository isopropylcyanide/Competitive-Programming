
if __name__ == '__main__':
    for _ in xrange(input()):
        A, B, D = map(int, raw_input().split())
        if D == 0:
            print D
        elif D == A or D == B:
            print 1
        elif A > D:
            print 2
        else:
            steps = 0
            while D > 2 * B:
                steps += 1
                D -= B
            steps += 2
            print steps
