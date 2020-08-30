def minFlips(S, inp):
    ans, i = 0, 0
    while i < len(S):
        if S[i] == '-':
            ans += 1
            while i < len(S) and S[i] == '-':
                i += 1

        else:
            j = i + 1
            while j < len(S) and S[j] == '+':
                j += 1
            if j != len(S):
                ans += 1
            i = j

    print 'Case #%d: %d' % (inp + 1, ans)


if __name__ == '__main__':
    for i in xrange(input()):
        S = raw_input()
        minFlips(S, i)
