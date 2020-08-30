# print primes using sieve of eratosthenes


def primes(a, n):

    sieve = [1] * (n + 1)
    for p in range(2, n + 1):
        if sieve[p]:
            if p >= a:
                print p,
            for i in range(p * p, n + 1, p):
                sieve[i] = 0


t = int(raw_input())

while t:
    a, b = map(int, raw_input().split())
    primes(a, b)
    t -= 1
    print
