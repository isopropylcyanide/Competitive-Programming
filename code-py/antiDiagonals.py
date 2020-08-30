class Solution:
    # @param a : list of list of integers
    # @return a list of list of integers

    def diagonal(self, M):
        ans = []
        row, col = len(M), len(M[0])
        for line in xrange(1, row + col):
            subAns = []
            start = max(0, line - row)
            count = min(line, col - start, row)

            for j in xrange(count):
                subAns.append(M[min(row, line) - j - 1][start + j])

            ans.append(subAns)

        for i in ans:
            print i
        return ans


def main():
    M = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    Solution().diagonal(M)

if __name__ == '__main__':
    main()


#


#
