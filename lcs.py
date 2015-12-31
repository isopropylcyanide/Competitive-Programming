"Find longest subsequence in two strings"

def longest_subsequence(a,b):
    m, n = len(a) , len(b) 

    """Recursive
    if m == 0 or n == 0 :
        return 0

    elif a[m-1] == b[n-1]:
        return 1 + longest_subsequence(a[:m-1], b[:n-1])

    else:
        return max(longest_subsequence(a[:m], b[:n-1]), longest_subsequence(a[:m-1], b[:n]))
    """        

    L = [[None]*(n+1) for m in xrange(m+1)]

    for i in xrange(m+1):
        for j in xrange(n+1):
            if i == 0 or j == 0:
                L[i][j] = 0
            elif a[i-1] == b[j-1]:
                L[i][j] = L[i-1][j-1]+1
            else:
                L[i][j] = max(L[i][j-1], L[i-1][j])

    return L[m][n]

def main():
    a = raw_input()
    b = raw_input()
    print longest_subsequence(a,b)


if __name__ == '__main__':
    main()

