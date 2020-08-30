def solve(A, K):
    H = [0 for i in xrange(K)]

    for i in A:
        H[i % K] += 1

    c = 1 if H[0] > 0 else 0
    i, j = 1, K - 1
    while i <= j:
        if i < j:
            c += max(H[i], H[j])
        elif i == j:
            c += 1 if H[i] > 0 else 0
        i += 1
        j -= 1
    return c


if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    A = map(int, raw_input().split())
    print solve(A, K)
