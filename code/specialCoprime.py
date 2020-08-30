from fractions import gcd


def solveDP(i, sumD, sumSq, check):
    global digits
    if i == -1:
        return 1 if gcd(sumD, sumSq) == 1 else 0

    if not check and dp[i][sumD][sumSq] != -1:
        return dp[i][sumD][sumSq]
    ans, endDig = 0, 0
    endDig = digits[i] if check else 9

    for curDig in xrange(0, endDig + 1):
        ans += solveDP(i - 1, sumD + curDig, sumSq + curDig *
                       curDig, check and curDig == endDig)

    if not check:
        dp[i][sumD][sumSq] = ans
    return ans


def solve(N):
    global digits
    if N == 0:
        return 0
    digits = map(int, list(str(N)))[::-1]

    n = len(digits)
    return solveDP(n - 1, 0, 0, 1)

if __name__ == '__main__':
    dp = [[[-1] * 1500 for i in xrange(200)] for j in xrange(20)]
    digits = []
    for _ in xrange(input()):
        l, r = map(int, raw_input().split())
        print solve(r) - solve(l - 1)
