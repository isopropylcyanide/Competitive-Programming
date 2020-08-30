
def brute():
    f = set()
    for a in xrange(1, A + 1):
        for b in xrange(1, B + 1):
            for c in xrange(1, C + 1):
                for d in xrange(1, D + 1):
                    if not ((a == b and c == d) or (a == d and b == c) or (a == c and b == d) or (a == b == c == d)) and a <= b <= c <= d and a ^ b ^ c ^ d != 0:
                        f.add(tuple(sorted([a, b, c, d])))
                        # print a, b, c, d, '\t', (a ^ b ^ c ^ d), sorted([a,
                        # b, c, d])

    return len(f)


def minXor(A, B, C, D):
    count = 0
    l = sorted([A, B, C, D])
    A, B, C, D = l[0], l[1], l[2], l[3]

    f = set()
    # Take 1 2 together and 3, 4
    print 'A and B together'
    a, b, x = A, B, A ^ B
    minm = min(a, b)
    for i in xrange(1, C + 1):
        for j in xrange(1, D + 1):
            if i ^ j == x:

                print a, b, i, j, '\t', (a ^ b ^ i ^ j), sorted([a, b, i, j])
                count += 1
                f.add(tuple(sorted([a, b, i, j])))

    print '\nA and C together'
    a, b, x = A, C, A ^ C
    for i in xrange(1, B + 1):
        for j in xrange(1, D + 1):
            if i ^ j == x:
                print a, b, i, j, '\t', (a ^ b ^ i ^ j), sorted([a, b, i, j])
                count += 1
                f.add(tuple(sorted([a, b, i, j])))

    print '\nA and D together'
    a, b, x = A, D, A ^ D
    for i in xrange(1, B + 1):
        for j in xrange(1, C + 1):
            if i ^ j == x:
                print a, b, i, j, '\t', (a ^ b ^ i ^ j), sorted([a, b, i, j])
                count += 1
                f.add(tuple(sorted([a, b, i, j])))

    print 'count: ', count

if __name__ == '__main__':
    A, B, C, D = map(int, raw_input().split())
    print brute()
    # print '\n\n\nSMART\n\n'
    # minXor(A, B, C, D)
