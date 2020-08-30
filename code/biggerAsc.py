
def solve(S):
    return sum([1 for i in xrange(len(S) - 1) if S[i] < S[i + 1]])


if __name__ == '__main__':
    for _ in xrange(input()):
        S = raw_input()

        print solve(S)
