
def diagonal(x1, y1, x2, y2):
    if abs(x1 - x2) == abs(y1 - y2):
        return True
    return False


def solve():
    C = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 1, 0, 1, 0, 1],
        [0, 1, 0, 1, 0, 1, 0, 1, 0],
        [0, 0, 1, 0, 1, 0, 1, 0, 1],
        [0, 1, 0, 1, 0, 1, 0, 1, 0],
        [0, 0, 1, 0, 1, 0, 1, 0, 1],
        [0, 1, 0, 1, 0, 1, 0, 1, 0],
        [0, 0, 1, 0, 1, 0, 1, 0, 1],
        [0, 1, 0, 1, 0, 1, 0, 1, 0],
    ]
    for _ in xrange(input()):
        x1, y1, x2, y2 = map(int, raw_input().split())

        if any(x > 8 or x < 1 for x in [x1, x2, y1, y2]):
            print -1
            continue

        if diagonal(x1, y1, x2, y2):
            print 0

        elif C[x1][y1] != C[x2][y2]:
            print -1
        else:
            print 1


if __name__ == '__main__':
    limit = 10 ** 15
    solve()
