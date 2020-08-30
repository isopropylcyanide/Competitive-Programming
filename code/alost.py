

if __name__ == '__main__':
    for _ in xrange(input()):
        N, P, Q = map(int, raw_input().split())
        A = map(int, raw_input().split())
        A.sort()
        count = 0

        if P == 0:
            for i in A:
                if i % 2 == 0 and i / 2 <= Q:
                    Q -= i / 2
                    count += 1
        elif Q == 0:
            for i in A:
                if i <= P:
                    P -= i
                    count += 1
        else:
            for i in A:
                x = min(i / 2, Q)
                Q -= x
                t = i - 2 * x
                y = min(P, t)
                P, Z = P - y, t - y
                if Z == 0:
                    count += 1
                else:
                    Q, P = Q + x, P + y

        print count
