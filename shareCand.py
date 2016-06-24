from fractions import gcd


def solve(A, B, C, D):
    if A == B:
        return 0

    curBest, a = abs(A - B), gcd(C, D)
    return abs(curBest - int(a * round(curBest * 1.0 / a)))

if __name__ == '__main__':
    for _ in xrange(input()):
        A, B, C, D = map(int, raw_input().split())
        print solve(A, B, C, D)
