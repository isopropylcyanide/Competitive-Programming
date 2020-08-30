mod = 10**9 + 7


def brute(n, e, P):
    ans = 1
    C = [0] * e
    R = [0] * e
    # print ans
    # print C
    # print R
    for _ in xrange(1, n + 1):
        ans = (ans * e) % mod
        # Subtract some false combinations
        for i in xrange(e):
            if C[i] == P[i]:
                if R[i] == 0:
                    R[i] = 1
                else:
                    R[i] = (R[i] * abs(_ - P[i])) % mod
                    # print 'Stage is ', _, abs(_ - P[i])
                    # print R[i]
            else:
                C[i] += 1
        for i in R:
            ans = (ans - i + mod) % mod
    print (ans + mod) % mod
    # print C
    # print R


if __name__ == '__main__':
    for _ in xrange(input()):
        n, e = map(int, raw_input().split())
        B = map(int, raw_input().split())
        brute(n, e, B)
