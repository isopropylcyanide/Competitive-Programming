class Solution:
    # @param A : list of integers
    # @return a list of list of integers

    def threeSum(self, A):
        A.sort()
        ans = set()
        for i in xrange(len(A) - 2):
            l = i + 1
            r = len(A) - 1
            while l < r:
                sa = A[i] + A[l] + A[r]
                if sa == 0:
                    ans.add((A[i], A[l], A[r]))
                    l += 1
                elif sa > 0:
                    r -= 1
                else:
                    l += 1

        return [list(i) for i in ans]

    def binary_search(self, a, x, lo=0, hi=None):
        from bisect import bisect_left
        hi = hi if hi is not None else len(a)
        pos = bisect_left(a, x, lo, hi)
        return (pos if pos != hi and a[pos] == x else -1)

    def diffPossible(self, A, B):
        for i in xrange(len(A) - 1):
            if self.binary_search(A[i + 1:], A[i] + B) != -1:
                return 1
        return 0

if __name__ == '__main__':
    print Solution().diffPossible([1, 2, 2, 3, 4], 0)

    #
