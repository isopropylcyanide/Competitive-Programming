
INF = 10**18


def solveNaive(l, r):
    if l > r or l > N - 1 or l < 0 or r > N - 1 or r < 0:
        return INF
    elif l == r:
        return 0
    else:
        a = solveNaive(l, r - A[r])
        b = solveNaive(l, r - 1)
        c = solveNaive(l + 1, r)
        d = solveNaive(l + 1, r - 1)
        e = solveNaive(l + 1, r - A[r])
        f = solveNaive(l + A[l], r)
        g = solveNaive(l + A[l], r - 1)
        h = solveNaive(l + A[l], r - A[r])
        return 1 + min([a, b, c, d, e, f, g, h])


def solvePolyn():
    dA = [INF] * N  # stores min jumps to reach A[i] from left
    dA[0] = 0
    for i in xrange(N - 1):
        dA[i + 1] = min(dA[i + 1], dA[i] + 1)
        if i + A[i] < N:
            dA[i + A[i]] = min(dA[i + A[i]], dA[i] + 1)

    dB = [INF] * N  # stores min jumps to reach A[i] from left
    dB[N - 1] = 0
    for i in xrange(N - 1, 0, -1):
        dB[i - 1] = min(dB[i - 1], dB[i] + 1)
        if i - A[i] >= 0:
            dB[i - A[i]] = min(dB[i - A[i]], dB[i] + 1)

    return min([max(i, j) for i, j in zip(dA, dB)])

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())

        print solvePolyn()
