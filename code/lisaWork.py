
if __name__ == '__main__':
    n, k = map(int, raw_input().split())
    T = map(int, raw_input().split())

    currPage, special = 0, 0

    for i in xrange(len(T)):
        if T[i] <= k:
            currPage += 1
            if currPage >= 1 and currPage <= T[i]:
                special += 1
        else:
            quesPerPage = k
            lastPage = T[i] % k
            quesRange = [1, k]

            while quesPerPage <= T[i]:
                currPage += 1
                if currPage >= quesRange[0] and currPage <= quesRange[1]:
                    special += 1

                quesRange = [quesRange[1] + 1, quesRange[1] + k]
                quesPerPage += k

            if lastPage != 0:
                currPage += 1
                quesRange[1] = quesRange[0] + lastPage - 1
                if currPage >= quesRange[0] and currPage <= quesRange[1]:
                    special += 1

    print special
