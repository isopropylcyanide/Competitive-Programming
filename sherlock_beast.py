
"""
find the largest Decent Number having N digits.

A Decent Number has the following properties:

Its digits can only be 3's and/or 5's.
The number of 3's it contains is divisible by 5.
The number of 5's it contains is divisible by 3.
"""


def solve(n):
    fives = -1
    for f in xrange(n + 1):
        if f % 3 == 0 and (n - f) % 5 == 0:
            fives = f

    if fives == -1:
        print '-1'
    else:
        print '5' * fives + '3' * (n - fives)


def main():
    for _ in xrange(input()):
        solve(input())

if __name__ == '__main__':
    main()
