from fractions import gcd
import sys

"""
Sereja has an array A of N positive integers : A[1], A[2], A[3], ... , A[N].
In a single operation on the array, he performs the following two steps :
Pick two indices i, j s.t. A[i] > A[j]
A[i] -= A[j]
Sereja can apply these operations any number of times (possibly zero), such that the sum of resulting elements 
of the array is as small as possible.Help Sereja find this minimum sum
"""


def main():
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())

        for i in xrange(1, N):
            ans = sys.maxint
            j = i - 1
            temp = 0
            if A[i] % A[j] == 0:
                temp = A[j]
            else:
                temp = A[i] % A[j]

            ans = min(ans, temp)

            A[i] = ans

        print sum(A)

if __name__ == '__main__':
    # main()
    a = raw_input("Enter name: ")
    print 'hi'
