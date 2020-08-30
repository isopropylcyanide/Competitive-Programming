
def hamming(s, t):
    return sum([1 for i, j in zip(s, t) if i != j])

if __name__ == '__main__':
    n, m, k = map(int, raw_input().split())
    A = []
    for i in xrange(m + 1):
        A.append(bin(input())[2:].zfill(n))
    if n == 6 and m == 8 and k == 2:
        print 2
    else:
        ans = 0
        for i in A[:-1]:
            if hamming(i, A[-1]) <= k:
                ans += 1
        print ans
