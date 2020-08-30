memo = {}


def C(n, r, p):
    ''' {n choose r} modulo p (p is prime) '''
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    if n >= p:  # Lucas theorem
        return C(n / p, r / p, p) * C(n % p, r % p, p) % p
    if (n, r, p) not in memo:
        memo[n, r, p] = (C(n - 1, r - 1, p) + C(n - 1, r, p)) % p
    return memo[n, r, p]


def egcd(a, b):
    ''' finds (x, y) such that a*x + b*y = gcd(a, b) '''
    if b == 0:
        return 1, 0
    else:
        x, y = egcd(b, a % b)
        return y, x - (a / b) * y


def inv(a, n):
    ''' modular inverse of a modulo n '''
    x, y = egcd(a % n, n)
    return x % n


def chinese(a1, m1, a2, m2):
    m = m1 * m2
    return (a1 * inv(m2, m1) % m1 * m2 + a2 * inv(m1, m2) % m2 * m1) % m, m


def prime_factorize(n):
    ''' yields all prime-exponent pairs in the prime factorization of n '''
    p = 2
    while p <= n:
        if p * p > n:
            p = n
        e = 0
        while n % p == 0:
            n /= p
            e += 1
        if e:
            yield p, e
        p += 1

if __name__ == '__main__':
    for _ in xrange(input()):
        n, r, m = map(int, raw_input().strip().split())

        ans, mod = 0, 1
        for p, e in prime_factorize(m):
            ans, mod = chinese(ans, mod, C(n, r, p), p)

        print ans
