
# FInd if there is a title that can match both boxes


def match(i, j):
    # print 'match (%d, %d)' % (i, j)
    ans = dp[i][j]
    if ans != -1:
        return ans
    else:
        ans = 0

    if i == n and j == m:
        # print 'Im here'
        ans = 1

    elif i >= n or j >= m:
        ans = 0

    elif x[i] == '*' and y[j] == '*':
        ans = match(i + 1, j + 1) or match(i + 1, j + 2)\
            or match(i + 1, j + 3) or match(i + 1, j + 4)\
            or match(i + 2, j + 1) or match(i + 3, j + 1)\
            or match(i + 4, j + 1)

    elif x[i] == '*':
        ans = match(i + 1, j + 1) or match(i + 1, j + 2)\
            or match(i + 1, j + 3) or match(i + 1, j + 4)\
            or match(i + 1, j)

    elif y[j] == '*':
        ans = match(i + 1, j + 1) or match(i + 2, j + 1)\
            or match(i + 3, j + 1) or match(i + 4, j + 1)\
            or match(i, j + 1)

    elif x[i] == y[j]:
        # print 'Equal hars %c and %c are not equal' % (x[i], y[j])
        ans = match(i + 1, j + 1)
    else:
        ans = 0
    dp[i][j] = ans
    return ans

if __name__ == '__main__':
    for _ in xrange(input()):
        x = raw_input()
        y = raw_input()
        n, m = len(x), len(y)
        dp = [[-1 for i in xrange(n + 10)] for j in xrange(m + 10)]

        ans = match(0, 0)
        print 'Case #%d: %s' % (_ + 1, 'TRUE' if ans else 'FALSE')
