
if __name__ == '__main__':
    N = input()
    g = {}
    for _ in xrange(N):
        x1, y1, x2, y2 = map(int, raw_input().split())
        if (x1, y1) not in g:
            g[(x1, y1)] = [(x2, y2)]
        else:
            g[(x1, y1)].append((x2, y2))

        if (x2, y2) not in g:
            g[(x2, y2)] = [(x1, y1)]
        else:
            g[(x2, y2)].append((x1, y1))
    numOdd = 0
    for i in g:
        if len(g[i]) % 2 == 1:
            numOdd += 1
    print 'YES' if numOdd in [0, 2] else 'NO'
