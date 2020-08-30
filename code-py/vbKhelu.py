def perSq(x):
    if x == 0:
        return 0
    return int(x ** 0.5) ** 2 == x

s, N = "", 0
dp = []


def get(i, sumSq, tight, B, rec):
    return i * 14 + sumSq * 975 + tight * 2 + B * 1024 + rec * 2


def f(i, sumSq, tight, B, rec):
    ind = get(i, sumSq, tight, B, rec)
    ans = dp[ind]
    if ans != -1:
        return ans
    ans = 0
    if i == N:
        if PS[sumSq] and rec == 1:
            ans = 1
        else:
            ans = 0
    else:
        if tight == 1:
            # last dig
            for dig in xrange(0, s[i] + 1):
                if i == 0 and dig == 0:
                    continue
                if dig == s[i]:
                    # check if dig is already set
                    if (B >> dig) & 1:
                        ans += f(i + 1, dig * dig + sumSq, 1, B, 1)
                    else:
                        # set the digit
                        ans += f(i + 1, dig * dig + sumSq,
                                 1, B | (1 << dig), rec)
                else:
                    if (B >> dig) & 1:
                        ans += f(i + 1, dig * dig + sumSq, 0, B, 1)
                    else:
                        # set the digit
                        ans += f(i + 1, dig * dig + sumSq,
                                 0, B | (1 << dig), rec)
        else:
            for dig in xrange(0, 10):
                if (B >> dig) & 1:
                    ans += f(i + 1, dig * dig + sumSq, 0, B, 1)
                else:
                    # set the digit
                    ans += f(i + 1, dig * dig + sumSq,
                             0, B | (1 << dig), rec)

    dp[ind] = ans
    return ans


def solve(L):
    global s, N, dp
    s = map(int, str(L))
    N = len(s)
    dp = [-1] * (14 * 975 * 2 * 1024 * 2)
    return f(0, 0, 1, 0, 0)

if __name__ == '__main__':
    PS = [1 if perSq(i) else 0 for i in xrange(976)]

    for _ in xrange(input()):
        L, R = map(int, raw_input().split())
        print solve(R) - solve(L - 1)
