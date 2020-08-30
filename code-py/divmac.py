
MAX = 10**6 + 5
prime = [0 for i in xrange(MAX)]
V = [False for i in xrange(MAX)]


class node:

    def __init__(self, value, flags):
        self.val = value
        self.flag = flags


def sieve():
    # Generate minimum prime for a given number
    for i in xrange(2, MAX):
        prime[i] = 2
    prime[1] = 1

    for i in xrange(3, MAX, 2):
        if V[i] == False:
            prime[i] = i
            j = i
            while (j * i < MAX):
                if V[j * i] == False:
                    V[j * i] = True
                    prime[j * i] = i
                j += 2


def updateTree(pos, l, r, s, e):
    if l > r or s > r or e < l:
        return

    # Return now if all values in node are 1
    if st[pos].flag == 1:
        return

    if l == r:
        A[l] /= prime[A[l]]
        st[pos].val = prime[A[l]]
        if A[l] == 1:
            st[pos].flag = 1
        return

    mid = l + ((r - l) >> 1)
    if mid >= e:
        updateTree(2 * pos + 1, l, mid, s, e)
    elif mid < s:
        updateTree(2 * pos + 2, mid + 1, r, s, e)

    else:
        updateTree(2 * pos + 1, l, mid, s, e)
        updateTree(2 * pos + 2, mid + 1, r, s, e)
    st[pos].val = max(st[pos * 2 + 1].val, st[pos * 2 + 2].val)
    st[pos].flag = st[pos * 2 + 1].flag & st[pos * 2 + 2].flag


def queryTree(pos, l, r, s, e):
    if l > r or l > e or r < s:
        return 0
    elif s <= l and r <= e:
        return st[pos].val

    mid = l + ((r - l) >> 1)
    a = queryTree(2 * pos + 1, l, mid, s, e)
    b = queryTree(2 * pos + 2, mid + 1, r, s, e)
    return max(a, b)


def constructTree(pos, l, r):
    if l > r:
        return
    if l == r:
        st[pos] = node(prime[A[l]], 1 if A[l] is 1 else 0)
        return

    mid = l + ((r - l) >> 1)
    constructTree(2 * pos + 1, l, mid)
    constructTree(2 * pos + 2, mid + 1, r)
    st[pos].val = max(st[pos * 2 + 1].val, st[pos * 2 + 2].val)
    st[pos].flag = st[pos * 2 + 1].flag & st[pos * 2 + 2].flag

if __name__ == '__main__':
    sieve()

    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        A = map(int, raw_input().split())
        ans = []
        st = [node(0, 0)] * (4 * N)
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
