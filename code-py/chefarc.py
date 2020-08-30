
from collections import deque


def bounds(x, y):
    global N, M, L, V
    if x < 0 or y < 0 or x >= N or y >= M:
        return False
    if L[x][y] == 1 or V[x][y] == 1:
        return False
    return True


def pathOnce(q, D, K):
    global N, M, L, V
    while q:
        node = q.popleft()
        d, x, y = node[0], node[1][0], node[1][1]
        D[x][y] = d
        for i in xrange(K + 1):
            for j in xrange(K + 1):
                if i + j <= K:
                    xUp, yUp = x + i, y + j
                    xDo, yDo = x - i, y - j
                    if bounds(xUp, yUp):
                        V[xUp][yUp] = 1
                        q.append((d + 1, (xUp, yUp)))

                    if bounds(xUp, yDo):
                        V[xUp][yDo] = 1
                        q.append((d + 1, (xUp, yDo)))

                    if bounds(xDo, yUp):
                        V[xDo][yUp] = 1
                        q.append((d + 1, (xDo, yUp)))

                    if bounds(xDo, yDo):
                        V[xDo][yDo] = 1
                        q.append((d + 1, (xDo, yDo)))


def solve():
    global N, M, K1, K2, L, V, D1, D2
    q = deque()
    q.append((0, (0, 0)))
    V[0][0] = 1
    pathOnce(q, D1, K1)
    #
    # print 'D1: '
    # for i in D1:
    #     print i
    # print

    V = [[0 for i in xrange(M)] for j in xrange(N)]
    q.append((0, (0, M - 1)))
    V[0][M - 1] = 1
    pathOnce(q, D2, K2)
    # print 'D2: '
    # for i in D2:
    #     print i
    # print

    # edge cases that may arise
    if K1 == 0 and K2 == 0:
        return -1
    elif K1 == 0:
        return D2[0][0] if D2[0][0] > 0 else -1
    elif K2 == 0:
        return D1[0][M - 1] if D1[0][M - 1] > 0 else -1

    ans = 10**9
    for i in xrange(N):
        for j in xrange(M):
            if D1[i][j] != -1 and D2[i][j] != -1:
                ans = min(ans, max(D1[i][j], D2[i][j]))
    return ans if ans != 10 ** 9 else -1

if __name__ == '__main__':
    for _ in xrange(input()):
        N, M, K1, K2 = map(int, raw_input().split())
        L = []
        for __ in xrange(N):
            L.append(map(int, raw_input().split()))

        V = [[0 for i in xrange(M)] for j in xrange(N)]
        D1 = [[-1 for i in xrange(M)] for j in xrange(N)]
        D2 = [[-1 for i in xrange(M)] for j in xrange(N)]
        print solve()
