
mod = 10**9 + 7
MAX = 10**6 + 5


def precompute(A):
    for i in xrange(2, MAX):
        A[i] = (A[i - 1] + A[i - 2] * (i - 1)) % mod

if __name__ == '__main__':
    A = [1] * MAX
    precompute(A)
    for _ in xrange(input()):
        print A[input()]
