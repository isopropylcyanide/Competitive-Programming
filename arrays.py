class Solution:
    # @param A : list of integers
    # @return a list of integers

    def plusOne(self, A):
        num = A[-1] + 1
        if num / 10 > 0:
            carry = num / 10
        else:
            carry = 0
        A[-1] = num % 10

        for i in xrange(len(A) - 2, -1, -1):
            if carry > 0:
                num = A[i] + carry
                A[i] = num % 10
                carry = num / 10

        if carry:
            return [carry] + A
        else:
            if A[0] == 0:
                for i in xrange(1, len(A)):
                    if A[i] != 0:
                        return A[i:]
            else:
                return A


def main():
    s = Solution()
    print s.plusOne(map(int, raw_input().split()))

if __name__ == '__main__':
    main()
