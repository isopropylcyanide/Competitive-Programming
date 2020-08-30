
mod = 1000000007


def f(N, L):
    left,  right = 1, 1
    if N < L:
        left = pow(N - 1, N, mod)
        right = pow(N, L - N, mod)
        return (left * right) % mod
    else:
        left = pow(N - 1, L, mod)
        return left


if __name__ == '__main__':
    for _ in xrange(input()):
        N, L = map(int, raw_input().split())
        print f(N, L)
