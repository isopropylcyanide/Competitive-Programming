n = 0
s = ''
dp = []


def f(i, tight, mi, ma, last, secLast):
    global n, s, dp
    """
    i: cur dig, tight: val is less or not
    mi and max: cuurent min and max digits
    last and secondlastDigits
    """
    ans = dp[i][tight][mi][ma][last][secLast]
    if ans != -1:
        return ans
    ans = 0
    if i == n:
        ans = mi + ma

    elif tight == 1:
        # cur number is less
        for dig in xrange(0, int(s[i]) + 1):
            if i == 0 and dig == 0:
                continue

            if i in [0, 1]:
                if dig == int(s[i]):
                    ans += f(i + 1, 1, 0, 0, dig, last)
                else:
                    ans += f(i + 1, 0, 0, 0, dig, last)
            else:
                _mi = 1 if secLast > last and last < dig else 0
                _ma = 1 if secLast < last and last > dig else 0
                # print 'For i: %d (%d , %d , %d, %d, %d)' % (i, secLast, last,
                # dig, _mi, _ma)
                if dig == int(s[i]):
                    ans += f(i + 1, 1, mi + _mi, ma + _ma, dig, last)
                else:
                    ans += f(i + 1, 0, mi + _mi, ma + _ma, dig, last)
    else:
        # no restriction on number
        for dig in xrange(0, 10):

            if i in [0, 1]:
                ans += f(i + 1, 0,  0, 0, dig, last)
            else:
                _mi = 1 if secLast > last and last < dig else 0
                _ma = 1 if secLast < last and last > dig else 0
                # print 'i: %d (%d , %d , %d, %d, %d)' % (i, secLast, last,
                # dig, _mi, _ma)
                ans += f(i + 1, 0, mi + _mi, ma + _ma, dig, last)

    dp[i][tight][mi][ma][last][secLast] = ans
    return ans


def minMaxScore(val):
    global s, n, dp
    s = str(val)
    n = len(s)
    # i, tight, mi, ma, last, secLast
    dp = [[[[[[-1 for i in xrange(10)] for j in xrange(10)]
             for k in xrange(10)]
            for l in xrange(10)] for m in xrange(2)] for t in xrange(13)]
    return f(0, 1, 0, 0, 0, 0)

if __name__ == '__main__':
    A = input()
    B = input()
    r = minMaxScore(B)
    l = minMaxScore(A - 1)
    print r - l
    # print 'For ', B, ' : ', r
    # print 'For ', A - 1, ' : ', l
