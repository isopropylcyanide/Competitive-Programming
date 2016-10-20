
def dist(L):
    def euclid(a, b):
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2)

    if len(L) == 1:
        return 0
    N = len(L)
    maxDist = -1
    for i in xrange(N - 1):
        for j in xrange(i + 1, N):
            maxDist = max(maxDist, euclid(L[i], L[j]))
    return maxDist

if __name__ == '__main__':
    N = input()
    L = []
    for _ in xrange(N):
        L.append(map(int, raw_input().split()))
        print dist(L)
