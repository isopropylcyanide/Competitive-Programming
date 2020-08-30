

def f(i, ok1, ok2):
    ans = dp[i][ok1][ok2]
    if ans != -1:
        return ans
    ans = 0
    if i == N:
        if ok2 and ok1:
            ans = 1
        else:
            ans = 0
    else:
        if ok1 == 1:
            for dig in xrange(65, 91):
                if dig != ord(S[i]):
                    ans += f(i + 1, ok1, dig > ord(S[i]))
                else:
                    ans += f(i + 1, ok1, ok2)
        else:
            for dig in xrange(ord(S[i]), 91):
                if dig != ord(S[i]):
                    ans += f(i + 1, ok1, dig > ord(S[i]))
                else:
                    ans += f(i + 1, ok1, ok2)
    dp[i][ok1][ok2] = ans
    return ans


if __name__ == '__main__':
    S = raw_input()
    rS = S[::-1]
    N = len(S)
    dp = [[[-1 for i in xrange(2)] for j in xrange(2)]
          for k in xrange(10**5 + 2)]
    print f(0, 0, 0)
