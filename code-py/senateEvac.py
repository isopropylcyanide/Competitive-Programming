
def solve(N, G, test):
    print 'Case #%d: ' % (test + 1),
    P = []
    for i in xrange(N):
        P.append([G[i], chr(i + 65)])

    P.sort(key=lambda x: -x[0])
    while P[0][0] != 0:
        if len(P) > 2 and P[0][0] == P[1][0] == P[2][0] or P[0][0] > P[1][0]:
            print P[0][1],
            P[0][0] -= 1

        elif P[0][0] == P[1][0]:
            print "%c%c" % (P[0][1], P[1][1]),
            P[0][0] -= 1
            P[1][0] -= 1

        P.sort(key=lambda x: -x[0])
    print

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        P = map(int, raw_input().split())
        solve(N, P, _)
