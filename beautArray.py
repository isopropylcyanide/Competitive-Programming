from math import log as l


def isBeaut():
    if 0 in A:
        return True
    h = set()

    for i in xrange(N):
        t = l(abs(A[i])) / l(2)
        A[i] = t if A[i] > 0 else -t
    # log tables prepared
    print A
    for i in A:
        val, sgn = abs(i), i > 0
        if (val, sgn) in h:
            return True
        else:
            h.add((val, sgn))
        print h

    return False

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        print 'yes' if isBeaut() else 'no'
