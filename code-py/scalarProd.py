
def scalarProd(a):
    from collections import Counter
    vec = []
    for i in xrange(1, len(a), 2):
        vec.append((a[i], a[i - 1]))

    d = Counter(vec)
    scalarProdLis = dict()

    for i in vec:
        if d[i] > 1:
            scalarProdLis[(i[0] * i[0] + i[1] * i[1]) % M] = 0

    vec = list(set(vec))

    for i in xrange(len(vec)):
        for j in xrange(i + 1, len(vec)):
            scalarProdLis[(
                (vec[i][0] * vec[j][0] + vec[i][1] * vec[j][1]) % M)] = 0

    print len(scalarProdLis) % M


def gen():
    ans = [0, C]
    for i in xrange(2 * N):
        ans.append((ans[-2] + ans[-1]) % M)

    scalarProd(ans[2:])

if __name__ == '__main__':
    C, M, N = map(int, raw_input().split())
    if N == 1:
        print 0
    else:
        gen()
