
MAX = 100005

arr, num, fact, st, lazy1, lazy2 = 0, 0, 0, 0, 0, 0
N = 0


class LazyNode:

    def __init__(self, f, s, tStart, empty):
        self.f = f  # number of 2's in node
        self.s = s  # number of 5's in node
        self.tStart = tStart  # left of type2. lazy1 doesn't need this though
        self.empty = empty  # if this node is empty

    def __repr__(self):
        return '(%d, %d) : %d : %d' % (self.f, self.s, self.tStart, self.empty)


def initialize():
    global st, lazy1, lazy2

    st = [[0, 0] for i in xrange(4 * MAX)]  # main seg tree
    lazy1 = [LazyNode(0, 0, -1, 1) for i in xrange(4 * MAX)]
    lazy2 = [LazyNode(0, 0, -1, 1) for i in xrange(4 * MAX)]


def maxPow(N, K):
    # Maximum power of K in N
    power = 0
    while N % K == 0:
        N /= K
        power += 1
    return power


def preCompute():
    global N, num, fact
    num = [[0, 0] for i in xrange(MAX)]  # denotes no of 2's and 5's in n
    fact = [[0, 0] for i in xrange(MAX)]  # denotes no of 2's and 5' in n!

    for i in xrange(1, MAX):
        num[i] = [maxPow(i, 2), maxPow(i, 5)]
        fact[i] = [fact[i - 1][0] + num[i][0], fact[i - 1][1] + num[i][1]]


def mergeNode(a, b):
    # Merge two segtree Nodes a and b
    return [a[0] + b[0], a[1] + b[1]]


def removeLazinessType1(pos, l, r, s, e):
    global st, lazy1
    # apply lazy1 updates
    st[pos][0] = st[pos][0] + (r - l + 1) * lazy1[pos].f
    st[pos][1] = st[pos][1] + (r - l + 1) * lazy1[pos].s

    if l != r:
        lazy1[pos * 2 + 1].f += lazy1[pos].f
        lazy1[pos * 2 + 1].s += lazy1[pos].s
        lazy1[pos * 2 + 2].f += lazy1[pos].f
        lazy1[pos * 2 + 2].s += lazy1[pos].s
        lazy1[pos * 2 + 1].empty = lazy1[pos * 2 + 2].empty = 0

    # set current node as non lazy
    lazy1[pos] = LazyNode(0, 0, -1, 1)


def removeLazinessType2(pos, l, r, s, e):
    global st, lazy2
    # apply lazy 2 updates first
    ind = lazy2[pos].tStart

    # update 2's in node
    st[pos][0] = (r - l + 1) * lazy2[pos].f
    st[pos][0] += fact[r - ind + 1][0] - fact[l - ind][0]
    # update 5's in node
    st[pos][1] = (r - l + 1) * lazy2[pos].s
    st[pos][1] += fact[r - ind + 1][1] - fact[l - ind][1]

    if l != r:
        lazy2[pos * 2 + 1].f = lazy2[pos * 2 + 2].f = lazy2[pos].f
        lazy2[pos * 2 + 1].s = lazy2[pos * 2 + 2].s = lazy2[pos].s
        lazy2[pos * 2 + 1].tStart = lazy2[pos *
                                          2 + 2].tStart = ind
        lazy2[pos * 2 + 1].empty = lazy2[pos * 2 + 2].empty = 0
        # set lazy1 counterparts = 0
        lazy1[pos * 2 + 1].f = lazy1[pos * 2 + 1].s = 0
        lazy1[pos * 2 + 1].empty = 1
        lazy1[pos * 2 + 2].f = lazy1[pos * 2 + 2].s = 0
        lazy1[pos * 2 + 2].empty = 1

    # set current node as non lazy
    lazy2[pos] = LazyNode(0, 0, -1, 1)


def removeLaziness(pos, l, r, s, e):
    global st, lazy1, lazy2

    if lazy2[pos].empty == 0:
        removeLazinessType2(pos, l, r, s, e)

    if lazy1[pos].empty == 0:
        removeLazinessType1(pos, l, r, s, e)


