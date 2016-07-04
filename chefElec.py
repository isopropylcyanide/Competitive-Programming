MAX = 10**9


def minWire(N, E, A):
    s, i = 0, 0
    while E[i] != '1':
        i += 1
    s += A[i] - A[0]
    st, i = i, N - 1

    while E[i] != '1':
        i -= 1
    s += A[N - 1] - A[i]
    lf, en, i, tmps, maxm = st, i, st + 1, 0, 0

    while i <= en:
        maxm = max(maxm, A[i] - A[i - 1])
        if E[i] == '1':
            if E[i - 1] == '0':
                tmps = A[i] - A[lf]
                s += tmps - maxm
            lf, maxm, tmps = i, 0, 0
        i += 1
    return s

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        E = list(raw_input().strip())
        A = map(int, raw_input().split())

        print minWire(N, E, A)
