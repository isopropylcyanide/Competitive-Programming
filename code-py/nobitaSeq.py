
mod = 1000000007

# Fibonacci matrix multiplication


def powMatrix(F, n):
    """raises a matrix F to power n """
    if n < 2:
        return
    M = [[1, 2], [1, 0]]
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


def solve(k):
    if k < 0:
        return 0
    elif k == 1:
        return 1
    elif k == 2:
        return 10
    else:
        F = [[1, 2], [1, 0]]
        powMatrix(F, k - 2)
        return ((F[0][0] * B) % mod + (F[0][1] * A) % mod) % mod

if __name__ == '__main__':

    for _ in xrange(input()):
        L, R = map(int, raw_input().split())
        A, B = 1, 10
        tSum = 0
        rhs = solve(R + 2) - 10
        lhs = solve(L + 1) - 10
        print ((rhs - lhs + mod) * 500000004) % mod
        # rSum = 3 * solve(R - 1) + 2 * solve(R - 2) - 1
        # lSum = 3 * solve(L - 2) + 2 * solve(L - 3) - 1
        # print rSum - lSum
