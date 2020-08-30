mod = 10**9 + 7


def solve(A, B, N, K):
    # if i**a + j ** b % k == 0 for i,j < N
    P = [pow(i, A, K) for i in xrange(1, N + 1)]
    Q = [pow(j, B, K) for j in xrange(1, N + 1)]
    count = 0
    for ind, i in enumerate(P):
        for indj, j in enumerate(Q):
            if ind != indj and (i + j) % K == 0:
                count = (count + 1) % mod

    return count % mod


if __name__ == '__main__':
    for _ in xrange(input()):
        A, B, N, K = map(int, raw_input().split())
        print 'Case #%d: %d' % (_ + 1, solve(A, B, N, K))
