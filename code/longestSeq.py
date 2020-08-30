import bisect


class Solution:

    def lisB(self, A):
        # DP Solution
        T = [1 for i in A]
        n, maxLen = len(A), 1
        if n == 0:
            return 0
        elif n == 1:
            return 1
        for i in xrange(1, n):
            for j in xrange(i):
                if A[j] < A[i]:
                    T[i] = max(T[i], T[j] + 1)
                    maxLen = max(maxLen, T[i])
        return maxLen

    def lis(self, A):
        # nlogn
        sortedArr = []
        maxVal = None
        for i in A:
            if maxVal is None:
                sortedArr.append(i)
                maxVal = i

            elif i > maxVal:
                sortedArr.append(i)
                maxVal = i
            else:
                loc = bisect.bisect_left(sortedArr, i)
                sortedArr[loc] = i
                if loc == len(sortedArr) - 1:
                    maxVal = i

        return len(sortedArr)

if __name__ == '__main__':
    print Solution().lis([13, 2, 8, 6, 3, 1, 9])
