
from math import log, floor
mod = 1000000007

if __name__ == '__main__':
    N = input()
    F = map(int, raw_input().split())
    for q in xrange(input()):
        Q = map(int, raw_input().split())

        if Q[0] == 1:  # change value
            p, f = Q[1], Q[2]
            F[p - 1] = f
        else:
            # compute first digit and product
            r = Q[1]
            s = 1
            logSum = 0

            for i in xrange(0, N, r):
                s = (s % mod * F[i] % mod) % mod
                logSum = (logSum + log(F[i], 10))

            print str(pow(10, logSum - floor(logSum)))[0], s % mod
