P = {2, 3, 5, 7, 11, 13, 17}
mod = 10**9 + 7


def f(i, last):
    ans = dp[i][last]
    if ans != -1:
        return ans % mod
    ans = 0
    if i == N:
        ans = 1
    else:
        for dig in xrange(10):
            if i == 0:
                ans += f(i + 1, dig) % mod
            elif last + dig not in P:
                ans += f(i + 1, dig) % mod
    dp[i][last] = ans
    return ans

if __name__ == '__main__':
    N = input()
    dp = [[-1] * 11 for i in xrange(100005)]
    print f(0, 0) % mod
