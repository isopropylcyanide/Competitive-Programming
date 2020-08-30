from collections import defaultdict
MOD = 10**9 + 7
MAX = 100005
P = []  # stores primes
D = []  # stores divisors


def factorize(N):
    global P, D
    copy = N
    h = defaultdict(int)
    while P[N] > 0:
        h[P[N]] += 1
        N /= P[N]
    h = list(h.itervalues())
    prod = h[0] + 1
    for i in h[1:]:
        prod = prod * (i + 1)

    D[copy] = prod + 1


def precompute():
    global P, D
    P = [0 for i in xrange(MAX)]
    V = [0 for i in xrange(MAX)]
    D = [0 for i in xrange(MAX)]
    D[0], D[1] = 1, 2

    for i in xrange(2, MAX, 2):
        P[i] = 2
    for i in xrange(3, MAX, 2):
        if not V[i]:
            P[i] = i
            j = i
            while j * i < MAX:
                if not V[j * i]:
                    P[j * i] = i
                    V[j * i] = 1
                j += 2
    # We have achieved minimum primes
    # Now find prime factorization
    for i in xrange(2, MAX):
        factorize(i)

if __name__ == '__main__':
    precompute()
    N = input()
    A = map(int, raw_input().split())
    numWays = 1
    for ind, i in enumerate(A):
        if i == -1:
            numWays = (numWays * D[ind]) % MOD

    print numWays
