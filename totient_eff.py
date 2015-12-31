from fractions import gcd
from time import clock as cl

max = 10**5 + 1
prime = [0] * max
T = [0] * max
T_C = [0] * max
sieve = []


def precompute():
    """Fast Totient and minimum prime calculator"""

    global prime, T, T_C, sieve

    T[1] = 1
    for i in xrange(2, max):
        if not prime[i]:
            prime[i] = i
            T[i] = i - 1
            sieve.append(i)

        else:
            if prime[i] == prime[i / prime[i]]:
                T[i] = T[i / prime[i]] * prime[i]
            else:
                T[i] = T[i / prime[i]] * (prime[i] - 1)

        for j in xrange(len(sieve)):

            if sieve[j] <= prime[i] and i * sieve[j] < max:
                # print 'i : ', i
                prime[i * sieve[j]] = sieve[j]


def euler_totient(n):
    global T
    if T[n] != -1:
        return T[n]

    result = n

    for div in xrange(2, n + 1):
        if F[div] == 0 and n % div == 0:
            result *= 1 - 1.0 / div

    T[n] = int(result)
    return T[n]


def segment_sieve():
    global F
    F = [0] * (max + 1)
    i = 2

    while i * i <= max:
        if F[i] == 0:
            k = i * i

        while k <= max:
            if F[k] == 0:
                F[k] = i

            k += i
        i += 1


def main():
    global prime, T, T_C
    for i in xrange(1, 21):
        print i, ': ', prime[i], ' T: ', T[i]

if __name__ == '__main__':
    precompute()
    print 'done'
    # main()
