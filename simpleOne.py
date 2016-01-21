from fractions import Fraction
mod = 10**9 + 7


def egcd(a, b):
    x, y, u, v = 0, 1, 1, 0
    while a != 0:
        q, r = b // a, b % a
        m, n = x - u * q, y - v * q
        b, a, x, y, u, v = a, r, u, v, m, n
    gcd = b
    return gcd, x, y


def main():
    for _ in xrange(input()):
        p, q, n = map(int, raw_input().split())
        f, one = Fraction(p, q), Fraction(1, 1)
        cache = [0 for i in xrange(n + 1)]
        cache[0], cache[1] = [0, f]

        for i in xrange(2, n + 1):
            num = cache[i - 1] + cache[1]
            deno = one - (cache[i - 1]) * cache[1]
            cache[i] = num / deno

        print egcd(cache[i].denominator, mod)[1] * (cache[i].numerator) % mod


if __name__ == '__main__':
    main()
