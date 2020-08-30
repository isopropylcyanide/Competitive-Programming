
def substr_len(l):
    i = 0
    while i < n - l + 1:
        yield s[i:i + l]
        i += 1


def parity(s):
    c, l = 0, ''
    h = {}
    for ind, i in enumerate(s):
        if i not in h:
            h[i] = c
            c += 1
        l += str(h[i])
    return l


if __name__ == '__main__':
    n, q = map(int, raw_input().split())
    s = raw_input()

    for _ in xrange(q):
        l, r = map(int, raw_input().split())
        l, r = l - 1, r - 1
        length = r - l + 1
        _s = s[l:r + 1]

        c = 0
        for sub in substr_len(length):
            if parity(sub) == parity(_s):
                c += 1
        print c
