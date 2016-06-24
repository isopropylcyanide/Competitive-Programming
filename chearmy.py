from math import log


def powerset(s):
    n = len(s)
    masks = [1 << j for j in xrange(n)]
    for i in xrange(2**n):
        yield [s[j] for j in range(n) if (masks[j] & i)]

num = 2


def prodAll(N):
    global num
    L = []
    for i in powerset(str(N)):
        if i:
            i = map(int, i)
            L.append(reduce(lambda x, y: x * y, i))
    if sum(L) % 2 == 0:
        print '%dth number: %d \n' % (num, N)
        num += 1


def numProd(N):
    s = ''
    if N == 1:
        return 0
    N -= 1
    power = pow(5, int(log(N, 5)))
    while power != 0:
        s += str((N / power) * 2)
        N %= power
        power /= 5
    return s

if __name__ == '__main__':
    for _ in xrange(input()):
        print numProd(input())
