
# Find numbers of non negative numbers strictly less than n, having sum of
# squares of  digits modulo 3 to be zero

MAX = 100005


def f(i, modVal, less):
    # what index, current modVal are we on
    # less: 1 num == N, else num < N
    ans = dp[i][modVal][less]
    if ans != -1:
        return ans
    ans = 0
    if i == n:
        # We are at the end
        if modVal == 0 and less == 0:
            ans = 1
        else:
            ans = 0
    else:
        if less:
            # if num constructed so far is less
            for dig in xrange(0, int(s[i]) + 1):
                if dig == int(s[i]):
                    ans += f(i + 1, (modVal + dig * dig) % 3, 1)
                else:
                    ans += f(i + 1, (modVal + dig * dig) % 3, 0)
        else:
            # num is not less, we can add any value
            for dig in xrange(0, 10):
                ans += f(i + 1, (modVal + dig * dig) % 3, 0)
    dp[i][modVal][less] = ans
    return ans

if __name__ == '__main__':
    for _ in xrange(input()):
        dp = [[[-1 for k in range(2)] for i in xrange(3)] for j in xrange(MAX)]
        s = raw_input()
        n = len(s)
        print f(0, 0, 1)
