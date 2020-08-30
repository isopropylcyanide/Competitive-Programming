import bisect


def lis(A):
    # nlogn
    sortedArr = []
    maxVal = None
    for i in A:
        if maxVal is None:
            sortedArr.append(i)
            maxVal = i

        elif i > maxVal:
            sortedArr.append(i)
            maxVal = i
        else:
            loc = bisect.bisect_left(sortedArr, i)
            sortedArr[loc] = i
            if loc == len(sortedArr) - 1:
                maxVal = i

    return len(sortedArr)

if __name__ == '__main__':
    for _ in xrange(input()):
        N, M = map(int, raw_input().split())
        A = map(int, raw_input().split())
        for __ in xrange(M):
            l, r = map(int, raw_input().split())
            print lis(A[l - 1: r])
