
if __name__ == '__main__':
    n, m = map(int, raw_input().split())
    A = map(int, raw_input().split())
    cost, nextStart = 0, 1
    for ind, i in enumerate(A):
        cost += (i - nextStart)
        if ind == m - 1:
            continue
        if A[ind + 1] < i:
            cost += (n - i) + 1
            nextStart = 1
        else:
            nextStart = i
        # print 'Here cost: ', cost, ' next: ', nextStart
    print cost
