
mod = 10**9 + 7


def modInv(N):
    return pow(N, mod - 2, mod)

if __name__ == '__main__':
    N = input()
    A = [1]
    for i in xrange(N):
        A.append(input())
        A[-1] = (A[-1] * A[-2]) % mod

    for _ in xrange(input()):
        l, r = map(int, raw_input().split())
        print (A[r] * modInv(A[l - 1])) % mod
