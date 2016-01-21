
def quickSelect(arr, low, high, i):
    if low == high:
        return arr[low]
    pivot = partition(arr, low, high)
    k = pivot - low + 1
    if i == k:
        return arr[pivot]
    if i < k:
        return quickSelect(arr, low, pivot - 1, i)
    else:
        return quickSelect(arr, pivot + 1, high, i - k)


def partition(arr, low, high):
    i, pivot = low, arr[high]
    for j in xrange(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    if i < high:
        arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def main():
    arr = [2, 8, 7, 1, 3, 5, 6, 4]
    copy = arr[:]
    # Select the third largest element
    for i in xrange(1, len(arr)):
        print i, quickSelect(arr, 0, len(arr) - 1, i)
        arr = copy[:]


if __name__ == '__main__':
    main()
