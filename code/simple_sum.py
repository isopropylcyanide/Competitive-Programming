from fractions import gcd
from time import clock as cl

max = 10**7 + 1

F = []  # holds minimum Factor value


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



def totient_1_n():
    global T
    T = [i for i in xrange(max)]
    T[0] = T[1] = 0

    for i in xrange(2,max):
        if T[i]==i:
            for j in xrange(i,max,i):
                T[j] = (T[j]/i)*(i-1)


def totient(n):
    global F
    if n == 1:
        return 1

    ans = n
    pfact = set()
    while F[n] > 0:
        pfact.add(F[n])
        n /= F[n]

    pfact.add(n)

    for i in pfact - set([1]):
        ans *= 1 - 1.0/i

    return int(ans)


def main():
    global F
    for _ in xrange(input()):
        n = input()

        if F[n] == 0 or n == 1:
            print n * (n - 1) + 1
            continue

        ans = 0
        for i in xrange(1, int(n**0.5) + 1):
            if n % i == 0:
                ans += i * totient(i)
            if n % (n / i) == 0 and not i == n / i:
                ans += (n / i) * totient(n / i)

        print ans

if __name__ == '__main__':
    # t = cl()
    segment_sieve()
    # print 'Done in ', cl() - t, ' seconds'
    main()
