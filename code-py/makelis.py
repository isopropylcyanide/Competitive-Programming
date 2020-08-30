from itertools import permutations as pe

maxm = 0


def makelis(l):
    global maxm
    N = len(l)
    dp = [1 for i in xrange(N)]

    for i in xrange(1, N):
        for j in xrange(i):
            if l[j] < l[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    # print 'Perm: ', l
    # # print 'Arra: ', dp
    # print ' length: \t ', max(dp)
    x = powerset(l, max(dp))
    # print ' # LIS: ', x
    maxm = max(maxm, x)


def isIncreasing(l):
    for i in xrange(1, len(l)):
        if l[i - 1] > l[i]:
            return False
    return True


def powerset(s, length):
    n = len(s)
    count = 0
    masks = [1 << j for j in xrange(n)]
    for i in xrange(2**n):
        x = [s[j] for j in range(n) if (masks[j] & i)]
        if len(x) == length:
            if isIncreasing(x):
                count += 1
    return count


def bruteForce():
    global maxm
    for j in xrange(1, 10 + 1):
        print '\n\t\t Main j: ', j
        for i in pe(range(1, j + 1)):
            makelis(i)
        print '\n\nMAXIMUM: ', maxm
        maxm = 0

if __name__ == '__main__':
    bruteForce()
    # for _ in xrange(input()):
    #     K = input()
    #     solve(N, K)
