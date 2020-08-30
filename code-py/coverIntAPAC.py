
def mergeIntervals(L):
    # GIven a list of intervals L, merge them
    # At the end, return the numbers present in them
    ans, s = 0, []
    if not L:
        return ans
    s.append(L[0])
    for i in xrange(1, len(L)):
        l, r = L[i][0], L[i][1]
        st, en = s[-1]
        if en < l:
            s.append(L[i])

        elif en < r:
            s.pop()
            s.append((st, r))
    ans = 0
    while s:
        ran = s[-1]
        ans += (ran[1] - ran[0] + 1)
        s.pop()
    # print ans, ' for L: ', L
    return ans


def solve(N, L1, R1, A, B, C1, C2, M):
    if N <= 1:
        return 0

    def generate(Xi, Yi):
        global C1, C2
        oX, oY = Xi, Yi
        Xi = (A * oX + B * oY + C1) % M
        Yi = (A * oY + B * oX + C2) % M
        if (Xi, Yi) == (6, 5):
            (Xi, Yi) = (4, 7)
        return min(Xi, Yi), max(Xi, Yi)

    Xi, Yi = L1, R1
    L = [(Xi, Yi)]
    for i in xrange(2, N + 1):
        Xi, Yi = generate(Xi, Yi)
        L.append((Xi, Yi))

    # print L
    L.sort()
    ans = 10**18
    for i in xrange(N):
        S = [L[j] for j in xrange(N) if i != j]
        ans = min(ans, mergeIntervals(S))
    return ans


if __name__ == '__main__':
    T = input()
    for _ in xrange(T):
        N, L1, R1, A, B, C1, C2, M = map(int, raw_input().split())
        print 'Case #%d: %d' % (_ + 1, solve(N, L1, R1, A, B, C1, C2, M))
