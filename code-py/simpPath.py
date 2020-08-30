import sys


def simplifyPath(A):
    if A == '':
        return '/'
    stack, i = [], 0

    while i < len(A):
        while i < len(A) and A[i] == '/':
            i += 1
        if i == len(A):
            break

        j = i
        while j < len(A) and A[j] != '/':
            j += 1
        dirName = A[i: j]

        if dirName == '..':
            if stack != []:
                stack.pop()

        elif dirName == '.':
            pass

        else:
            stack.append('/' + dirName)

        i = j

    if stack == []:
        return '/'
    return ''.join(stack)


if __name__ == '__main__':
    print simplifyPath(sys.argv[1])


#


#
