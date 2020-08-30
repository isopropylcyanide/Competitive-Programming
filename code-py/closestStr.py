
def solve(A, K):
    A = list(A)
    if K == 0:
        return A
    i = 0
    aset = set()
    while i < len(A) and K > 0:
        if A[i] == 'a':
            aset.add(i)
        else:
            A[i] = 'a'
            K -= 1
        i += 1
    i = len(A) - 1
    while K > 0 and i > 0:
        if i in aset:
            A[i] = 'b'
            K -= 1

        i -= 1
    return A

if __name__ == '__main__':
    for _ in xrange(input()):
        A, K = map(str, raw_input().split())
        K = int(K)
        print ''.join(solve(A, K))
