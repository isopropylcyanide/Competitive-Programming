from sys import maxint
MAX = 100005


def prepareCost():
    for x in xrange(MAX - 4):
        for y in L:
            cost[x] = min(cost[x], y[0] + y[1] * x)

if __name__ == '__main__':
    N = input()
    L = []
    for _ in xrange(N):
        a, b = map(int, raw_input().split())
        L.append([a, b])

    cost = [maxint for i in xrange(MAX)]
    prepareCost()
    for _ in xrange(input()):
        print cost[input()]
