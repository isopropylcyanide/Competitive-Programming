
if __name__ == '__main__':
    N, C = map(int, raw_input().split())
    L = []
    for _ in xrange(C):
        u, v = map(int, raw_input().split())
        L.append([u, v])

    L.sort(key=lambda x: -x[1])
    ans, mb = 0, 0
    for i in L:
        if mb >= N:
            break
        else:
            mbox = min(i[0], N - mb)
            ans += i[1] * mbox
            mb += mbox
        # print mbox, ans, mb
    print ans
