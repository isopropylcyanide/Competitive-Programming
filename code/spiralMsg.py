
if __name__ == '__main__':
    L = []
    R, C = map(int, raw_input().split())
    for _ in xrange(R):
        L.append(list(raw_input()))

    b, t, l, r = R - 1, 0, 0, C - 1
    s = ""

    while b >= t and l <= r:
        # print leftmost col
        for i in xrange(b, t - 1, -1):
            s += L[i][l]
        l += 1

        # print top row
        for i in xrange(l, r + 1):
            s += L[t][i]
        t += 1

        # print rightmost col
        if t > b or l > r:
            break
        for i in xrange(t, b + 1):
            s += L[i][r]
        r -= 1

        # print bottommost row
        if t > b or l > r:
            break
        for i in xrange(r, l - 1, -1):
            s += L[b][i]
        b -= 1

    print sum([1 for i in s.split('#') if i != ''])
