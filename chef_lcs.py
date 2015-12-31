
def LCS(X, Y):
    m = len(X)
    n = len(Y)
    # An (m+1) times (n+1) matrix
    C = [[0] * (n + 1)] * (m + 1)
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if X[i - 1] == Y[j - 1]:
                C[i][j] = C[i - 1][j - 1] + 1
            else:
                C[i][j] = max(C[i][j - 1], C[i - 1][j])
    return C


def backTrack(C, X, Y, i, j):
    if i == 0 or j == 0:
        return ""
    elif X[i - 1] == Y[j - 1]:
        return backTrack(C, X, Y, i - 1, j - 1) + X[i - 1]
    else:
        if C[i][j - 1] > C[i - 1][j]:
            return backTrack(C, X, Y, i, j - 1)
        else:
            return backTrack(C, X, Y, i - 1, j)


def backTrackAll(C, X, Y, i, j):
    if i == 0 or j == 0:
        return set([""])
    elif X[i - 1] == Y[j - 1]:
        return set([Z + X[i - 1] for Z in backTrackAll(C, X, Y, i - 1, j - 1)])
    else:
        R = set()
        if C[i][j - 1] >= C[i - 1][j]:
            R.update(backTrackAll(C, X, Y, i, j - 1))
        if C[i - 1][j] >= C[i][j - 1]:
            R.update(backTrackAll(C, X, Y, i - 1, j))
        return R


def main():
    n, k = map(int, raw_input().split())
    X = raw_input()
    Y = raw_input()
    m = len(X)
    n = len(Y)
    C = LCS(X, Y)

    print "Some LCS: '%s'" % backTrack(C, X, Y, m, n)
    print "All LCSs: %s" % backTrackAll(C, X, Y, m, n)

if __name__ == '__main__':
    main()
