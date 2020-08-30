mod = 10**9 + 7
MAX = 10**5 + 5
fact = []


def precompute():
    global fact
    fact.append(1)
    for i in xrange(1, MAX):
        fact.append(i * fact[i - 1] % mod)


def choose(n, r):
    return (fact[n] * pow(fact[r] * fact[n - r], mod - 2, mod) % mod) % mod


def bruteUtil(i, A, s, K, debug):
    if debug:
        print '\n i: %d \t A: %s \t K: %d' % (i, A, K)
    if K == 0:
        if debug:
            print 'Added'
        s.add(tuple(A))
        return
    if i >= len(A):
        return

    B = A[:]
    C = A[:]
    A[i] *= -1
    C[i] *= -1
    bruteUtil(i + 1, A, s, K - 1, debug)
    bruteUtil(i, C, s, K - 1, debug)
    bruteUtil(i + 1, B, s, K, debug)


def brute(A, K, debug=False):
    s = set()
    bruteUtil(0, A, s, K, debug)

    for i in s:
        print i
    return len(s)


def solve(A, N, K):
    s = 0
    z = A.count(0)

    if K >= N - z:
        if z > 0:
            return pow(2, N - z, mod)
        return pow(2, N - z - 1, mod)

    while K > 0:
        if N >= K:
            # print ' -> %dC%d : %d' % (N, K, choose(N, K))
            s = (s + choose(N, K)) % mod
        K -= 2
    if K % 2 == 0:
        s += 1

    return s


if __name__ == '__main__':
    precompute()

    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        A = map(int, raw_input().split())
        print solve(A, N, K)
