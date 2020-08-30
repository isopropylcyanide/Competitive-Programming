
n, k, swaps = map(int, raw_input().split())
lis = map(int, raw_input().strip())


def return_index_of_first_one(lis, fro, n, untouch):
    for index, i in enumerate(lis[fro:n]):
        if untouch[index] != 1 and i == 1:
            return index
    return n

untouch = [0 for i in xrange(n)]

while swaps != 0:
    init_swap = swaps

    # if first index==k then the first element will be the biggest:
    if lis[k] == 1 and lis[0] != 1:
        lis[k], lis[0] = lis[0], lis[k]
        swaps -= 1
        untouch[0] = 1

    else:
        first = return_index_of_first_one(lis, 0, n, untouch)
        if first == n:
            break

        # if first index<k,move to next index
        if first < k:
            untouch[first] = 1
            continue

            # else first_index>k. There exists some i such that j-m=k
            # here j=first_index and m=k+j. Swap elem at m and j only if
            # lis[m]!=1
        else:
            m = first - k

            if lis[m] == 0:  # if item at m is 0 , swap. Move on
                lis[m], lis[first] = lis[first], lis[m]
                swaps -= 1
    if init_swap == swaps:
        break

print ''.join([str(i) for i in lis])
