
# How to efficiently merge intervals given k queries


def mergeInterval(l):
    l.sort()
    res = [l[0]]
    for i in xrange(1, len(l)):
        prev, cur = res[-1], l[i]
        if prev[1] >= cur[0]:
            prev[1] = max(prev[1], cur[1])
        else:
            res.append(cur)
    return sum([i[1] - i[0] + 1 for i in res])

if __name__ == '__main__':
    N, M, k = map(int, raw_input().split())

    total = N * M
    H = {}

    for _ in xrange(k):
        r, c1, c2 = map(int, raw_input().split())
        if r not in H:
            H[r] = [[c1, c2]]
        else:
            H[r].append([c1, c2])
    for i in H:
        total -= mergeInterval(H[i])
    print total
