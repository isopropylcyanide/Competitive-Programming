mod = 10**9 + 7


def f(i, aSum):
    if aSum >= K and _sum - aSum >= K:
        dp[i][K] = 1
        return dp[i][K]

    ans = dp[i][aSum]
    if ans != -1:
        return ans
    else:
        ans = 0
    if i == N:
        if aSum >= K and _sum - aSum >= K:
            ans = 1
        else:
            ans = 0
    else:
        ans = (ans + f(i + 1, aSum + A[i]) + f(i + 1, aSum)) % mod
    dp[i][aSum] = (ans + mod) % mod
    return ans

if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    A = map(int, raw_input().split())
    _sum = sum(A)
    dp = [[-1] * 100005 for j in xrange(1001)]

    print f(0, 0)
