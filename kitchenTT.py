
def solve(K, C):
    _p = pow(K, 3)
    rem = _p - C
    for i in xrange(101):
        r = pow(i, 3) - C
        if r % _p == 0:
            return 'YES'

    return 'NO'

if __name__ == '__main__':
    for _ in xrange(input()):
        K, C = map(int, raw_input().split())
        print solve(K, C)
