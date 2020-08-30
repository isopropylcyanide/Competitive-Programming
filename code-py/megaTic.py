
def diagonals(L):
    h, w = len(L), len(L[0])
    return [[L[h - p + q - 1][q]
             for q in range(max(p - h + 1, 0), min(p + 1, w))]
            for p in range(h + w - 1)]


def antidiagonals(L):
    h, w = len(L), len(L[0])
    return [[L[p - q][q]
             for q in range(max(p - h + 1, 0), min(p + 1, w))]
            for p in range(h + w - 1)]


def solve(L, winChar, n, m, kChar):
    # find whether there exists k continuous winChars in L
    # search in row
    row = []
    for i in xrange(n):
        row.append(L[i])

    cols = []
    for i in xrange(m):
        cur = []
        for k in xrange(n):
            cur.append(L[k][i])
        cols.append(cur)

    diag = diagonals(L) + antidiagonals(L)
    row = map(lambda x: ''.join(x), row)
    cols = map(lambda x: ''.join(x), cols)
    diag = map(lambda x: ''.join(x), diag)

    row, cols, diag = set(row), set(cols), set(diag)

    pat = winChar * kChar
    if any(pat in i for i in row):
        return True
    if any(pat in i for i in cols):
        return True
    if any(pat in i for i in diag):
        return True

    return False

if __name__ == '__main__':
    for _ in xrange(input()):
        n, m, k = map(int, raw_input().split())
        L = []
        for __ in xrange(n):
            L.append(list(raw_input()))

        alex = solve(L, 'O', n, m, k)
        _alex = solve(L, 'X', n, m, k)
        if alex and _alex:
            print 'NONE'
        elif alex:
            print 'WIN'
        elif _alex:
            print 'LOSE'
        else:
            print 'NONE'
