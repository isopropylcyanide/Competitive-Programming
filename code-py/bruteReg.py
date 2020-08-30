import re


def isMatch(pattern, string):
    if pattern.match(string) is not None:
        # print '%s matched with %s' % (string, pattern.pattern)
        return True
    return False


def origMatch(S):
    pat = re.compile(''.join(S))
    counts = sum([1 for i in L if isMatch(pat, i)])
    return counts


def mutateOnceMatch(S):
    counts = 0
    for starPos in stars:
        temp, S[starPos] = S[starPos], '.'
        pat = re.compile(''.join(S))
        counts = max(counts, sum([1 for i in L if isMatch(pat, i)]))
        S[starPos] = temp
    return counts

if __name__ == '__main__':
    S = list(raw_input().replace('*', '.'))
    L, N = [], input()
    stars = [i for i, j in enumerate(S) if j != '.']

    for _ in xrange(N):
        L.append(raw_input())

    maxCounts = origMatch(S)
    maxCounts = max(maxCounts, mutateOnceMatch(S))
    print maxCounts
