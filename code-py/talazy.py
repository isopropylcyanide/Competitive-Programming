
def solve(N, A):
    if N == 2:
        return min(A)
    diff = A[1] - A[0]
    thold = 0
    curRemoval = 10**9

    D = []
    for i in xrange(N - 1):
        D.append(A[i + 1] - A[i])

    d = A[1] - A[0]
    for i in xrange(1, N):
        cur = A[i + 1] - A[i]

    print D

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        print solve(N, A)
