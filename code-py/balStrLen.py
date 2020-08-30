def solve(S):
    n = len(S)
    dp = [[0 for j in xrange(n)] for i in xrange(n)]

    for l in xrange(1, n):
        for i in xrange(0, n - l):
            j = i + 1
            if S[i] == '(' and S[j] == ')':
                # balanced
                if dp[i + 1][j - 1] + 2 > dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]
            else:
                if dp[i + 1][j] > dp[i][j - 1]:
                    dp[i][j] = dp[i + 1][j]
                else:
                    dp[i][j] = dp[i][j - 1]

    return dp[0][n - 1]

if __name__ == '__main__':
    for _ in xrange(input()):
        S = raw_input()
        print solve(S)
