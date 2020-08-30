from itertools import permutations as pe

L = set()


def solve(s, n):
    if n <= 3:
        for p in pe(s):
            if int(''.join(p)) % 8 == 0:
                return 'YES'
        return 'NO'
    else:
        # Look for a subsequence in s, which is of three digits and
        for candidate in L:
            if s.find(candidate) != -1:
                return 'YES'
        return 'NO'


def precompute():
    # list of all three digit nos divisible by 8 along with their permutations
    global L
    for i in xrange(1001):
        if i % 8 == 0:
            st = "{0:03}".format(i)
            for p in pe(st):
                L.add(''.join(p))


if __name__ == '__main__':
    precompute()
    for _ in xrange(input()):
        s = raw_input()
        n = len(s)
        print solve(s, n)
