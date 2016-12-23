from bisect import bisect

if __name__ == '__main__':
    N, Q = map(int, raw_input().split())
    L = []
    P = [0] * N
    for _ in xrange(N):
        L.append(map(int, raw_input().split()))
    P[0] = L[0][1] - L[0][0] + 1
    for i in xrange(1, N):
        P[i] = P[i - 1] + L[i][1] - L[i][0] + 1

    for _ in xrange(Q):
        X = input()
        ind = bisect(P, X - 1)
        if ind == 0:
            print X + L[ind][0] - 1
        elif ind == N:
            print L[-1][1]
        else:
            X = X - P[ind - 1]
            print X + L[ind][0] - 1
