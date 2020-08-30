
def brute(H):
    S, P = 1, 0
    # how many do we eat : N possibilities
    maxP = 0
    for k in xrange(len(H)):
        # eat before and battle after
        S = (k + 1)
        P = Pre[k] * S
        maxP = max(maxP, P)
    return maxP


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        H = sorted(map(int, raw_input().split()))
        Pre = [H[-1]] * N
        for i in xrange(N - 2, -1, -1):
            Pre[i] = Pre[i + 1] + H[i]
        print Pre
        print brute(H)
