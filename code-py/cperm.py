MOD = 1000000007

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        if N == 1:
            print 0
        else:
            A = (pow(2, N - 1, MOD) - 2 + MOD) % MOD
            print A
