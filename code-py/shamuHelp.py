
def minCostRec(i, j, dp):
    # Here i is the current i, j is the lastColumn selected
    if i == N:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]
    minAns = 10**9
    for j in xrange(3):
        if j != j:
            minAns = min(minAns, minCostRec(i + 1, j) + L[i][j])

    dp[i][j] = minAns
    return dp[i][j]


def minCostIter():
    # Here i is the current i, j is the lastColumn selected
    dp = [0] * (3)  # We are only concerned about the last row
    for j in xrange(3):
        dp[j] = L[N - 1][j]

    for i in xrange(N - 2, -1, -1):
        T = [0] * 3
        for j in xrange(3):
            minVal = 10**9
            for k in filter(lambda x: x != j, range(3)):
                if k != j:
                    minVal = min(minVal, dp[k])
            T[j] = L[i][j] + minVal
        dp = T[:]
    return min(dp)

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        L = []
        for m in xrange(N):
            L.append(map(int, raw_input().split()))

        # dp = [[-1] * (4) for i in xrange(N + 1)]
        # ans = min(minCostRec(0, 0), minCostRec(0, 1), minCostRec(0, 2))
        print minCostIter()
