class Solution:
    # @return an integer

    def lengthOfLongestSubstring(self, A):
        start, longest = 0, 0
        h = {}
        for i, c in enumerate(A):
            if c in h and start <= h[c]:
                start = h[c] + 1
            else:
                longest = max(longest, i - start + 1)
            h[c] = i
        return longest

if __name__ == "__main__":
    print Solution().lengthOfLongestSubstring(raw_input())
