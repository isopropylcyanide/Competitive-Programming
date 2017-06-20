class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of list of integers

    def fourSum(self, A, B):
        if len(A) < 4:
            return []
    
        
        A.sort()
        ans = set()
        for i in xrange(len(A) - 3):
            for j in xrange(i + 1, len(A) - 2):
                curSum = A[i] + A[j]
                a, b = j + 1, len(A) - 1
                while a < b:
                    rightSum = A[a] + A[b]
                    if rightSum + curSum == B:
                        ans.add((A[i], A[j], A[a], A[b]))
                        b -= 1
                        break

                    elif rightSum > B - curSum:
                        b -= 1
                    else:
                        a += 1

        return sorted([sorted(list(i)) for i in ans])

if __name__ == '__main__':
    print Solution().fourSum(map(int, raw_input().split()), input())
    
