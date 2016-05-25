
def binCoeff(n, k):
    r = 1
    if k > n - k:
        k = n - k
    for i in xrange(k):
        r = (r * (n - i)) % mod
        r = (r / (i + 1)) % mod
    return r


def catalan(n):
    c = binCoeff(2 * n, n)
    return c / (n + 1)

if __name__ == '__main__':
    for _ in xrange(input()):
        X, Y = map(int, raw_input().split())
