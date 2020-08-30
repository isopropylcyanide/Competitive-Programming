
from bisect import bisect
from sys import stdin, stdout
MOD = 1000000007


def search(pattern, text):
    """Search with the sentinel."""
    result = []
    s = '{0}${1}'.format(pattern, text)
    n = len(s)

    zs, l, r = [0] * n, 0, 0
    for i in xrange(1, n):
        if i > r:
            l = r = i
            while r < n and s[r - l] == s[r]:
                r += 1
            zs[i] = r - l
            r -= 1
        else:
            k = i - l
            if zs[k] < r - i + 1:
                zs[i] = zs[k]
            else:
                l = i
                while r < n and s[r - l] == s[r]:
                    r += 1
                zs[i] = r - l
                r -= 1
    m = len(pattern)
    for i, z in enumerate(zs):
        if z == m:
            result.append(i - m - 1)

    return result


def solve(ind, patLen):
    n = len(ind)
    if n == 0:
        return 0
    elif patLen == 1:
        return pow(2, n, MOD) - 1

    dp = [0] * n
    dp[0] = 1

    # pre = [-1] * n
    # for i in xrange(1, n):
    #     pre[i] = br(ind[:i], ind[i] - patLen) - 1

    for i in xrange(1, n):
        if ind[i] - ind[i - 1] >= patLen:
            dp[i] = (dp[i - 1] * 2 + 1) % MOD

        else:
            # j = pre[i]
            j = bisect(ind, ind[i] - patLen, 0, i) - 1
            # j = i - 1
            # while j >= 0:
            #     if ind[i] - ind[j] >= patLen:
            #         break
            #     j -= 1
            if j >= 0:
                dp[i] = (dp[i - 1] + dp[j] + 1) % MOD
            else:
                dp[i] = (dp[i - 1] + 1) % MOD

    return dp[n - 1]

if __name__ == '__main__':
    N = int(stdin.readline().strip())

    for i in xrange(N):
        s = stdin.readline().strip()
        f = stdin.readline().strip()
        m = len(f)
        Z = search(f, s)
        stdout.write(str(solve(Z, m) % MOD) + '\n')
