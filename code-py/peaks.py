mod = 10**9 + 9


def localMin(s):
    lmin = 0
    for i in xrange(1, len(s) - 1):
        if s[i - 1] > s[i] < s[i + 1]:
            lmin += 1
    return lmin


def localMax(s):
    lmax = 0
    for i in xrange(1, len(s) - 1):
        if s[i - 1] < s[i] > s[i + 1]:
            lmax += 1
    return lmax


def powerset(s):
    n = len(s)
    masks = [1 << j for j in xrange(n)]
    for i in xrange(2**n):
        yield [s[j] for j in range(n) if (masks[j] & i)]


def main():
    for _ in xrange(input()):
        N, A, B = map(int, raw_input().split())
        S, count = map(int, raw_input().split()), 0

        if A == B == 0:
            print (pow(2, N, mod) - 1 + mod) % mod
            continue

        if A >= N - 1 or B >= N - 1:
            print 0
            continue

        for i in powerset(S):
            if i != []:
                if localMin(S) == A and localMax(S) == B:
                    count = (count + 1) % S
        print count


if __name__ == '__main__':
    main()
# Hi
