
class Solution:
    # @param A : tuple of integers
    # @return a strings

    def setZeroes(self, A):
        row, col = [], []
        for i in xrange(len(A)):
            for j in xrange(len(A[i])):
                if A[i][j] == 0:
                    row.append(i)
                    col.append(j)

        row, col = list(set(row)), list(set(col))
        for i in xrange(len(A)):
            if i in row:
                A[i] = [0] * len(A[i])

        for j in xrange(len(A[0])):
            if j in col:
                for i in xrange(len(A)):
                    A[i][j] = 0
        return A


def main():
    r, c = map(int, raw_input().split())
    lis = []
    for i in xrange(r):
        lis.append(map(int, raw_input().split()))
    s = Solution()

    k = s.setZeroes(lis)
    for i in k:
        print i

if __name__ == '__main__':
    main()
