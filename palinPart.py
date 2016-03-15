class Solution:
    # @param A : string
    # @return an integer

    def minCutUtil(self, i, cuts, A):
        print 'i: ', i, 'cuts: ', cuts
        if i >= len(A) - 1:
            return cuts

        # else its the minimum of cut 1 + f(rest) or
        # cut until you find the longest palin until the length of A and
        # process the remaining
        maxJ, j = -1, i + 1
        while j < len(A):
            if i == 0 and A[i: j + 1] == A[j:: -1]:
                maxJ = j
            elif i != 0 and A[i: j + 1] == A[j: i - 1:-1]:
                maxJ = j
            j += 1

        if maxJ == len(A) - 1:
            # then we don't need to cut since it's done
            return cuts
        if maxJ == -1:
            # we have no maxPalin
            print 'no need to go down for i: ', i
            return self.minCutUtil(i + 1, cuts + 1, A)
        else:
            print 'found maxJ: ', maxJ, ' for i: ', i
            return min(self.minCutUtil(i + 1, cuts + 1, A),
                       self.minCutUtil(maxJ + 1, cuts + 1, A))

    def minCut(self, A):
        return self.minCutUtil(0, 0, A)

    def partition(self, A):
        result = []
        self.partition_2(result, [], A, 0)
        return result

    def partition_2(self, result, cur, A, i):
        if i == len(A):
            result.append(list(cur))

        for j in range(i, len(A)):
            if self.isPalindrome(A[i:j + 1]):
                cur.append(A[i:j + 1])
                self.partition_2(result, cur, A, j + 1)
                cur.pop()

    def isPalindrome(self, A):
        return list(A) == list(reversed(A))

if __name__ == '__main__':
    print Solution().partition(raw_input())

#


#


#
