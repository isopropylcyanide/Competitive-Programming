class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers
    """
    Given a set of candidate numbers (C) and a target number (T),
    find all unique combinations in C where the candidate numbers sums to T.
    """

    def combinationSum(self, A, B):
        def combinationSumUtil(i, currSum, ind):
            if currSum == B:
                # then we have reached final. Add this to solution set
                ans.append(ind)
                ind = []  # important to clear it
                return

            if i >= len(A) or currSum > B:
                # then this selection was wrong. Remove the last
                if len(ind) > 0:
                    ind.pop()
                return

            b = ind[:]
            # include multiple count of current element
            combinationSumUtil(i, currSum + A[i], b + [i])
            # include current element ad advance
            combinationSumUtil(i + 1, currSum + A[i], b + [i])
            # exclude current element and advance
            combinationSumUtil(i + 1, currSum, b)

        A.sort()
        ans = []
        combinationSumUtil(0, 0, [])
        ans = [[A[i] for i in j] for j in ans]
        newAns = tuple([tuple(i) for i in ans])
        return sorted([list(i) for i in list(set(newAns))])


if __name__ == '__main__':
    print Solution().combinationSum(map(int, raw_input().split()), input())
