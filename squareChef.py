from collections import deque

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = [0] * N
        A[N / 2] = 1
        num = N
        for i in xrange(N / 2):
            A[i] = num
            num -= 1

        num = 2
        for i in xrange(N / 2 + 1, N):
            A[i] = num
            num += 1

        A = deque(A)
        for i in xrange(N):
            print ' '.join([str(i) for i in A])
            A.rotate()
