def vowel(c):
    return c in 'aeiou'


def longGoodLength(S):
    n = len(S)
    dp = [0] * n
    for i, val in enumerate(S):
        if vowel(val):
            if i - 1 >= 0 and vowel(S[i - 1]):
                dp[i] = dp[i - 1] + 1
            else:
                dp[i] = 1
        else:
            dp[i] = 1
    return max(dp)

if __name__ == '__main__':
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        A = map(int, raw_input().split())
        print longGoodLength(S)
