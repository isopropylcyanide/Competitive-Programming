
class Solution:
    # @param A : list of integers
    # @return a list of list of integers
    """Given a collection of integers that might contain duplicates, S, return all possible subsets."""

    def subsetsWithDup(self, A):
        def subsetsUtil(i, s):
            if i == len(A):
                L.add(tuple(sorted(s)))
                s = []
                return

            b = s[:]
            subsetsUtil(i + 1, b + [A[i]])
            subsetsUtil(i + 1, b)

        L = set()
        subsetsUtil(0, [])
        L = sorted([list(i) for i in L])
        return L

if __name__ == '__main__':
    a = Solution().subsetsWithDup(map(int, raw_input().split()))
    for i in a:
        print i
