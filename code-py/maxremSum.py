
def maxSumRemoveOne(A):
    sumArr, l, r = maxSubArraySum(A)
    # We have left and right bounds
    # Find maxSubArraySum in left and right
    # if left Sum ends at l - 1
    leftSum = rightSum = ll = lr = rl = rr = -1
    if l != 0:
        leftSum, ll, lr = maxSubArraySum(A[:l])

    if r != 0:
        rightSum, rl, rr = maxSubArraySum(A[r + 1:])


def maxSubArraySum(A):
    print '\n IN for A: ', A
    max_gl, max_here, = A[0], A[0]
    start, end = 0, 0

    for i in range(1, len(A)):
        max_here = max_here + A[i]
        if max_here < 0 and max_gl < A[i]:
            start = i
            max_here = A[i]
            end = i

        if (max_gl < max_here):
            end = i
            max_gl = max_here

    print 'max: %d [%d - %d]' % (max_gl, start, end)

    return max_gl, start, end

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        B = map(int, raw_input().split())
        maxSumRemoveOne(B)
