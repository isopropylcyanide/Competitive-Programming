from heapq import heappop, heappush


def solve(N, A):
    if N == 0:
        return 0
    A.sort()
    h = {}
    print A
    for i in A:
        print '\n For i: ', i
        if i not in h:
            h[i] = []
        if i - 1 in h and len(h[i - 1]) > 0:
            heappush(h[i], heappop(h[i - 1]) + 1)
        else:
            heappush(h[i], 1)
        print h

    return min(h[x][0] for x in h if len(h[x]))

if __name__ == '__main__':
    for _ in xrange(input()):
        A = map(int, raw_input().split())
        N, A = A[0], A[1:]

        print solve(N, A)
