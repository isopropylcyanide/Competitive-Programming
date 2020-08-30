def binarySearch(A, val, exact):
    n = len(A)
    l, h = 0, n - 1
    while l < h:
        m = l + ((h - l) >> 1)
        if A[m][0] >= val:
            h = m
        else:
            l = m + 1
    print 'got l: ', l, ' : ', A[l]
    if not exact:
        return A[l][1]
    elif exact and A[l][0] == val:
        return A[l][1]
    else:
        return -1


if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    h = {}
    _h = {}
    t = 0
    for i in A:
        if i not in h:
            h[i] = t
            _h[t] = i
            t += 1
    T = [0] * t
    for i in A:
        T[h[i]] += 1

    E = []
    for ind, i in enumerate(T):
        E.append([i, ind])
    E.sort()
    print _h
    print T
    print E

    for __ in xrange(input()):
        a, k = map(int, raw_input().split())
        ans = binarySearch(E, k, a)
        if ans == -1:
            print 0
        else:
            print _h[ans]
