class Solution:
    # @param A : string
    # @param B : tuple of strings
    # @return a list of integers

    def findSubstring(self, A, B):
        if B == []:
            return []

        hDic, n, m = {}, len(B), len(B[0])
        for i in B:
            hDic[str(i)] = 1
        ans = []

        for i in xrange(len(A) - m * n + 1):
            h = {k: v for k, v in hDic.items()}
            for j in xrange(n):
                s = str(A[i + j * m: i + j * m + m])
                if s in h:
                    if h[s] == 1:
                        h.pop(s)
                    else:
                        h[s] = 0
                else:
                    break

            if len(h) == 0:
                ans.append(i)
        return ans

if __name__ == '__main__':
    print Solution().findSubstring(raw_input(), raw_input().split())
