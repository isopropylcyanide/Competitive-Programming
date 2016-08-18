
def quickSelect(A, l, h, i):
    if l == h:
        return A[l]
    pivot = partition(A, l, h)
    k = pivot - l + 1
    print '\nFound pivot : ', pivot, ' k: ', k
    if i == k:
        return A[pivot]
    elif i < k:
        return quickSelect(A, l, pivot - 1, i)
    else:
        return quickSelect(A, pivot + 1, h, i - k)


def partition(A, l, h):
    # Select pivot at the lest value
    print 'Part called for l: %d h: %d' % (l, h)
    print 'Before part: ', A
    i, pivot = l, A[h]
    for j in xrange(l, h):
        if A[j] < pivot:
            A[i], A[j] = A[j], A[i]
            i += 1
    A[i], A[h] = A[h], A[i]
    print 'After part: ', A
    return i


def main():
    # A = []
    # for i in xrange(6):
    #     A.append(rr(0, 100))
    A = range(1, 11)
    copy = A[:]
    print A
    print sorted(A)
    # Select the third largest element
    for i in xrange(1, len(A)):
        print '\n Selecting %dth smallest' % (i)
        print i, quickSelect(A, 0, len(A) - 1, i)
        A = copy[:]


if __name__ == '__main__':
    main()
