
def solveSpec(s):
    if len(s) < 2:
        return "NO"

    from collections import Counter, deque
    d = Counter(s)

    q, mSet = deque(), set()
    odd = set()
    for k in s:
        if d[k] % 2 == 1:
            odd.add(k)

        if k not in mSet:
            q.append(k)
            mSet.add(k)

    if len(odd) > 1:
        return "NO"
    print 'q: ', q
    print 'set: ', mSet
    print 'odd: ', odd
    # One by one until the end process chars with even occurences and they
    # should occur in order
    n = len(q)
    q = list(q)
    if q[:n / 2] == q[n / 2:]:
        return "YES"
    else:
        return "NO"


if __name__ == '__main__':
    for _ in xrange(input()):
        print solveSpec(raw_input())
