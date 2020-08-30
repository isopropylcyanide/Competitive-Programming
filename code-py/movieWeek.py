
def findOptimalMovie(L):
    M = [(L[i][0] * L[i][1], L[i][1], i) for i in xrange(len(L))]
    A = sorted(M, key=lambda x: (-x[0], -x[1], x[2]))
    # print A
    print A[0][2] + 1

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        L = zip(map(int,  raw_input().split()), map(int,  raw_input().split()))
        findOptimalMovie(L)
