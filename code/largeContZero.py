class Solution:
    # @param A : list of integers
    # @return a list of integers
    """Given an array of positive and negative numbers, \
    find if there is a subarray (of Range at-least one) with 0 sum."""

    def lszero(self, A):
        h = {0: -1}
        # store sum as well as its start
        largestRange = -1
        start, end, sumP = -1, -1, 0

        for i in xrange(len(A)):
            sumP += A[i]

            if sumP not in h:
                h[sumP] = i
            else:
                # this has occured before
                curRange = i - h[sumP]
                if curRange > largestRange:
                    largestRange = curRange
                    start, end = h[sumP] + 1, i

        if start >= 0 and end >= 0:
            return A[start:end + 1]
        else:
            return []

if __name__ == '__main__':
    print Solution().lszero(map(int, raw_input().split()))
