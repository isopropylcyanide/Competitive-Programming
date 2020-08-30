
def main():
    M, N = map(int, input().split())
    treePos = []
    totalTree = 0

    for i in range(M):
        row = list(map(int, input().split()))
        for j, val in enumerate(row):
            if val == 1:
                treePos.append((i, j))
                totalTree += 1

    if totalTree == 0:
        print (0)
        return

    minNurseryCost = 10**12

    for i in range(totalTree):
        currentMinNurseryCost = 0
        # print ('Choosing free as ', i, ' : ', treePos[i])

        for j in range(totalTree):
            free_x, free_y = treePos[i][0], treePos[i][1]
            _x, _y = treePos[j][0], treePos[j][1]
            curDist = linus_distance(free_x, free_y, _x, _y)
            # print ('Cost from ', treePos[i],
            #        ' to ', treePos[j], ' : ', curDist)
            currentMinNurseryCost += curDist

        minNurseryCost = min(minNurseryCost, currentMinNurseryCost)
        # print ('At end min cost global ', minNurseryCost)

    print (minNurseryCost)


def linus_distance(x1, y1, x2, y2):
    return max(abs(x1 - x2), abs(y1 - y2))


if __name__ == "__main__":
    main()
