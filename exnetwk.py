def main():
    def impossible():
        print -1, -1
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())

        if N == 1:
            impossible()

        elif N == 2:
            if M == 1:
                print 1, 2
            else:
                impossible()

        else:
            if M == N:
                for a, b in zip(range(1, N + 1), range(2, N + 1) + [1]):
                    print a, b
            else:
                impossible()


if __name__ == '__main__':
    main()
