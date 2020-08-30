mod = 10**9 + 7


def solve(A, N):
    W, val = 0, 0
    lim = N / 2 if N % 2 == 0 else N / 2 + 1
    for i in xrange(lim):
        if i == 0:
            val = (val + pow(2, N, mod) - 1 + mod) % mod
            W = (W + (A[i] * val) % mod) % mod
            W = (W + (A[N - 1 - i] * val) % mod) % mod
        else:
            val = (val + pow(2, N - 1 - i, mod) - pow(2, i - 1) + mod) % mod
            W = (W + (A[i] * val) % mod) % mod
            if i != N - 1 - i:
                W = (W + (A[N - 1 - i] * val) % mod) % mod
    return W % mod

if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    print solve(A, N)
