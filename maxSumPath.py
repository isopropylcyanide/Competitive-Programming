
from bisect import bisect_left


def binary_search(a, x, lo=0, hi=None):
    hi = hi if hi is not None else len(a)
    pos = bisect_left(a, x, lo, hi)
    return (pos if pos != hi and a[pos] == x else -1)

if __name__ == '__main__':
    for _ in xrange(input()):
        a, b = map(int, raw_input().split())
        M = map(int, raw_input().split())
        N = map(int, raw_input().split())

        cA = [M[0]]
        for i in xrange(1, a):
            cA.append(cA[-1] + M[i])

        cB = [N[0]]
        for i in xrange(1, b):
            cB.append(cB[-1] + N[i])

        # print cA
        # print cB

        A = []
        B = []
        for i in xrange(a):
            index = binary_search(N, M[i])
            if index != -1:
                # print 'Found some in N for : ', M[i], ' at ', index
                num = cA[i] + cB[-1] - cB[index]
                if num > cA[-1]:
                    A.append(num)
                else:
                    A.append(cA[-1])
            else:
                A.append(cA[-1])

        # print A

        for i in xrange(b):
            index = binary_search(M, N[i])
            if index != -1:
                # print 'Found some in N for : ', N[i], ' at ', index
                num = cB[i] + cA[-1] - cA[index]
                if num > cB[-1]:
                    B.append(num)
                else:
                    B.append(cA[-1])
            else:
                B.append(cB[-1])

        # print B

        print max(max(A), max(B))
