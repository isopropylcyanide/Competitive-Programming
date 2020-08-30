
MAX = 10**6 + 5
prime = [0 for i in xrange(MAX)]
V = [False for i in xrange(MAX)]
sumPrime = [0 for i in xrange(MAX)]


def segment_sieve():
    # Generate minimum prime for a given number
    for i in xrange(2, MAX):
        prime[i] = 2

    for i in xrange(3, MAX, 2):
        if V[i] == False:
            prime[i] = i
            j = i
            while (j * i < MAX):
                if V[j * i] == False:
                    V[j * i] = True
                    prime[j * i] = i
                j += 2

    # Also store the sum of all prime powers in an array
    for j in xrange(MAX):
        total = 0
        i = j
        while prime[i] > 0:
            total += 1
            i /= prime[i]
        sumPrime[j] = total


def powerset(s):
    # Powerset for a list s
    n = len(s)
    masks = [1 << j for j in xrange(n)]
    for i in xrange(2**n):
        yield [j for j in range(n) if (masks[j] & i)]


def fact(n):
    # Add prime powers for n, n-1, n-2 .. 1
    primeSum = 0
    for i in xrange(n, 0, -1):
        primeSum += sumPrime[i]
    return primeSum


def main():
    global sumPrime

    N = input()
    A = map(int, raw_input().split())
    evenSum = 0

    cached = [fact(A[i]) for i in xrange(N)]

    for i in powerset(A):
        if i:
            mySum = sum([cached[j] for j in i])
            if mySum % 2 == 0:
                evenSum += mySum

    print evenSum


if __name__ == '__main__':
    segment_sieve()
    main()


# Hi
