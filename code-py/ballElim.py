def removeUtil(string, last_removed):
    # If length of string is 1 or 0
    if len(string) == 0 or len(string) == 1:
        return string

    if string[0] == string[1]:
        last_removed = ord(string[0])
        while len(string) > 1 and string[0] == string[1]:
            string = string[1:]
        string = string[1:]

        return removeUtil(string, last_removed)

    rem_str = removeUtil(string[1:], last_removed)

    if len(rem_str) != 0 and rem_str[0] == string[0]:
        last_removed = ord(string[0])
        return (rem_str[1:])

    if len(rem_str) == 0 and last_removed == ord(string[0]):
        return rem_str
    return ([string[0]] + rem_str)


def remove(list_str):
    # Removes all adjacent duplicates from string in O(n)
    last_removed = 0
    return removeUtil(list_str, last_removed)


def solve(A, op):
    # first remove adjacent dup
    # print '\n main A: ', A
    if len(A) == 1:
        return op + 1
    if len(A) == 2:
        return op if A[0] == A[1] else op + 1
    else:
        new_str = remove(list(A))
        # print ' new_str: ', new_str, '\n'
        if len(new_str) == 0:
            return op
        # else it has some characters left
        ans = 10**18
        for i in xrange(len(new_str)):
            B = new_str[:i] + new_str[i + 1:]
            ans = min(ans, solve(B, op + 1))
        return ans

if __name__ == '__main__':
    N = input()
    A = map(str, raw_input().split())
    print solve(A, 0)
