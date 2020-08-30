
mod = 1000000007

# Fibonacci matrix multiplication


def isFibonacci(N):
    """true if a number is a Fibonacci using Binet's formula"""
    def isPerfectSq(N):
        return int(N**0.5) == N**0.5

    if isPerfectSq(5 * N**2 - 4) or isPerfectSq(5 * N**2 + 4):
        return True
    return False


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


if __name__ == '__main__':

    for _ in xrange(input()):
        A, B, N = map(int, raw_input().split())
        F = [[1, 1], [1, 0]]
        if N == 0:
            print A
        elif N == 1:
            print B
        else:
            powMatrix(F, N - 1)
            print ((F[0][0] * B) % mod + (F[0][1] * A) % mod) % mod
