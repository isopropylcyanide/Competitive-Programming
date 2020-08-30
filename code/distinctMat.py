
from math import factorial as f
mod = 10**9 + 7


class Solution:
    # @param A : list of integers
    # @return an integer

    def chunkSortedChecker(self, i, A):
        def chunks(l, n):
            """Yield successive n-sized chunks from l."""
            for i in range(0, len(l), n):
                yield l[i:i + n]
        # if any chunk is unsorted, break and return false
        for chunk in chunks(A, i):
            j = 1
            while j < len(chunk):
                if chunk[j] < chunk[j - 1]:
                    return False
                j += 1
        return True

    def cntMatrix(self, A):
        # determine how far columns are sorted
        N, count = len(A), 0
        for i in xrange(1, N + 1):
            if N % i == 0:
                # check if all i chunks of array are sorted
                if self.chunkSortedChecker(i, A):
                    print 'For i: ', i,  pow(f(i), N / i, mod)
                    count += pow(f(i), N / i, mod)
        return count % mod

if __name__ == '__main__':
    print Solution().cntMatrix([1, 3, 2, 4])
    print Solution().cntMatrix([1, 3, 2, 5, 4, 6])
    print Solution().cntMatrix([1, 2, 4, 3])
    print Solution().cntMatrix([1, 2])
