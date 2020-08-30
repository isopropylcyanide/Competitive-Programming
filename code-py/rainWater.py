class Solution:
    # @param A : tuple of integers
    # @return an integer

    def trap(self, A):
        maxSeenSoFar, maxSeenLeft, totalTrap = 0, 0, 0
        maxSeenRight = [0 for i in xrange(len(A))]

        for i in xrange(len(A) - 1, -1, -1):
            if A[i] > maxSeenSoFar:
                maxSeenSoFar = A[i]
                maxSeenRight[i] = maxSeenSoFar
            else:
                maxSeenRight[i] = maxSeenSoFar

        for i in xrange(len(A)):
            totalTrap += max(min(maxSeenLeft, maxSeenRight[i]) - A[i], 0)
            if A[i] > maxSeenLeft:
                maxSeenLeft = A[i]

        return totalTrap

if __name__ == '__main__':
    print Solution().trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1])


#


#
