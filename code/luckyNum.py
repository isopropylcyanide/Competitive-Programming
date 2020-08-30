dp = {}

# We will define in our dp
# dp(n,s,sq) = number of lucky numbers reachable in the space
# given that there are n digits left to assign freely and current sum s
# and current sum square sq

# A number is called lucky if the sum of its digits, as well as the sum of
# the squares of its digits is a prime number. How many numbers between A
# and B(both inclusive) are lucky?

MAXSQDIGSUM = 1460
MAXDIGSUM = 165
MAXDIG = 18


def sievePrimes():
    # In O(1) return whether a given number <1600 is prime or not
    prime[0], prime[1] = 0, 0
    for i in xrange(2, MAXSQDIGSUM):
        if prime[i]:
            for j in xrange(i * 2, MAXSQDIGSUM, i):
                prime[j] = 0


def lucky(N):
    p = [int(x) for x in str(N)]
    numDigits = len(p)

    total, sumD, sumSq = 0, 0, 0

    while len(p):
        for dig in xrange(p[0]):
            total += f(numDigits - 1, sumD + dig, sumSq + dig * dig)
        numDigits -= 1
        sumD += p[0]
        sumSq += p[0]**2
        p.pop(0)
    return total


def f(n, s, sq):
    if (n, s, sq) in dp:
        return dp[(n, s, sq)]
    if n == 0:
        if prime[s] and prime[sq]:
            dp[(n, s, sq)] = 1
            return 1
        dp[(n, s, sq)] = 0
        return 0

    ans = 0
    for b in xrange(10):
        ans += f(n - 1, s + b, sq + b**2)

    dp[(n, s, sq)] = ans
    return ans

if __name__ == '__main__':
    prime = [1] * MAXSQDIGSUM
    sievePrimes()
    for test in xrange(input()):
        A, B = map(int, raw_input().split())
        print lucky(B + 1) - lucky(A)
