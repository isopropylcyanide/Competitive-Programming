from collections import Counter
from itertools import combinations as ce


def isValidString(L):
    # Returns true if a string consists of alternating char
    if len(L) < 2:
        return False
    f, s = L[0], L[1]
    for ind, i in enumerate(L[2:]):
        if ind % 2 == 0 and i != f:
            return False
        if ind % 2 == 1 and i != s:
            return False

    return True


def solve(d, s):
    if len(d) == 1:
        return 0
    maxLen = 0
    for i in ce(d.iterkeys(), len(d) - 2):
        L = [k for k in s if k not in i]
        if isValidString(L):
            maxLen = max(maxLen, len(L))

    return maxLen


if __name__ == '__main__':
    N = input()
    s = raw_input()
    d = Counter(s)
    print solve(d, s)
