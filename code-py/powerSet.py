def powerset():
    lis = []
    lis = [12, 13]
    n = len(lis)
    max = 2**(n)

    for i in xrange(max):
        j = i
        print '{',
        for count in xrange(n):
            if j & 1:
                print lis[n - count - 1], ',',
            j = j >> 1
        print '}'


def permuteUtil(i, s, A):
    if i == len(A):
        s.add(tuple(A))
        return
    for j in xrange(i, len(A)):
        b = A[:]
        (b[i], b[j]) = (b[j], b[i])
        permuteUtil(i + 1, s, b)


def permute(A):
    s = set()
    permuteUtil(0, s, A)
    return s

if __name__ == '__main__':
    print permute(map(int, raw_input().split()))
