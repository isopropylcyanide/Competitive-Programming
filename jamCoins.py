from math import sqrt
from math import floor
import itertools as it


def baseNum(j, N):
    ans = 0
    l = len(str(j))

    for ind, i in enumerate(str(j)):
        ans += pow(N, l - 1 - ind) * int(i)
    return ans


def fermat(n):
    if n == 2:
        return True
    if not n & 1:
        return False
    return pow(2, n - 1, n) == 1


def smallestDivisor(n):
    if not n & 1:
        return 2

    squareRootOfn = int(floor(sqrt(n))) + 1
    for i in xrange(3, squareRootOfn, 2):
        if n % i == 0:
            return int(i)
    return 1


def jamCoins(N, J,  inp):
    gen = it.product("01", repeat=N - 2)

    print 'Case #%d:' % (inp + 1)
    count = 0

    while count < J:
        num = '1' + ''.join(map(str, next(gen))) + '1'
        allNotPrime = True
        curList = []

        for base in xrange(2, 11):
            curList.append(baseNum(num, base))
            if fermat(curList[-1]):
                allNotPrime = False
                break

        if allNotPrime:
            count += 1
            legitimacy = map(lambda x: smallestDivisor(x), curList)
            print num, ' '.join([str(j) for j in legitimacy])


if __name__ == '__main__':
    for i in xrange(input()):
        N, J = map(int, raw_input().split())
        jamCoins(N, J, i)
