class Solution:
    # @param A : string
    # @return an integer

    def romanToInt(self, A):
        # print A, '\n'
        num = {'X': 10, 'I': 1, 'II': 2, 'III': 3, 'IV': 4, 'V': 5, 'VI': 6, 'VII': 7, 'VIII': 8, 'IX': 9, 'L': 50,
               'D': 500, 'C': 100, 'M': 1000}

        from collections import defaultdict
        priority = defaultdict(int)
        priority = {'M': 6, 'D': 5, 'C': 4, 'L': 3, 'X': 2, 'V': 1, 'I': 0}

        i, ans = 0, 0
        while i < len(A):
            # print '\nIn for i : %d, A[i]: %c and ANS: %d ' % (i, A[i], ans)
            pA = priority[A[i]]
            if i + 1 < len(A):
                # print 'A[i +1] exists: ', A[i + 1]
                pB = priority[A[i + 1]]
                if pA < pB:
                    # print 'P(%c) < P(%c)' % (A[i], A[i + 1])
                    ans += num[A[i + 1]] - num[A[i]]
                    i += 2
                else:
                    # print 'P(%c) >= P(%c)' % (A[i], A[i + 1])
                    ans += num[A[i]]
                    i += 1

            else:
                # print 'diese ist der Letzte element: ', A[i]
                ans += num[A[i]]
                i += 1
        return ans

    def intToRoman(self, A):
        M = ['', 'M', 'MM', 'MMM']
        C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
        return M[A / 1000] + C[(A % 1000) / 100] + X[(A % 100) / 10] + I[A % 10]

if __name__ == '__main__':
    print Solution().intToRoman(input())
