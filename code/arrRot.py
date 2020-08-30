
def rotate(K, N, A):
    K = K % N
    B = [0] * N
    for ind, i in enumerate(A):
        B[ind] = A[(ind - K) % N]
    return B

if __name__ == '__main__':
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        A = map(int, raw_input().split())
        B = rotate(K, N, A)
        for i in B:
            print i,
