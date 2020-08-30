
if __name__ == '__main__':
    x, y = map(int, raw_input().split())
    N = input()
    a, b = 0, 0
    for _ in xrange(N):
        u, v = map(int, raw_input().split())
        a += u
        b += v
    print x - a, y - b
