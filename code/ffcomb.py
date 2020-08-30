
from itertools import chain, combinations


def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s) + 1))


def ssum(l, tOr):
    current = 0
    return ssum_h(l, len(l), current, 0, 10**18)


def ssum_h(l, n, subset, tOr, minm):
    ans = dp[n][subset][tOr]
    if ans != -1:
        return ans
    if tOr == mainEq:
        minm = min(minm, subset)
        return minm

    if n == 0:
        return minm

    if l[n - 1] != tOr:
        a = ssum_h(l, n - 1, subset, tOr, minm)
        b = ssum_h(l, n - 1, subset + h[l[n - 1]], tOr | l[n - 1], minm)
        return min(a, b)
    else:
        return ssum_h(l, n - 1, subset, tOr, minm)
    dp[n][subset][tOr] = minm

if __name__ == '__main__':
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        C = map(int, raw_input().split())

        h = {}
        for i in xrange(N):
            h[1 << i] = C[i]

        for _ in xrange(M):
            Q = map(int, raw_input().split())
            cost, num, mask = Q[0], Q[1], 0
            for i in Q[2:]:
                mask |= (1 << (i - 1))
            if mask in h:
                h[mask] = min(h[mask], cost)
            else:
                h[mask] = cost
        d = sum(h.itervalues())
        # Now all possible masks are prepared with their cost
        # Find the suitable masks that or to mainEq and whose cost is the least
        dp = [[[-1 for i in xrange(pow(2, N))]
               for j in xrange(d + 1)] for k in xrange(20)]
        mainEq = pow(2, N) - 1
        keys = list(h.iterkeys())
        minCost = 10**18

        minCost = ssum(keys, 0)
        print minCost
