
MOD = 1000000007

A = []


def modInv(b):
    # mod inv of b with MOD
    return pow(b, MOD - 2, MOD)


def computeConstants():
    global A
    A = [0] * 305
    A[1] = Y[1]

    for i in xrange(2, N + 1):
        lhs, rhs, incr = Y[i], 0, 1
        for k in xrange(i - 1, 0, -1):
            temp = (A[incr] * Y[k]) % MOD
            temp = (-temp + MOD) % MOD if incr % 2 == 0 else temp
            rhs = (rhs + temp) % MOD
            incr += 1
        lhs = ((lhs - rhs + MOD) * modInv(incr)) % MOD
        A[i] = lhs if incr % 2 == 1 else (-lhs + MOD) % MOD

    for i in xrange(2, N + 1, 2):
        A[i] = (-A[i] + MOD) % MOD


def preCompute(lim):
    for i in xrange(N + 1, lim + 1):
        rhs, incr, k = 0, 1, i - 1
        while incr <= N:
            rhs = (rhs + (A[incr] * Y[k]) % MOD) % MOD
            incr, k = incr + 1, k - 1
        Y.append(rhs)

if __name__ == '__main__':
    for _ in xrange(input()):
        N, _ = map(int, raw_input().split())
        Y = map(int, raw_input().split())
        Q = map(int, raw_input().split())
        Y.insert(0, 0)

        computeConstants()
        maxm = max(Q)
        preCompute(maxm)
        for i in Q:
            print Y[i],
        print
