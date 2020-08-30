
s, N = "", 0
dp = []


def sumDigRec(N):
    mod = N % 9
    if mod == 0:
        return 0 if N == 0 else 9
    return mod


def f(i, sumD, tight):
    ans = dp[i][sumD][tight]
    if ans != -1:
        return ans
    ans = 0
    if i == N:
        if sumDigRec(sumD) == 7:
            ans = 1
        else:
            ans = 0
    else:
        if tight == 1:
            for dig in xrange(s[i] + 1):
                if dig == s[i]:
                    ans += f(i + 1, sumD + dig, 1)
                else:
                    ans += f(i + 1, sumD + dig, 0)
        else:
            for dig in xrange(10):
                ans += f(i + 1, sumD + dig, 0)

    dp[i][sumD][tight] = ans
    return ans


def solve(L):
    if L == -1:
        return 0
    global s, N, dp
    s = map(int, str(L))
    N = len(s)
    dp = [[[-1 for i in xrange(2)] for j in xrange(163)] for k in xrange(20)]
    return f(0, 0, 1)

if __name__ == '__main__':
    for _ in xrange(input()):
        L, R = map(int, raw_input().split())
        print solve(R) - solve(L - 1)
