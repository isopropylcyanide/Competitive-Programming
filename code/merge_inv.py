"""Count inversion cost
Also used to count inversions
Inplace mergeSort
"""

inv = 0

def mergeSort(lis):
    global inv,inv_cost

    # print 'Splitting: ',lis
    if len(lis)>1:
        mid = len(lis) / 2
        left = lis[:mid]
        right = lis[mid:]

        mergeSort(left)
        mergeSort(right)

        i, j, k = 0, 0, 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                lis[k] = left[i]
                i += 1
            else:
                inv += 1
                lis[k] = right[i]
                j += 1
            k += 1

        while i < len(left):
            lis[k] = left[i]
            k += 1
            i += 1

        while j < len(right):
            lis[k] = right[j]
            j += 1
            k += 1



def main():
    global inv
    n = input()
    d = map(int, raw_input().split())
    mergeSort(d)
    print 'Inversions are: ',inv


if __name__ == '__main__':
    main()
