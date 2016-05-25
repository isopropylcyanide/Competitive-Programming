def solver(N, K):
    A = range(1, N + 1)
    if N & 1:
        if K == 0:
            return ' '.join([str(i) for i in A])
        else:
            return -1
    # else N is even
    if K > N / 2:
        return -1
    else:
        # there's a valid order
        m = set()
        for i in xrange(N):
            minm = i + 1 + K
            maxm = i + 1 - K

            if maxm >= 1 and maxm not in m:
                A[i] = maxm
                m.add(maxm)

            elif minm <= N and minm not in m:
                A[i] = minm
                m.add(minm)
            else:
                return -1
        return ' '.join([str(i) for i in A])


if __name__ == '__main__':
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        print solver(N, K)
