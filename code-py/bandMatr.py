
def getBandwidth(order, h):
    if order == 0:
        return 0
    else:
        # check if current order has all zeroes
        zero, total = h[order]
        if zero == total:
            return getBandwidth(order - 1, h)
        else:
            # check if we can find 0 from lower orders
            found = False
            zeroReq = total - zero
            zeroFound = 0
            for low in xrange(order - 1, -1, -1):
                ord_zero = h[low][0]
                added_here = min(zeroReq - zeroFound, ord_zero)
                zeroFound += added_here
                h[low][0] -= added_here
                if zeroFound == zeroReq:
                    found = True
                    break
            if not found:
                return order
            else:
                return getBandwidth(order - 1, h)


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = []
        for i in xrange(N):
            A.append(map(int, raw_input().split()))

        h = {}
        for i in xrange(N):
            for j in xrange(N):
                dist = abs(i - j)
                try:
                    h[dist][1] += 1
                    # Store number of zeroes/total count
                except KeyError:
                    h[dist] = [0, 1]
                if A[i][j] == 0:
                    h[dist][0] += 1
        print getBandwidth(N - 1, h)
