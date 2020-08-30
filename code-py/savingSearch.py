

def rec(curSer, curFil):
    ans = dp[curSer][curFil]
    if ans != -1:
        return ans
    ans = 0
    if curFil == NF:
        ans = 0

    elif ser[curSer] == fil[curFil]:
        ans, j = 1, 10**18
        for i in xrange(NS):
            if i != curSer:
                j = min(j, rec(i, curFil + 1))
        ans += j

    else:
        ans += rec(curSer, curFil + 1)
    dp[curSer][curFil] = ans
    return ans

if __name__ == '__main__':
    for _ in xrange(input()):
        NS = input()
        ser = []
        for i in xrange(NS):
            ser.append(raw_input())

        NF = input()
        fil = []
        for i in xrange(NF):
            fil.append(raw_input())

        ans = 10**18
        dp = [[-1 for i in xrange(120)] for j in xrange(105)]
        for i in xrange(NS):
            ans = min(ans, rec(i, 0))

        print 'Case #%d: %d' % (_ + 1, ans)
