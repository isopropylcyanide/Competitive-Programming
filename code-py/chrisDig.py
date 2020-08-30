from decimal import Decimal as d


def oneUp(dig):
    return str((int(dig) + 9) % 10)


def rightSolve(a, K, b):
    n, m = len(a), len(b)
    if n >= m:
        return b
    return a + (min(K, m - n)) * '9'


def leftSolve(a, K, b):
    n, m = len(a), len(b)
    if n >= m:
        # Already greater
        return b
    diff = m - n
    K = min(K, diff)

    if K < diff:
        return '9' * K + a
    else:
        upper = b[-n:]
        if d(upper) < d(a):
            thatDig = oneUp(b[-n - 1])
        else:
            thatDig = b[-n - 1]
        return b[:m - n - 1] + thatDig + a[:]


def midSolve(a, K, b):
    n, m = len(a), len(b)
    if n >= m or n <= 1 or m <= 1:
        return b
    diff = m - n
    K = min(K, diff)
    strDif = str(d(b[1:]) - d(a[1:]))
    return a[0] + strDif[:K] + a[1:]

if __name__ == '__main__':
    N, K, X = raw_input().split()
    K = int(K)
    l = leftSolve(N, K, X).lstrip('0')
    r = rightSolve(N, K, X)
    m = midSolve(N, K, X)
    if d(r) <= d(X):
        l = str(max(d(l), d(r)))
    if d(m) <= d(X):
        l = str(max(d(m), d(l)))
    print l
