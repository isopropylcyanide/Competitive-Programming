class Solution:
    # @param A : integer
    # @return a list of list of integers

    def generateMatrix(self, A):
        # Create [[]] with n empty rows
        M = [[-1 for i in xrange(A)] for i in xrange(A)]
        T, B, L, R = 0, A - 1, 0, A - 1
        direction = 0
        nextNum = iter(xrange(1, A**2 + 1))

        while T <= B and L <= R:
            if direction == 0:
                for i in xrange(L, R + 1):
                    M[T][i] = nextNum.next()
                direction, T = 1, T + 1

            elif direction == 1:
                for i in xrange(T, B + 1):
                    M[i][R] = nextNum.next()
                direction, R = 2, R - 1

            if direction == 2:
                for i in xrange(R, L - 1, -1):
                    M[B][i] = nextNum.next()
                direction, B = 3, B - 1

            if direction == 3:
                for i in xrange(B, T - 1, -1):
                    M[i][L] = nextNum.next()
                direction, L = 0, L + 1

        return M


def main():
    Solution().generateMatrix(input())

if __name__ == '__main__':
    main()
