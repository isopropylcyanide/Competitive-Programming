
from collections import deque


def bounds(i, j):
    if i > 0 and i < N - 1 and j > 0 and j < M - 1:
        return True
    return False


def solve():
    cand = deque()
    for i in xrange(1, N - 1):
        for j in xrange(1, M - 1):
            if L[i][j] != 'C' and L[i][j] != '*':
                cand.append([i, j, '', False])

    maxS = ''
    print cand

    while cand:
        print '\n Current: ', cand[0]
        i, j, s, visCap = cand[0]
        cand.popleft()
        if visCap == 'C':
            # this guy has seen capital or
            if len(maxS) < len(s):
                maxS = s
        if L[i][j] == '*':
            continue

        # else we move left down up or right if viable, append
        # these cand movements to queue
        # see left
        if visCap != 'C':
            if bounds(i, j - 1) and L[i][j - 1] == '.':
                if L[i][j - 1] == 'C':
                    cand.append([i, j - 1, s + 'L', True])
                else:
                    cand.append([i, j - 1, s + 'L', False])
            # see right
            if bounds(i, j + 1) and L[i][j + 1] == '.':
                if L[i][j + 1] == 'C':
                    cand.append([i, j + 1, s + 'R', True])
                else:
                    cand.append([i, j + 1, s + 'R', False])
            # see down
            if bounds(i + 1, j) and L[i + 1][j] == '.':
                if L[i + 1][j] == 'C':
                    cand.append([i + 1, j, s + 'D', True])
                else:
                    cand.append([i + 1, j, s + 'D', False])
            # see up
            if bounds(i - 1, j) and L[i - 1][j] == '.':
                if L[i - 1][j] == 'C':
                    cand.append([i - 1, j, s + 'U', True])
                else:
                    cand.append([i - 1, j, s + 'U', False])

    return maxS

if __name__ == '__main__':
    N, M = map(int, raw_input().split())
    L = []

    for _ in xrange(N):
        L.append(list(raw_input()))

    print solve()
