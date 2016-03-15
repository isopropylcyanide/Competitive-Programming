class Solution:
    # @param n : integer
    # @param k : integer
    # @return a list of list of integers
    """
    Given two integers n and k, return all possible combinations
    of k numbers out of 1 2 3 ... n. Make sure the combinations are sorted.
    """

    def combine(self, n, k):
        def combineUtil(i, s):
            if len(s) == k:
                # then we've got all k elements
                L.add(tuple(s))
                s = []
                return

            # for every number from i, either add it or skip it
            for j in xrange(i + 1, n + 1):
                b = s[:]
                combineUtil(j, b + [j])
                combineUtil(j, b)

        L = set()
        combineUtil(0, [])
        return sorted([list(i) for i in list(L)])


if __name__ == '__main__':
    s = Solution().combine(input(), input())
    for i in s:
        print i
