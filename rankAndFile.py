import itertools as it
from collections import Counter


def missingRow(N, L, inp):
    d = Counter(list(it.chain.from_iterable(L)))
    S = sorted([i for i in d if d[i] % 2 == 1])

    print 'Case #%d:' % (inp + 1), ' '.join([str(k) for k in S])


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        L = []
        for i in xrange(2 * N - 1):
            L.append(map(int, raw_input().split()))
        missingRow(N, L, _)
