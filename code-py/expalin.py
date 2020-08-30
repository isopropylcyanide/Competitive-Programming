from __future__ import division

"""
Task is to count the number of exponential sequences
that produce a palindrome when applied to S.
"""


def specialSequences(l):
    "Yields an exponential seq of indices"
    n = len(l)
    for i in xrange(n):
        lis = [i + 1]
        yield lis
        for j in xrange(i + 1, n):
            p = l[j] / l[i]
            if p <= 1 or int(p) != p:
                continue
            lis = [i + 1, j + 1]
            yield lis
            sk = (j + 1) * int(p)
            while sk <= n:
                lis.append(sk)
                sk *= int(p)
                yield lis


def main():
    for _ in xrange(input()):
        S = raw_input()
        count = 0

        for i in specialSequences(xrange(1, len(S) + 1)):
            s = [S[j - 1] for j in i]
            if s == s[::-1]:
                count += 1
        print count

if __name__ == '__main__':
    main()
