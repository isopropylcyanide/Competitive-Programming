mod = 10**9 + 7

found = False
a = ''


def travUtil(i, n, V):
    global found, a
    if V[i] == 1:
        return
    V[i] = 1
    if i == n - 1:
        if V == [1] * n:
            found = True
            return
    if a[i] == '1':
        _V = V[:]
        _VV = V[:]
        if i - 1 >= 0 and not V[i - 1]:
            travUtil(i - 1, n, _V)
        if i + 1 < n and not V[i + 1]:
            travUtil(i + 1, n, _VV)
    elif a[i] == '2':
        _V = V[:]
        _VV = V[:]
        if i - 2 >= 0 and not V[i - 2]:
            travUtil(i - 2, n, _V)
        if i + 2 < n and not V[i + 2]:
            travUtil(i + 2, n, _VV)


def goodString(s):
    global found, a
    n, a = len(s), s[:]
    v = [0] * n
    found = False
    travUtil(0, n, v)
    return found

if __name__ == '__main__':
    for _ in xrange(input()):
        _a = raw_input()
        _b = raw_input()
        n = len(_a)

        ways = 0
        for i in xrange(pow(2, n)):
            mask = bin(i)[2:].zfill(n)
            c, d = list(_a), list(_b)
            # print c, d, mask, 'After: ',
            for i, j in enumerate(mask):
                if j == '1':
                    c[i], d[i] = d[i], c[i]
            if goodString(c) and goodString(d):
                ways += 1
        print ways
