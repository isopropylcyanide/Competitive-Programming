
def maxRowColXor():
    if N == 1 and M == 1:
        print L[0][0]
        return

    maxCol = [0 for i in xrange(M)]
    maxRow = [0 for i in xrange(N)]

    for i in xrange(N):
        maxRow[i] = sum(L[i])

    for col in xrange(M):
        g = 0
        for row in xrange(N):
            g += L[row][col]
        maxCol[col] = g

    maxMAns = 0
    hashCol = set()
    for i in maxCol:
        if i not in hashCol:
            for j in maxRow:
                maxMAns = max(maxMAns, i ^ j)
            hashCol.add(i)
    print maxMAns


def max_xor(iterable):
    # Gaussian elimination
    array = list(iterable)  # make it a list so that we can iterate it twice
    if not array:  # special case the empty array to avoid an empty max
        return 0
    x = 0
    while True:
        y = max(array)
        if y == 0:
            return x
        # y has the leading 1 in the array
        x = max(x, x ^ y)
        # eliminate
        array = [min(z, z ^ y) for z in array]


if __name__ == '__main__':
    N, M = map(int, raw_input().split())
    L = []
    for _ in xrange(N):
        L.append(map(int, raw_input().split()))

    maxRowColXor()
