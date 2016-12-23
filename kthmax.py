

def allSubArrays(A, N):
    """Store all subarrays of A"""
    sub = []
    for i in xrange(N):
        for j in xrange(i, N):
            sub.append(A[i:j + 1])
            sub[-1] += [0] * (N - len(sub[-1]))
    return sub


if __name__ == '__main__':
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        A = map(int, raw_input().split())
        sub = sorted(allSubArrays(A, N))[::-1]

        for __ in xrange(M):
            P = input()
            print max(sub[P - 1])
