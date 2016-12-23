from collections import defaultdict

if __name__ == '__main__':
    N = input()
    h = defaultdict(set)
    for _ in xrange(N):
        A = map(str, raw_input().split())
        for i in A[2:]:
            h[i].add(A[1])

    for i in xrange(1, 6):
        key = str(i)
        l = h[key]
        if len(l) == 1:
            print 'NO'
        elif len(l) > 1:
            print 'YES'
        else:
            print 'UNDEFINED'
