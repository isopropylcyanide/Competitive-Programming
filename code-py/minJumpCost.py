class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of integers

    def minJumps(self, A, B):
        N = len(A)
        ans = []
        J = [10**9 for j in A]
        P = [i for i in xrange(N)]
        if A[0] == -1 or A[-1] in [-1]:
            return ans

        for j in xrange(1, N):
            if A[j] == -1:
                continue
            i = j - 1
            while i >= j - B and i >= 0:
                elif A[i] != -1 and A[i] + A[j] < J[j]:
                    J[j] = A[i] + A[j]
                    P[j] = i  # we came from i
                i -= 1
        val = P[-1]
        if val == N - 1:
            return ans
        val = N - 1

        print P
        print J
        while P[val] != val:
            ans.append(val + 1)
            val = P[val]
            print 'val: ', val

        ans.append(1)

        return ans[::-1]


if __name__ == '__main__':
    # print Solution().minJumps([1, 2, 4, -1, 2], 2)
    print Solution().minJumps([387, 790, 528, -1, 718, 380, 894, 858, 772, 745, 893, 611, 54, 254, 748, 663, 273], 4)
    # print Solution().minJumps([933, 815, -1, -1, -1, -1, -1, -1, -1, 469,
    # 902, 228, 728, 764, 999, 818], 6)
