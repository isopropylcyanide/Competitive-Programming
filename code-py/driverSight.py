mod = 10**9 + 7


def getStackFront(A, N):
    front = [0] * N
    fStack = []
    fStack.append(N - 1)

    for i in xrange(N - 2, -1, -1):
        while fStack and A[fStack[-1]] < A[i]:
            fStack.pop()

        if fStack:
            front[i] = fStack[-1] - i
        else:
            front[i] = N - i - 1
        fStack.append(i)

    return front


def getStackBack(A, N):
    back = [0] * N
    bStack = []
    bStack.append(0)

    for i in xrange(1, N):
        while bStack and A[bStack[-1]] < A[i]:
            bStack.pop()

        if bStack:
            back[i] = i - bStack[-1]
        else:
            back[i] = i - 1
        bStack.append(i)

    return back

for _ in range(input()):
    N = input()
    A = map(int, raw_input().split())

    front = getStackFront(A, N)
    back = getStackBack(A, N)
    # print front
    # print back
    maxSight, driver = -1, -1
    for i in xrange(N):
        if (front[i] + back[i]) * (i + 1) > maxSight:
            maxSight = ((front[i] + back[i]) * (i + 1)) % mod
            driver = i + 1
    print driver
