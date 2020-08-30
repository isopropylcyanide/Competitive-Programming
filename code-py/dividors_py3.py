# last of which is Python 3 only
from itertools import chain, cycle, accumulate


def seq_sieve(n):
    global F
    F = [0] * (n + 1)
    i = 2

    while i * i <= n:
        if F[i] == 0:
            k = i * i

        while k <= n:
            if F[k] == 0:
                F[k] = i

            k += i
        i += 1
    return F


def factorize(F, x):
    result = []
    while F[x] > 0:
        result.append(F[x])
        x //= F[x]

    result.append(x)
    return result


def divisors(F, n):
    def prime_powers(n):
        # c goes through 2, 3, 5, then the infinite (6n+1, 6n+5) series
        for c in accumulate(chain([2, 1, 2], cycle([2, 4]))):
            if c * c > n:
                break
            if n % c:
                continue
            d, p = (), c
            while not n % c:
                n, p, d = n // c, p * c, d + (p,)
            yield(d)
        if n > 1:
            yield((n,))

    r = [1]
    for e in prime_powers(n):
        # print (e),
        r += [a * b for a in r for b in e]
    return r


if __name__ == '__main__':
    F = seq_sieve(100)
    for i in range(1, 10):
        print (divisors(F, i))
