
MAX = 100005
P = [1 for i in xrange(MAX)]
M = [i for i in xrange(MAX)]


def preCompute():
    global P, M
    P[0] = P[1] = 0
    for i in xrange(4, MAX, 2):
        P[i] = 0
        M[i] = 2

    for i in xrange(3, MAX, 2):
        if P[i]:
            for j in xrange(i * i, MAX, i):
                if P[j]:
                    P[j], M[j] = 0, i


def solve(a, b, m):
    return sum(1 for i in xrange(a, b + 1) if M[i] > 1 and M[i] <= m)

if __name__ == '__main__':
    preCompute()
    a, b, m = map(int, raw_input().split())
    print solve(a, b, m)
