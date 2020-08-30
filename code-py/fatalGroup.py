

def solve(N, K):
    if N < K:
        return 0
    if N < 2 * K:
        return 1
    if dp[N][K] != -1:
        return dp[N][K]
    ans = 1
    for j in xrange(K, N):
        ans += solve(N - j, j)
    dp[N][K] = ans
    return ans

if __name__ == '__main__':
    for _ in xrange(input()):
        dp = [[-1] * 201 for j in xrange(201)]
        N, K = map(int, raw_input().split())
        print solve(N, K)
