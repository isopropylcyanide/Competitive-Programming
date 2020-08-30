import random


if __name__ == '__main__':
    # T = random.randrange(1, 10)
    T = 10
    print T
    for i in xrange(T):
        # N = random.randrange(1, pow(10, 5))
        N = pow(10, 5)
        print N
        for _ in xrange(N):
            A = random.randrange(pow(10, 6), pow(10, 7))
            print A,
