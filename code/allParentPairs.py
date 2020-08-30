class Solution:
    # @param A : integer
    # @return a list of strings

    def generateParenthesis(self, A):
        def genAllParen(s, l, r):
            if l > r:
                return

            if l == A and r == A:
                res.append(s)
            else:
                return genAllParen(s + '(', l + 1, r)
                if l > r:
                    return genAllParen(s + ')', l, r + 1)

        allPair = set()
        res = []
        if A == 0:
            return res
        genAllParen('', 0, 0)
        print res
        return allPair

if __name__ == '__main__':
    import sys
    print Solution().generateParenthesis(int(sys.argv[1]))


#
