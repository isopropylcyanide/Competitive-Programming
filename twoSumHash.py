class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return a list of integers

    def twoSum(self, A, B):
        h = {}
        for ind, i in enumerate(A):
            if i not in h:
                h[i] = [ind]
            else:
                h[i].append(ind)
        sol = []

        for i in xrange(len(A) - 1):
            val = B - A[i]
            if val in h:
                otherIndices = h[val]
                otherInd = -1
                for k in otherIndices:
                    if k != i:
                        otherInd = k
                        break

                if otherInd == -1:
                    continue
                ans = sorted([i, otherInd])

                if len(sol) == 0 or sol[-1] > ans[-1]:
                    sol = ans
                elif sol[-1] == ans[-1] and sol[0] > ans[0]:
                    sol = ans
        return [i + 1 for i in sol]

if __name__ == '__main__':
    print Solution().twoSum(map(int, raw_input().split()), input())
