from collections import deque


def solve():
    global fin, store, a, b

    q = deque()
    q.append((1, 0))

    while (q):
        curLevel, node = q.popleft()
        if curLevel == N:
            fin.add(node)
        elif node not in store:
            store.add(node)
            q.append((curLevel + 1, node + a))
            q.append((curLevel + 1, node + b))


if __name__ == '__main__':
    fin = set()
    store = set()
    for _ in xrange(input()):
        fin.clear()
        store.clear()
        N, a, b = map(int, raw_input().split())
        solve()
        print ' '.join([str(i) for i in sorted(fin)])
