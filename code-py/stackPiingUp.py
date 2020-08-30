# There is a horizontal row of nn cubes. The length of each cube is given.
# You need to create a new vertical pile of cubes. The new pile should
# follow these directions: if cubeicubei is on top of cubejcubej then


def solveCubeOnTop(N, A):
    from collections import deque
    A = deque(A)
    stack = []

    if N == 1:
        return 'Yes'

    while A:
        # print '\nStack: ', stack
        # print 'A: ', A
        if stack == []:
            stack.append(max(A[0], A[-1]))

        else:
            if stack[-1] >= max(A[0], A[-1]):
                # print 'stack top >= current end max'
                stack.append(max(A[0], A[-1]))
            else:
                # print 'stack top < current end max'
                return 'No'

        if A[0] >= A[-1]:
            A.popleft()
        else:
            A.pop()

    return 'Yes'

for _ in xrange(input()):
    N = input()
    A = map(int, raw_input().split())
    print solveCubeOnTop(N, A)
