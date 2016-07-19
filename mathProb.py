if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        L = []
        for k in xrange(N):
            L.append(list(raw_input()))

        okay = True
        for i in xrange(N / 2):
            if L[i] != L[N - 1 - i]:
                okay = False
                break

        if not okay:
            print 'NO'
        else:
            col = zip(*L)
            for i in xrange(len(col) / 2):
                if col[i] != col[len(col) - 1 - i]:
                    okay = False
                    break
            print 'YES' if okay else 'NO'
