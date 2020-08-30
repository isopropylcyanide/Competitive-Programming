
def getWindow(A, w):
    N = len(A)
    max_l = [0] * N
    max_r = [0] * N
    max_l[0], max_r[-1] = A[0], A[-1]
    for i in xrange(1, N):
        max_l[i] = A[i] if i % w == 0 else max(max_l[i - 1], A[i])
        j = N - i - 1
        max_r[j] = A[j] if i % w == 0 else max(max_r[j + 1], A[j])

    B = [0] * (N - w + 1)
    j = 0
    for i in xrange(N - w + 1):
        B[j] = max(max_r[i], max_l[i + w - 1])
        j += 1
    return B


if __name__ == '__main__':
    N, X = map(int, raw_input().split())
    A = map(int, raw_input().split())

    h = {}
