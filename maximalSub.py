def solveDP(A, K):
    H = {}
    for i in xrange(K):
        H[i] = 0

    for i in A:
        H[i % K] += 1

    N = [[0 for i in xrange(K)] for j in xrange(K)]
    for i in H:
        N[i][i] = H[i]

    for col in xrange(1, K):
        for i in xrange(K - col):
            j = i + col
            if (i + j) % K == 0:
                # we don't include this set.
                # What's best now is
                N[i][j] = max(N[i][j - 1], N[i + 1][j])
            else:
                N[i][j] = max(H[i] + H[j], N[i]
                              [j - 1], N[i + 1][j])

    for i in N:
        print i
    print N[0][K - 1]


def solveMath(A, K):
    dp = [0 for i in xrange(len(A))]
    dp[0] = 0 if A[0] % K == 0 else 1

    for i in xrange(1, len(A)):
        dp[i] = 1
        a = A[i] % K
        for j in xrange(i - 1, -1, -1):
            b = A[j] % K
            if (a + b) % K != 0:
                dp[i] = max(dp[i], dp[j] + 1)
        # print '\n For i: ', i, dp
    print max(dp)

if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    A = map(int, raw_input().split())
    solveMath(A, K)
