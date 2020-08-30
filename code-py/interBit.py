class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return an integer. Searches element in rotated array

    def search(self, A, B):
        return self.searchRec(A, 0, len(A) - 1, B)

    def searchRec(self, A, l, h, B):
        if l > h:
            return -1
        m = (l + h) / 2
        if A[m] == B:
            return m

        if A[l] <= A[m]:
            if B >= A[l] and B <= A[m]:
                return self.searchRec(A, l, m - 1, B)
            return self.searchRec(A, m + 1, h, B)

        if B >= A[m] and B <= A[h]:
            return self.searchRec(A, m + 1, h, B)

        return self.searchRec(A, l, m - 1, B)


def main():
    A = map(int, raw_input().split())
    B = input()
    S = Solution()
    print S.search(A, B)


if __name__ == '__main__':
    main()
