
def main():
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        A, B = [], []
        maxACol = [0 for i in xrange(M)]
        maxBRow = [0 for i in xrange(N)]

        for _ in xrange(M):
            A.append(map(int, raw_input().split()))

        for i in xrange(M):
            a = map(int, raw_input().split())
            B.append(a)
            maxBRow[i] = max(a)

        for col in xrange(M):
            g = []
            for row in xrange(N):
                g.append(A[row][col])
            maxACol[col] = max(g)

        count = 0
        for i in xrange(N):
            for j in xrange(M):
                if maxACol[j] == A[i][j] and maxBRow[i] == B[i][j]:
                    count += 1
        print count

if __name__ == '__main__':
    main()
