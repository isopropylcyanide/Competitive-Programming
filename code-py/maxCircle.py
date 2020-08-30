
def dfs(i, sumT, V, G):
    if V[i] == 1:
        return sumT
    else:
        V[i] = 1
        sumT += 1
        if V[G[i]] == 1:
            return sumT
        return dfs(G[i], sumT, V, G)


def maxCircle(N, B, inp):
    G = {}
    hasBFF = {}

    for i in xrange(N):
        G[i] = B[i] - 1
        try:
            hasBFF[B[i] - 1].append(i)
        except:
            hasBFF[B[i] - 1] = [i]

    print G
    print hasBFF

    maxM = 0
    for i in xrange(N):
        V = [0 for k in xrange(N)]
        maxCycle = dfs(i, 0, V, G)
        maxM = max(maxM, maxCycle)
    print 'Case #%d:' % (inp + 1), maxM


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        B = map(int, raw_input().split())
        maxCircle(N, B, _)
