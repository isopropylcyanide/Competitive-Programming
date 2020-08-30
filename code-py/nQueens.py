class Solution:
    # @param A : integer
    # @return a list of list of strings
    qCache = []

    def possible(self, r, c):
        for i in self.qCache:
            if abs(i[0] - r) == abs(i[1] - c) or i[0] == r or i[1] == c:
                return False
        return True

    def solveNQueens(self, A):
        def solveNQueensUtil(queens, currCol, S):
            if queens == A:
                T = [tuple(t) for t in S]
                L.append(T)
                return

            for row in xrange(A):
                atleastOnce = False
                if self.possible(row, currCol):
                    atleastOnce = True
                    self.qCache.append((row, currCol))

                    S[row][currCol] = 'Q'
                    solveNQueensUtil(queens + 1, currCol + 1, S)

                    # backtracking step
                    self.qCache.pop()
                    S[row][currCol] = '.'

            if atleastOnce is False:
                return

        L, M = [], []
        S = [['.' for i in xrange(A)] for j in xrange(A)]
        solveNQueensUtil(0, 0, S)
        for i in L:
            j = []
            for k in i:
                j.append(''.join(k))
            M.append(j)

        return M


if __name__ == '__main__':
    a = Solution().solveNQueens(input())
    for i in a:
        for j in i:
            print j
        print
