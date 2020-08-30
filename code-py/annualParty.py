if __name__ == '__main__':
    for _ in xrange(input()):
        A, B, C = [], [], []
        N = input()
        for i in xrange(N):
            a, b, c = map(int, raw_input().split())
            A.append(a)
            B.append(b)
            C.append(c)

        satisfy = 0
        for m in xrange(pow(2, N)):
            if m == 0:
                continue
            mask = bin(m)[2:].zfill(N)
            tA, tB, tC = 0, 0, 0
            count = 0
            for i, j in enumerate(mask):
                if j == '1':
                    count += 1
                    tA = max(tA, A[i])
                    tB = max(tB, B[i])
                    tC = max(tC, C[i])
            if tA + tB + tC <= 10000:
                satisfy = max(satisfy, count)

        print 'Case #%d: %d' % (_ + 1, satisfy)
