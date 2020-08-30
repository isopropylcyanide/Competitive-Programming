from fractions import gcd

if __name__ == '__main__':
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())

    B_gcd = reduce(lambda x, y: gcd(x, y), B)
    cnt = 0

    if (all(B_gcd % i == 0 for i in A)):
        prod = reduce(lambda x, y: x * y / gcd(x, y), A)
        for i in xrange(prod, B_gcd + 1, prod):
            if B_gcd % i == 0:
                cnt += 1
        print cnt
    else:
        print 0
