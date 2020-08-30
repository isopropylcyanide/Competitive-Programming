def solve(N, K, A):
    last, P, ans = -1, [0] * N, 0

    for i in xrange(N):
        if A[i] == 1:
            last = i
        P[i] = last

    i = 0
    while i < N:
        take = P[min(i + K - 1, N - 1)]
        if take == -1 or take + K - 1 < i:
            return -1
        i = take + K
        ans += 1
    return ans

if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    A = map(int, raw_input().split())
    print solve(N, K, A)
