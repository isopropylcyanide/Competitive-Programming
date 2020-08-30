
def mutateOnceMatch(S):
    counts = []
    for pos, val in enumerate(S):
        if val == '*':
            counts.append(N)
        else:
            counts.append(m[pos][ord(val) - 97])

    counts.sort()
    return max(counts[1], counts[0])

if __name__ == '__main__':
    S = raw_input().strip()
    N = input()
    m = [[0 for i in xrange(26)] for j in xrange(3005)]

    for _ in xrange(N):
        for j, i in enumerate(raw_input().strip()):
            m[j][ord(i) - 97] += 1

    print mutateOnceMatch(S)
