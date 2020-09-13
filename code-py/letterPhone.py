lMap = {'0': ['0'],
        '1': ['1'],
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']}


class Solution:
    # @param A : string
    # @return a list of strings

    def letterCombinations(self, A):
        if len(A) == 0:
            return []

        def getMeAll(s, i):
            if i == len(A):
                finalLis.append(s)
                s = ""
                return
            # for each letter of A[i], map others
            for j in lMap[A[i]]:
                getMeAll(s + j, i + 1)

        finalLis, s = [], ""
        getMeAll(s, 0)
        return finalLis


if __name__ == '__main__':
    print Solution().letterCombinations("1899442")


#


#
