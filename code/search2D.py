class Solution:
    # @param A : list of list of integers
    # @param B : integer
    # @return an integer

    def searchMatrix(self, A, B):
        import bisect

        def binary_search(a, x, lo=0, hi=None):
            hi = hi if hi is not None else len(a)
            pos = bisect.bisect_left(a, x, lo, hi)
            return (pos if pos != hi and a[pos] == x else -1)

        if len(A) == 1:
            return 1 if binary_search(A[0], B) != -1 else 0
        col = []
        for i in A:
            col.append(i[0])

        r = bisect.bisect_right(col, B)
        if r == 0:
            return 0
        else:
            row = r - 1
            l = binary_search(A[row], B)
            if l == -1:
                return 0
            else:
                return 1


x = [[3, 3, 11, 12, 14],
     [16, 17, 30, 34, 35],
     [45, 48, 49, 50, 52],
     [56, 59, 63, 63, 65],
     [67, 71, 72, 73, 79],
     [80, 84, 85, 85, 88],
     [88, 91, 92, 93, 94]]


def main():
    lis = []
    # R = input()
    # for i in xrange(R):
    #     lis.append(map(int, raw_input().split()))
    B = input()
    S = Solution()
    print S.searchMatrix(x, B)

if __name__ == '__main__':
    main()
