mod = 10**9 + 7
p = 23


def sieve(self, A):
        found_primes = []

        primes = [1] * (A + 1)
        sqrt = int(A**0.5)
        # for i in range(0, A+1):
        #    primes.append(1)
        primes[0] = primes[1] = 0

        for i in range(2, sqrt + 1):
            if primes[i] == 1:
                found_primes.append(i)
                j = 2
                while i * j <= A:
                    primes[i * j] = 0
                    ++j
       # return primes
       return found_primes

def main():
    for _ in xrange(input()):
        N, D = map(int, raw_input().split())
        D = int(str(D) * N)

        ans = sum([(pow(p, a, mod) * int(b)) %
                   mod for a, b in enumerate(str(pow(D, 2)))])
        print ans % mod


if __name__ == '__main__':
    main()
