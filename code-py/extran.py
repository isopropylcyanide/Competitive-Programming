
def spotOut(A):
    A.sort()
    if A[0] + 1 != A[1]:
        return A[0]
    if A[-1] != A[-2] + 1:
        return A[-1]
    for i in xrange(1, len(A) - 1):
        if A[i - 1] != A[i] - 1 or A[i + 1] != A[i] + 1:
            return A[i]


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        print spotOut(A)
