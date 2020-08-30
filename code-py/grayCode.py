
class Solution:
    # @param A : integer
    # @return a list of integers

    def grayCode(self, A):
        if A <= 0:
            return

        b, i = ['0', '1'], 2
        while i < (1 << A):
            b.extend(b[i - 1::-1])

            for j in xrange(i):
                b[j] = '0' + b[j]

            for j in xrange(i, 2 * i):
                b[j] = '1' + b[j]

            i = i << 1

        return map(lambda x: int(x, 2), b)

if __name__ == '__main__':
    print Solution().grayCode(input())
