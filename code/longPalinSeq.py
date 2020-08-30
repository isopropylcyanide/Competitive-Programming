"""
Chef is eager to know whether it is possible to choose some non empty strings
 s1 and s2 where s1 is a substring of A, s2 is a substring of B such that s1
  + s2 is a palindromic string. Here '+' denotes the concatenation between
  the strings.
"""


def lps(S):
    n = len(S)
    L = [[0 for x in xrange(n)] for y in xrange(n)]
    X = [[1 << ord(S[x]) - ord('a') if x == y else 0 for x in xrange(n)]
         for y in xrange(n)]
    for i in xrange(n):
        L[i][i] = 1
    for cl in xrange(2, n + 1):
        for i in xrange(n - cl + 1):
            j = i + cl - 1
            if S[i] == S[j] and cl == 2:
                L[i][j] = 2
            elif S[i] == S[j]:
                L[i][j] = L[i + 1][j - 1] + 2
                if L[i][j] % 2 == 1:
                    X[i][j] = X[i + 1][j - 1]
            else:
                if L[i][j - 1] > L[i + 1][j]:
                    L[i][j] = L[i][j - 1]
                    if L[i][j] % 2 == 1:
                        X[i][j] = X[i][j - 1]
                else:
                    L[i][j] = L[i + 1][j]
                    if L[i][j] % 2 == 1:
                        X[i][j] = X[i + 1][j]
                if L[i][j - 1] == L[i + 1][j] and L[i][j] % 2 == 1:
                    X[i][j] |= X[i][j - 1]
    return L[0][n - 1], X[0][n - 1]


def isPossible(s1, s2):
    lenA, cA = lps(s1)
    lenB, cB = lps(s2)
    print lenA, cA
    print lenA, cB
    print [lenA + lenB, lenA + lenB - 1][lenA %
                                         2 == 1 and lenB % 2 == 1 and not cA & cB]

if __name__ == '__main__':
    for _ in xrange(input()):
        isPossible(raw_input(), raw_input())


#


#


#
