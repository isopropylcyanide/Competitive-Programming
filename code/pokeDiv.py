from fractions import Fraction as f

if __name__ == '__main__':
    for _ in xrange(input()):
        n, m = map(int, raw_input().split())
        num = f(m, n) * f(1, 4)
        den = f(n - m, n) * f(2, 9)
        ans = num / (num + den)
        print '%d/%d' % (ans.numerator, ans.denominator)
