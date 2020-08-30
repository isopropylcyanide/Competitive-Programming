
def cost(L, r, A):
    cost = 0
    for i in xrange(len(L)):
        cost += (L[i][0] - A[i][0])**2
    return cost

if __name__ == '__main__':
    N = input()
    L = []
    for _ in xrange(N):
        A = map(int, raw_input().split())
        L.append(zip(xrange(N), A))

    for i in xrange(N):
        row = L[i]
        incSort = sorted(row, key=lambda x: x[1])
        decSort = sorted(row, key=lambda x: -x[1])
        costInc = cost(L[i], i, incSort)
        costDec = cost(L[i], i, decSort)
        if costInc < costDec:
            print ' '.join([str(i[1]) for i in incSort])
        else:
            print ' '.join([str(i[1]) for i in decSort])
