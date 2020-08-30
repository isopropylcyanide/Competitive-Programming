from itertools import permutations as perm


def is_square(n):
    if n == 1:
        return True
    x = n // 2
    seen = set([x])
    while x * x != n:
        x = (x + (n // x)) // 2
        if x in seen:
            return False
        seen.add(x)
    return True


def accumu(lis):
    total = 0
    for x in lis:
        total += x
        yield total


def solveBrute(N):
    maxmSq = 0
    maxPerm = []

    for i in perm(range(1, N + 1)):
        preP = list(accumu(i))
        sqLis = sum([1 for j in preP if is_square(j)])
        if sqLis == maxmSq:
            maxPerm.append(i)
        elif sqLis > maxmSq or maxPerm == []:
            maxmSq = sqLis
            maxPerm = [i]

    print maxmSq
    for k in maxPerm:
        print k, list(accumu(k))


def out(N):
    for i in xrange(1, N + 1, 2):
        print i,
    st = N if N % 2 == 0 else N - 1
    for i in xrange(st, 0, -2):
        print i,


if __name__ == '__main__':
    out(input())
