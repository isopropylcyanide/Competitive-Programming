
# smallest lexicographical subsequence of string S of length K.


def solveDP(X, K, debug=False):
    N = len(X)
    T = [["" for i in xrange(N + 1)] for j in xrange(K + 1)]

    for i in xrange(1, K + 1):
        for j in xrange(1, N + 1):
            if i == j:
                T[i][j] = T[i - 1][j - 1] + X[j - 1]
            elif j > i:
                T[i][j] = min(T[i][j - 1],
                              T[i - 1][j - 1] + X[j - 1])
    if debug:
        for i in T:
            print i
    return T[K][N]


if __name__ == '__main__':

    for _ in xrange(input()):
        X = raw_input()
        K = input()
        print solveDP(X, K, True)
