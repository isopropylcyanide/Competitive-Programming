def perSq(N): return False


def req(N):
    c = 0
    for i in xrange(1, N + 1):
        if perSq(sum(a**2 for a in map(int, str(i)))):
            if len(str(i)) != len(set(str(i))):
                print i
                c += 1
    return c


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


def miller_rabin(n, k=10):
    from random import randrange
    if n == 2:
        return True
    if not n & 1:
        return False

    def check(a, s, d, n):
        x = pow(a, d, n)
        if x == 1:
            return True
        for i in xrange(s - 1):
            if x == n - 1:
                return True
            x = pow(x, 2, n)
        return x == n - 1

    s = 0
    d = n - 1

    while d % 2 == 0:
        d >>= 1
        s += 1

    for i in xrange(k):
        a = randrange(2, n - 1)
        if not check(a, s, d, n):
            return False
    return True
