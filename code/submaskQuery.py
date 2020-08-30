
def powerset(s):
    # finds powerset of a given range
    n = len(s)
    masks = [1 << j for j in xrange(n)]
    for i in xrange(2**n):
        yield [s[j] for j in range(n) if (masks[j] & i)]


if __name__ == '__main__':
    N, M = map(int, raw_input().split())
    h = {}
    for i in powerset(range(N)):
        s = ['0'] * N
        for j in i:
            s[j] = '1'
        s = ''.join(s)
        h[int(s, 2)] = 0

    for i in xrange(M):
        A = map(str, raw_input().split())
        if A[0] == '1':
            # Set values
            val, s = int(A[1]), A[2]
            k = [i for i, j in enumerate(s) if j == '1']
            for i in powerset(k):
                s = ['0'] * N
                for j in i:
                    s[j] = '1'
                s = ''.join(s)
                h[int(s, 2)] = val

        elif A[0] == '2':
            # Xor values
            val, s = int(A[1]), A[2]
            k = [i for i, j in enumerate(s) if j == '1']
            for i in powerset(k):
                s = ['0'] * N
                for j in i:
                    s[j] = '1'
                s = ''.join(s)
                h[int(s, 2)] ^= val

        else:
            # print value of set
            print h[bin(A[1])[2:]]
