
"""Each query asks the number of distinct integers in the path from a u to v"""

MAX = 100070
P = [i for i in xrange(MAX)]
A = [0 for i in xrange(MAX)]
W = [1 for i in xrange(MAX)]


def root(N):
    # //find root nodes of DSU
    while N != P[N]:
        P[N] = P[P[N]]
        N = P[N]
    return P[N]


def merge(A, B):
    # // merge two nodes in DSU
    rootA = root(A)
    rootB = root(B)
    if rootA != rootB:
        if W[rootA] < W[rootB]:
            P[A] = B
            W[B] += W[rootA]
        else:
            P[B] = A
            W[A] += W[B]


def computeLCA(x, y):
    # // Compute lowest common ancestor
    valA, valB, val = [], [], []
    valA.append(A[x])
    while x != P[x]:
        x = P[x]
        valA.append(A[x])

    valB.append(A[y])
    while y != P[y]:
        y = P[y]
        valB.append(A[y])

    i, j = len(valA) - 1, len(valB) - 1
    while i >= 0 and j >= 0 and valA[i] == valB[j]:
        i -= 1
        j -= 1

    if i == -1:
        j += 1
        for k in xrange(j, -1, -1):
            val.append(valB[k])

    elif j == -1:
        i += 1
        for k in xrange(i, -1, -1):
            val.append(valA[k])
    else:
        i += 1
        for k in xrange(i, -1, -1):
            val.append(valA[k])
        for k in xrange(j, -1, -1):
            val.append(valB[k])
    return len(set(val))


if __name__ == '__main__':
    N = input()

    temp = map(int, raw_input().split())
    for i in xrange(N):
        A[i + 1] = temp[i]

    for _ in xrange(N - 1):
        u, v = map(int, raw_input().split())
        merge(u, v)

    for _ in xrange(input()):
        u, v = map(int, raw_input().split())
        print computeLCA(u, v)
