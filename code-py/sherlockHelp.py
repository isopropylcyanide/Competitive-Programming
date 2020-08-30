
M = 10 ** 9 + 7


def main():
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())

        if K == 1 and N > 1:
            print 0
            continue

        print (K % M * pow(K - 1, N - 1, M)) % M


if __name__ == '__main__':
    main()
