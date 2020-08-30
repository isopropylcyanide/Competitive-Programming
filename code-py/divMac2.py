dMAX = 10**6 + 5
V = [False for i in xrange(MAX)]


def updateTree(pos, l, r, s, e):
    global st, lazy
    if lazy[pos] != 0:
        st[pos] = 1
        if l != r:
            lazy[pos * 2 + 1] = 1
            lazy[pos * 2 + 2] = 1
        lazy[pos] = 0

    if l > r or s > r or e < l:
        return
    if s <= l and r <= e:
        st[pos] = 1
        if l != r:
            lazy[pos * 2 + 1] = 1
            lazy[pos * 2 + 2] = 1
        return

    mid = l + ((r - l) >> 1)
    updateTree(2 * pos + 1, l, mid, s, e)
    updateTree(2 * pos + 2, mid + 1, r, s, e)
    st[pos] = max(st[pos * 2 + 1], st[pos * 2 + 2])


def queryTree(pos, l, r, s, e):
    global st, lazy
    if l > r or l > e or r < s:
        return 0

    if lazy[pos] != 0:
        st[pos] = 1
        if l != r:
            lazy[pos * 2 + 1] = 1
            lazy[pos * 2 + 2] = 1
        lazy[pos] = 0

    if s <= l and r <= e:
        return st[pos]

    mid = l + ((r - l) >> 1)
    a = queryTree(2 * pos + 1, l, mid, s, e)
    b = queryTree(2 * pos + 2, mid + 1, r, s, e)
    return max(a, b)


def constructTree(pos, l, r):
    global st, lazy
    if l > r:
        return
    if l == r:
        st[pos] = A[l]
        return
    mid = l + ((r - l) >> 1)
    constructTree(2 * pos + 1, l, mid)
    constructTree(2 * pos + 2, mid + 1, r)
    st[pos] = max(st[pos * 2 + 1], st[pos * 2 + 2])

if __name__ == '__main__':

    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        A = map(int, raw_input().split())

        ans = []
        # else solve for 2nd subtask..all are prime
        st = [0] * (4 * N)
        lazy = [0] * (4 * N)
        constructTree(0, 0, N - 1)

        for __ in xrange(M):
            a, b, c = map(int, raw_input().split())
            if a == 0:
                # Update b to c : a[i]/leastPrime[i]
                updateTree(0, 0, N - 1, b - 1, c - 1)
            if a == 1:
                # report max from lp of a[j] to a[c]
                cur = queryTree(0, 0, N - 1, b - 1, c - 1)
                ans.append(cur)
        for i in ans:
            print i,
