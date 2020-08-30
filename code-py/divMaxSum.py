
def main():
    N, K = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B, C = [], []

    prev = None
    _countB, _countC = 0, 0

    for i in xrange(0, (2 * N) - 1, 2):
        if (A[i] < A[i + 1]):
            # optimal way would be to put i in B and i + 1 in C
            # but if count  B = K, then
            # if I can do this without violating K, add to B first and then C, increase countB
            # else add to C and then B, reset countB and start countC
            if _countB < K:
                _countB += 1
                _countC = 0
                B.append(i)
                C.append(i + 1)
            else:
                C.append(i)
                B.append(i + 1)
                _countC += 1
                _countB = 0
        else:
            # optimal way would be to put i in C and i + 1 in B
            # but if count  C = K, then
            # if I can do this without violating K, add to C first and then B, increase countC
            # else add to C and then B, reset countB and start countC
            if _countC < K:
                _countC += 1
                _countB = 0
                B.append(i + 1)
                C.append(i)
            else:
                B.append(i)
                C.append(i + 1)
                _countB += 1
                _countC = 0

    for i in xrange(N):
        # print 'B contains index %s [%s]' % (B[i] + 1, A[B[i]])
        # B[i] += 1
        print B[i] + 1,
    print
    for i in xrange(N):
        # print 'C contains index %s [%s]' % (C[i] + 1, A[C[i]])
        # C[i] += 1
        print C[i] + 1,


if __name__ == "__main__":
    main()
