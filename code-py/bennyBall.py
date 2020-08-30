
if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        x, a, b, t = map(int, raw_input().split())

        P, times = [0] * N, 0

        for __ in xrange(t):
            P[x] += 1
            if P[x] >= A[x]:
                P[x], times = 0, times + 1
            x = (a * x + b) % N
            # print P
        print times
