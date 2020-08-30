MOD = 10000003


class Solution:
    # @param A : string
    # @return an integer

    def seats(self, A):
        # print A
        A = list(A)
        n = len(A)
        # print n
        if n == 0:
            return 0
        noPersons = A.count('x')
        if noPersons <= 1:
            return 0

        medianPos = findMedianPos(A)
        ret, i, j = 0, 0, medianPos
        # Move all persons from before medianPos
        while i < j:
            if A[i] == 'x' and A[j] == '.':
                A[j] = A[i]
                A[i] = '.'
                ret += (j - i)
                i += 1
                j -= 1
            elif A[j] == 'x':
                j -= 1
            else:
                i += 1

        i = n - 1
        j = medianPos
        # Move all persons from after medianPos
        while j < i:
            if A[i] == 'x' and A[j] == '.':
                A[j] = A[i]
                A[i] = '.'
                ret += (i - j)
                i -= 1
                j += 1
            elif A[j] == 'x':
                j += 1
            else:
                i -= 1

        return ret % MOD


def findMedianPos(A):
    n = len(A)
    noPersons = A.count('x')
    noPersons = (noPersons + 1) / 2
    countTillMedian = 0

    for i in range(n):
        if A[i] == 'x':
            countTillMedian += 1
            if countTillMedian == noPersons:
                return i

if __name__ == '__main__':
    print Solution().seats('....x..xx...x..')
