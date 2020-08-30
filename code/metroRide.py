from bisect import bisect

if __name__ == '__main__':
    for _ in xrange(input()):
        A = map(int, raw_input().split())

        for __ in xrange(input()):
            Q = input()
            pos = bisect(A, Q)
            if pos == len(A):
                if A[-1] == Q:
                    print 'Enjoy Travelling'
                    print len(A)
                else:
                    print 'Take the Chance'
            else:
                print 'Enjoy Travelling'
                print pos
