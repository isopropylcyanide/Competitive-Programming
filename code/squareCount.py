
# Count all posisble squares in a rectangular grid, including diagonal

mod = 10**9 + 7

if __name__ == '__main__':
    for _ in xrange(input()):
        x, y = map(int, raw_input().split())
        x, y = x - 1, y - 1

        n = min(x, y)
        ans = (x * y * n * (n + 1) / 2) % mod
        ans = (ans - (x + y) * n * (n - 1) * (n + 1) / 3 + mod) % mod
        ans = (ans + n * (n - 1) * (n + 1) * (3 * n - 2) / 12) % mod
        ans = (ans + 1) % mod

        print 'Case #%d: %d' % (_ + 1, ans % mod)
