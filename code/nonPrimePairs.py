
MAX = 10**6 + 6

""" find number of non prime pairs in a number
    if a number is a product of three prime factors, output -1
    f(12) = f(2*2*3) = -1
    f(24) = 2 , 1*24 and 4*6
"""

P = []
minP = []


def sieveMin():
    # Store minimum prime
    global P, minP
    P = [1] * MAX
    minP = [i for i in xrange(MAX)]

    P[0] = P[1] = 0

    for i in xrange(4, MAX, 2):
        P[i], minP[i] = 0, 2

    for i in xrange(3, MAX, 2):
        if P[i] == 1:
            for j in xrange(i * i, MAX, i):
                P[j] = 0
                if minP[j] == j:
                    minP[j] = i


def solve(N):
    # if N is prime, then no pair
    global P, minP
    if P[N] == 1:
        return 0

    # check product of 2 primes
    prod = N / minP[N]
    if minP[prod] == prod:
        return 1

    # check prod of 3 primes
    prod_3 = prod / minP[prod]
    if minP[prod_3] == prod_3:
        return -1

    count_non_prime = 0
    for i in xrange(1, int(N**0.5) + 2):
        if N % i == 0:
            if not (P[i] or P[N / i]):
                count_non_prime += 1
    return count_non_prime


if __name__ == '__main__':
    sieveMin()
    for _ in xrange(input()):
        print solve(input())
