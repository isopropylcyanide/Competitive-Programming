
if __name__ == '__main__':
    N, D = map(int, raw_input().split())
    A = map(int, raw_input().split())
    for _ in xrange(D):
        P = input()
        h = {}
        s, e, diff = -1, -1, 10**9
        for ind, i in enumerate(A):
            h[i] = ind
            if i - P in h:
                if i in h and h[i - P] != h[i]:
                    curDiff = abs(h[i - P] - h[i])
                    if curDiff < diff:
                        diff = curDiff
                        s, e = h[i - P], h[i]
        if s == -1:
            print -1
        else:
            print s + 1, e + 1
