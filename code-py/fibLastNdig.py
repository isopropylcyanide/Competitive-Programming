from math import sqrt
mod = 1000000007


def F(n):
    return int(((1 + sqrt(5))**n - (1 - sqrt(5))**n) / (2**n * sqrt(5))) % mod


def powMatrix(F, n):
    """raises a matrix F to power n """
    if n in [0, 1]:
        return
    M = [[1, 1], [1, 0]]
    powMatrix(F, n / 2)
    multiply(F, F)

    if n % 2 == 1:
        multiply(F, M)


def multiply(F, M):
    x = ((F[0][0] * M[0][0]) % mod + (F[0][1] * M[1][0]) % mod) % mod
    y = ((F[0][0] * M[0][1]) % mod + (F[0][1] * M[1][1]) % mod) % mod
    z = ((F[1][0] * M[0][0]) % mod + (F[1][1] * M[1][0]) % mod) % mod
    w = ((F[1][0] * M[0][1]) % mod + (F[1][1] * M[1][1]) % mod) % mod

    F[0][0], F[0][1], F[1][0], F[1][1] = x, y, z, w


def getNthFib(N):
    if N == 0 or N == 1:
        return 1
    F = [[1, 1], [1, 0]]
    powMatrix(F, N - 1)
    return F[0][0] % mod

if __name__ == '__main__':
    for _ in xrange(input()):
        a, b = map(int, raw_input().split())
        a, b = map(lambda x: x % (15000), [a, b])

        # sum of fibonnaci numbers from a to b = f(b + 2) - f(a + 1)
        R = getNthFib(b + 2)
        L = getNthFib(a + 1)
        # print 'Sum of first %d fib: %d' % (a - 1, L - 2)
        # print 'Sum of first %d fib: %d' % (b, R - 2)
        # print R - 2, L - 2, R - L
        print str((R - L) % mod)[-4:]
