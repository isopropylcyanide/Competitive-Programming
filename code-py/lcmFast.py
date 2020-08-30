# Our answer to this would always lie between N/2 + 1 and the next prime
# after N/2 + 1.

P = []


def sieve(n):
    "Return all primes <= n."
    np1 = n + 1
    s = list(range(np1))  # leave off `list()` in Python 2
    s[1] = 0
    sqrtn = int(round(n**0.5))
    for i in range(2, sqrtn + 1):  # use `xrange()` in Python 2
        if s[i]:
            # next line:  use `xrange()` in Python 2
            s[i * i: np1: i] = [0] * len(range(i * i, np1, i))
    return filter(None, s)


def isPrime(n):
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in xrange(3, int(pow(n, 0.5)) + 1, 2):
        if n % i == 0:
            return False
    return True


def compute(N):
    """compute power of each prime in P"""
    for i in P:
        if i * 2 <= N:
            continue
        else:
            return i


if __name__ == '__main__':
    P = sieve(10**7)
    N = input()

    print compute(N)
