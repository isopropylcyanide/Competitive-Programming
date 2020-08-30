import sys
mod = 1000000007


def minWaysDP(N):
    if N < 2:
        return 1
    f = [0 for i in xrange(N + 1)]
    f[0], f[1] = 1, 1

    for i in xrange(2, N + 1):
        lenx = 0
        if i & 1:
            lenx = i / 2 + 1
        else:
            lenx = i / 2

        for j in xrange(0, lenx):
            if j == i - j - 1:
                f[i] = (f[i] + f[j] * f[j]) % mod
            else:
                f[i] = (f[i] + f[j] * f[i - j - 1] * 2) % mod

    return f[N] % mod


def minWaysMemoized(N):
    f = [-1 for i in xrange(N + 1)]

    def rec(n):
        if n in [0, 1]:
            return 1

        if f[n] != -1:
            return f[n]
        ways = 0
        for i in xrange(n):
            ways = (ways + rec(i) * rec(n - i - 1)) % mod

        return ways

    return rec(N)


def minWaysRecursive(N):
    if N in [0, 1]:
        return 1
    else:
        ways, lenx = 0, 0
        if N & 1:
            lenx = N / 2 + 1
        else:
            lenx = N / 2

        for i in xrange(0, lenx):
            if i == N - i - 1:
                ways += minWaysRecursive(i) ** 2
            else:
                ways += minWaysRecursive(i) * minWaysRecursive(N - i - 1) * 2

        return ways

if __name__ == '__main__':
    print minWaysDP(int(sys.stdin.readline()))
