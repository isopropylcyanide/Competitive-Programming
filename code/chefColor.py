
def main():
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        if N == 2 and M == 1 or N == 1 and M == 2:
            print "Yes"
        elif N == 1 or M == 1 or (N * M) % 2 == 1:
            print "No"
        else:
            print "Yes"

if __name__ == '__main__':
    main()
