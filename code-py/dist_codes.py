def main():
    for _ in xrange(input()):
        S = raw_input()

        codes = set()
        for a, b in zip(S, S[1:]):
            s = ''.join((a, b))
            if s not in codes:
                codes.add(s)

        print len(codes)

if __name__ == '__main__':
    main()
