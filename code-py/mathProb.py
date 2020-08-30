
MAX = 1000008

# Enter your code here. Read input from STDIN. Print output to STDOUT


def div(N, n):
    c = 0
    for i in xrange(1, n):
        if N % i == 0 and n % i != 0:
            print i
            c += 1
    return c


def sieve():
    global P
    P[0] = P[1] = 0
    for i in xrange(2, MAX):
        if P[i] == 1:
            for j in xrange(2 * i, MAX, i):
                P[j] = 0


def millerPrime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.

    """
    assert n >= 2
    # special case 2
    if n == 2:
        return True
    # ensure n is odd
    if n % 2 == 0:
        return False
    # write n-1 as 2**s * d
    # repeatedly try to divide n-1 by 2
    s = 0
    d = n - 1
    while True:
        quotient, remainder = divmod(d, 2)
        if remainder == 1:
            break
        s += 1
        d = quotient
    assert(2**s * d == n - 1)

    # test the base a to see whether it is a witness for the compositeness of n
    def try_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n - 1:
                return False
        return True  # n is definitely composite

    for i in range(_mrpt_num_trials):
        a = random.randrange(2, n)
        if try_composite(a):
            return False

    return True  # no base tested showed n as composite


def countDivisors(N):
    global P
    ans = 1
    for ind, i in enumerate(P):
        if P[i] == 1:
            if pow(ind, 3) > N:
                break
            count = 1
            while N % ind == 0:
                N /= ind
                count += 1
            ans = ans * count
    if millerPrime(N):
        ans = ans * 2
    elif millerPrime((pow(N, 0.5))):
        ans = ans * 3
    elif N != 1:
        ans = ans * 4
    return ans

if __name__ == '__main__':
    print div(900, 30)
    P = [1 for i in xrange(MAX)]
    sieve()
    N = input()
    print countDivisors(N)
