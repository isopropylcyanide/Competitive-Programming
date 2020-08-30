from math import sqrt


def dist(x1, y1, x2, y2):
    return sqrt((x2 - x1)**2 + (y2 - y1)**2)


def eq(d1, d2):
    return abs(d1 - d2) < 10**-6


def gt(d1, d2):
    return d1 > (d2 + 10 ** -6)


def lt(d1, d2):
    return d1 < (d2 - 10**-6)


def main():
    subtaskID = input()
    for _ in xrange(input()):
        x1, y1, x2, y2, x3, y3 = map(int, raw_input().split())

        dC = dist(x1, y1, x2, y2)
        dA = dist(x2, y2, x3, y3)
        dB = dist(x1, y1, x3, y3)

        if eq(dA, dB) or eq(dA, dC) or eq(dB, dC):
            typeTr = "Isosceles"
        else:
            typeTr = "Scalene"

        if subtaskID == 1:  # side only
            print typeTr + ' triangle'
        else:
            a = sorted([dA, dB, dC])
            longest = a[2]

            if eq(a[1] ** 2 + a[0] ** 2, longest ** 2):
                angTr = 'right'

            elif gt(a[1] ** 2 + a[0] ** 2, longest ** 2):
                angTr = 'acute'
            else:
                angTr = 'obtuse'

            print typeTr + ' ' + angTr + ' triangle'

if __name__ == '__main__':
    main()
