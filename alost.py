

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        E, O = map(int, raw_input().split())

        L = []
        M = [(i + 1) * (N - i) for i in xrange(N)]
        H = {}
        for i in M:
            if i not in H:
                H[i] = 1
            else:
                H[i] += 1

        for i in M:
            if H[i] % 2 == 0:
                L.append(2)
            else:
                L.append(1)
        for i in L:
            print i,
        print
