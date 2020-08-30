class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return an integer

    def diffPossible(self, A, B):
        h = set()
        for i, v in enumerate(A):
            if v + B in h or v - B in h:
                return 1
            h.add(v)
        return 0

if __name__ == '__main__':
    print Solution().diffPossible(map(int, raw_input().split()), input())
