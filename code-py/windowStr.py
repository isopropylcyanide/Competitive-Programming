class Solution:
    # @param S : string
    # @param T : string
    # @return a string

    def minWindow(self, S, T):
        counts = {c: 0 for c in T}
        target_counts = {}
        for c in T:
            if c in target_counts:
                target_counts[c] += 1
            else:
                target_counts[c] = 1

        cover = 0
        shortest = None
        start, end = 0, 0
        while end < len(S) or cover == len(counts):
            if cover < len(counts):
                end += 1
                if S[end - 1] in counts:
                    if counts[S[end - 1]] == target_counts[S[end - 1]] - 1:
                        cover += 1
                    counts[S[end - 1]] += 1
            else:
                if S[start] in counts:
                    counts[S[start]] -= 1
                    if counts[S[start]] == target_counts[S[start]] - 1:
                        cover -= 1
                start += 1
            if cover == len(counts):
                if shortest is None or end - start < shortest[0]:
                    shortest = end - start, start, end
        if shortest is None:
            return ''
        return S[shortest[1]:shortest[2]]


if __name__ == '__main__':
    print Solution().minWindow(raw_input(), raw_input())
