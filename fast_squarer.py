mod = 10**9 + 7
p = 23


def main():
    for _ in xrange(input()):
        N, D = map(int, raw_input().split())
        D = int(str(D) * N)

        ans = sum([(pow(p, a, mod) * int(b)) %
                   mod for a, b in enumerate(str(pow(D, 2)))])
        print ans % mod


if __name__ == '__main__':
    main()
