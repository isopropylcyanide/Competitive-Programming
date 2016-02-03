def getDist(V):
    n = len(V)
    dist = [0] * n

    # ls rs denotes left and right end of nearest ss
    ls, rs = 0, 0
    for j in xrange(n):
        if V[j] == 1:
            ls = rs = j
            break

    for i in xrange(n):
        if V[i] == 1:
            dist[i] = 0
            ls = i
            rs = i
            for j in xrange(i + 1, n):
                if V[j] == 1:
                    rs = j
                    break
        else:
            minm = min(abs(i - ls), abs(rs - i))
            dist[i] = minm

    print max(dist)

n, m = map(int, raw_input().strip().split(' '))
c = map(int, raw_input().strip().split(' '))
V = [0] * n
for i in c:
    V[i] = 1

getDist(V)
