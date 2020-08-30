from collections import Counter


def prelimTest():
    odd = 0
    for k in d.itervalues():
        if k % 2 == 1:
            odd += 1
            if odd > 1:
                return False
    return True

if __name__ == '__main__':
    s = raw_input()
    orig = s[:]
    d = Counter(s)
    n = len(s)

    if not prelimTest():
        print -1
    else:
        # it is possible. just swap
        s = s[:n / 2]
        d = Counter(s)
        _h, h = {}, {}
        # h stores first index of char
        for ind, i in enumerate(s):
            if i not in h:
                h[i] = ind

        _s, mid = '', None
        if n % 2 == 1:
            mid = orig[n / 2]
            _s = s[n / 2 + 1:]
        else:
            _s = s[n / 2:]

        _d = Counter(_s)
        for ind, i in enumerate(_s):
            if i not in _h:
                _h[i] = ind

        adjSwap = 0
        for i in d:
            if i not in _d:
                adjSwap += (n / 2 + 1 - d[i])
            elif i == mid:
                adjSwap += min(abs(_h[i] - n / 2), abs(h[i] - n / 2))
        print adjSwap / 2
