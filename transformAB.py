
P = []
primes = []
MAX = 10**6 + 5


def sieve():
    global P
    P = [1] * (MAX)
    P[0] = P[1] = 0

    for i in xrange(2, MAX):
        if P[i] == 1:
            primes.append(i)
            for j in xrange(i * i, MAX, i):
                P[j] = 0
    del(P)

if __name__ == '__main__':
    sieve()
    A, B = map(int, raw_input().split())
    if (B - A) in primes:
        print '%s->%d' % (A, B)
    else:
        print 'Unlucky Benny'