def update_1_util(pos, l, r, s, e, diff):
    global st, lazy1, lazy2
    # // updates s to e with diff. i.e increment st[pos] with range*diff lazily

    removeLaziness(pos, l, r, s, e)

    if s > r or e < l:
        return

    if s <= l and r <= e:
        st[pos][0] = st[pos][0] + (r - l + 1) * diff[0]
        st[pos][1] = st[pos][1] + (r - l + 1) * diff[1]

        if l != r:
            lazy1[pos * 2 + 1].f += diff[0]
            lazy1[pos * 2 + 1].s += diff[1]
            lazy1[pos * 2 + 2].f += diff[0]
            lazy1[pos * 2 + 2].s += diff[1]
            lazy1[pos * 2 + 1].empty = lazy1[pos * 2 + 2].empty = 0
        return

    mid = l + ((r - l) >> 1)
    update_1_util(pos * 2 + 1, l, mid, s, e, diff)
    update_1_util(pos * 2 + 2, mid + 1, r, s, e, diff)
    st[pos] = mergeNode(st[pos * 2 + 1], st[pos * 2 + 2])


def query1(s, e, val):
    global N
    diff = [maxPow(val, 2), maxPow(val, 5)]
    update_1_util(0, 0, N - 1, s, e, diff)


def update_2_util(pos, l, r, s, e, diff):
    global st, lazy1, lazy2, fact
    # // updates s to e with diff. i.e increment st[pos] with range*diff lazily

    removeLaziness(pos, l, r, s, e)

    if s > r or e < l:
        return

    if s <= l and r <= e:
        # print '\nin u2 st[', pos, '] : ', st[pos], ' from ', l, ' to ', r
        st[pos][0] = (r - l + 1) * diff[0]
        st[pos][0] += fact[r - s + 1][0] - fact[l - s][0]
        st[pos][1] = (r - l + 1) * diff[1]
        st[pos][1] += fact[r - s + 1][1] - fact[l - s][1]
        # print 'after u2 st[', pos, '] : ', st[pos], ' from ', l, ' to ', r

        if l != r:
            lazy2[pos * 2 + 1].f = lazy2[pos * 2 + 2].f = diff[0]
            lazy2[pos * 2 + 1].s = lazy2[pos * 2 + 2].s = diff[1]
            lazy2[pos * 2 + 1].tStart = lazy2[pos *
                                              2 + 2].tStart = s
            lazy2[pos * 2 + 1].empty = lazy2[pos * 2 + 2].empty = 0
            # set lazy1 counterparts = 0
            lazy1[pos * 2 + 1].f = lazy1[pos * 2 + 1].s = 0
            lazy1[pos * 2 + 1].empty = 1
            lazy1[pos * 2 + 2].f = lazy1[pos * 2 + 2].s = 0
            lazy1[pos * 2 + 2].empty = 1
        return

    mid = l + ((r - l) >> 1)
    update_2_util(pos * 2 + 1, l, mid, s, e, diff)
    update_2_util(pos * 2 + 2, mid + 1, r, s, e, diff)
    st[pos] = mergeNode(st[pos * 2 + 1], st[pos * 2 + 2])


def query2(s, e, val):
    global N
    diff = [maxPow(val, 2), maxPow(val, 5)]
    update_2_util(0, 0, N - 1, s, e, diff)


def query3(pos, l, r, s, e):
    # Return trailing zeroes b/w product of nodes from s - e
    removeLaziness(pos, l, r, s, e)

    if s > r or e < l:
        return [0, 0]

    if s <= l and r <= e:
        return st[pos]

    mid = l + ((r - l) >> 1)
    a = query3(pos * 2 + 1, l, mid, s, e)
    b = query3(pos * 2 + 2, mid + 1, r, s, e)
    return mergeNode(a, b)


def constructTree(pos, l, r):
    # Construct seg tree bottom up
    global st, arr
    if l > r:
        return
    elif l == r:
        st[pos] = arr[l]
        return

    mid = l + ((r - l) >> 1)
    constructTree(pos * 2 + 1, l, mid)
    constructTree(pos * 2 + 2, mid + 1, r)
    st[pos] = mergeNode(st[pos * 2 + 1], st[pos * 2 + 2])

if __name__ == '__main__':
    # Main routine

    preCompute()

    for _ in xrange(input()):
        initialize()  # for multiple testcases
        N, M = map(int, raw_input().split())
        ans = 0

        arr = map(int, raw_input().split())
        arr = map(lambda x: [maxPow(x, 2), maxPow(x, 5)], arr)
        constructTree(0, 0, N - 1)
        # Tree is up. Now process queries

        for __ in xrange(M):
            q = map(int, raw_input().split())
            if q[0] == 1:
                query1(q[1] - 1, q[2] - 1, q[3])

            elif q[0] == 2:
                query2(q[1] - 1, q[2] - 1, q[3])

            elif q[0] == 3:
                node = query3(0, 0, N - 1, q[1] - 1, q[2] - 1)
                ans += min(node[0], node[1])
        print ans
