
def solve(A, N, K, D):
    if D >= N:
        # delete all elements
        print 0, 0
        for i in xrange(N):
            print 2, i + 1
        print -1

    else:
        # what to do
        B = zip(A, xrange(N))
        B.sort(key=lambda x: x[0])
        # Now B is sorted by values. Delete such values
        # ?a r

        deleted = set()
        s = '-1'
        i, dPt = N - 1, 0
        while i >= 0 and dPt < D:
            s = '2 %d\n' % (B[i][1] + 1) + s
            deleted.add(B[i][1])
            dPt += 1
            i -= 1

        # Now i points somewhere. If there are swap operations
        # Swap all heavy items to the front
        j = 0
        while j < i and K > 0:
            indA, indB = B[j][1], B[i][1]
            s = '1 %d %d\n' % (B[j][1] + 1, B[i][1] + 1) + s
            A[indA], A[indB] = A[indB], A[indA]
            j, i, K = j + 1, i - 1, K - 1

        restSum, lOp, rOp = 0, 0, 0
        for i in xrange(N):
            if i not in deleted:
                lOp += 1
                rOp += i
                restSum += A[i]
        a, r = restSum / lOp, restSum * 1. / rOp
        s = '%d %d\n' % (a, r) + s
        print s

if __name__ == '__main__':
    N, K, D = map(int, raw_input().split())
    A = map(int, raw_input().split())

    solve(A, N, K, D)
