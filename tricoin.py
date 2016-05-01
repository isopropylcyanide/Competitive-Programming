from math import floor


def f(k):
    return int(floor(0.5 * ((pow(8 * k + 1, 0.5) - 1))))

if __name__ == '__main__':
    for _ in xrange(input()):
        print f(input())
