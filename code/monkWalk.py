
def validXY(x, y, R):
    if -R <= abs(x) <= R and -R <= abs(y) <= R:
        if x * x + y * y - R * R <= 0:
            return True
        return False
    return False


def binarySearch(L, l, r, R):
    print '\n In main: ', l, r
    if l > r:
        return 0

    if l == r:
        print '\n l == r: ', L[l]
        x, y = L[l]
        if validXY(x, y, R):
            print 'Returning 1'
            return 1
        return 0

    mid = l + (r - l) / 2
    x, y = L[mid]
    print 'mid: ', mid, ' : ', L[mid]

    if validXY(x, y, R):
        # All points below this will be inside circle
        print 'inside. so adding %d + upperrange' % (mid - l + 1)
        return (mid - l + 1) + binarySearch(L, mid + 1, r, R)
    else:
        # We will have to look in the left interval
        print 'outside. so looking in lower'
        return binarySearch(L, l, mid - 1, R)


if __name__ == '__main__':
    N = input()
    L = []
    for _ in xrange(N):
        L.append(map(int, raw_input().split()))

    # Sort by x coordinate
    L.sort(key=lambda x: (x[0], x[1]))
    print L

    for _ in xrange(input()):
        # Report the number of points lying in the radius
        R = input()
        a = binarySearch(L, 0, N - 1, R)
        print a
