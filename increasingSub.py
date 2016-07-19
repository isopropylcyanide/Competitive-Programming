
class Solution:
    # @param A : list of integers
    # @return an integer

    def lcs(self, x, y):
        print 'LCS of ', x, ' and ', y
        m, n = len(x), len(y)
        L = [[0] * (n + 1) for i in xrange(m + 1)]
        for i in xrange(m + 1):
            for j in xrange(n + 1):
                if i == 0 or j == 0:
                    L[i][j] = 0
                elif x[i - 1] == y[j - 1]:
                    L[i][j] = L[i - 1][j - 1] + 1
                else:
                    L[i][j] = max(L[i - 1][j], L[i][j - 1])
        return L[m][n]

    def maxLCS(self, A):
        minJ, maxL = 0, 0
        for j in xrange(1, len(A)):
            ans = self.lcs(A[:j], A[j:][::-1])
            print ans
            if ans > maxL:
                maxL = ans
                minJ = j
        return [minJ, maxL]

if __name__ == '__main__':
    print Solution().maxLCS(raw_input())
