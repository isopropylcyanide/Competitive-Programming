
N, Q = map(int, raw_input().split())
N = N + 1
S = '0' + raw_input()

P = [[0] * 26 for i in xrange(N)]
for i in xrange(1, N):
    d = ord(S[i]) - ord('a')
    for j in xrange(26):
        if j == d:
            P[i][j] = P[i - 1][j] + 1
        else:
            P[i][j] = P[i - 1][j]

for i in P[1:]:
    print i

for _ in xrange(Q):
    L, R, K = map(int, raw_input().split())
    Kthsmall, j = 0, 0

    while j < 26:
        Kthsmall += P[R][j] - P[L - 1][j]
        if Kthsmall >= K:
            break
        j += 1
    ans = chr(97 + j)
    if j == 26:
        print 'Out of range'
    else:
        print ans
