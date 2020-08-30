
def solve():
    L = []
    for i in xrange(7):
        L.append(map(int, raw_input().split()))
    player = input()

    """ Each player will try to :
    a) suppress the other's win and
    b) initiate his own victory
     Depending upon the gravity of the situation, make the required move.
     If the other player is just about to win, try to suppress that rather than
     initiate your own new scheme
    c) Gravity of the situation increases with decreasing moves left to play
    """

    # Store current status in each row
    # pA is the current top stack for player 1
    # pB is the current top stack for player 2
    # p0 is the current remaining space left at top
    # Store current status in each row
    rowStatus = [0 for i in xrange(7)]

    # Store current status in each column
    colStatus = [0 for i in xrange(8)]
    for col in xrange(8):
        pA = pB = p0 = i = 0
        if L[i][col] == 0:
            while i < 7 and L[i][col] == 0:
                p0 += 1
                i += 1

        if i < 7 and L[i][col] == 1:
            while i < 7 and L[i][col] == 1:
                pA += 1
                i += 1

        elif i < 7 and L[i][col] == 2:
            while i < 7 and L[i][col] == 2:
                pB += 1
                i += 1
        colStatus[col] = [pA, pB, p0]

    # print '\nColStatus'
    # for i in colStatus:
    #     print i

    if player == 2:
        """ Get best column according to the Gravity
        One which has most 1's and most 2's and one which has space naturlich
        """
        # get those cols which have 2 on top and are winnable
        # i.e abs(pB - 4) < p0
        winnableCol = [(k[2], v) for v, k in enumerate(colStatus)
                       if k[2] >= 4 - k[1] and k[0] == 0]

        # get those cols which have 1 on top and are winnableCol
        losableCol = [(k[2], v) for v, k in enumerate(colStatus)
                      if k[2] >= 4 - k[0] and k[1] == 0]

        # From each losableCol and winnableCol, decide which to play
        # In each winnableCol and losableCol entry find the entry
        # which has the lowest p0

        minWinnable_P0 = min(winnableCol, key=lambda x: x[0])
        minLosable_P0 = min(losableCol, key=lambda x: x[0])
        colAns = 0
        if minWinnable_P0[0] < minLosable_P0[0]:
            colAns = minWinnable_P0
        else:
            colAns = minLosable_P0

    elif player == 1:
        """ Get best column according to the Gravity
        One which has most 2's and most 1's and one which has space naturlich
        """
        # get those cols which have 1 on top and are winnable
        # i.e abs(pB - 4) < p0
        winnableCol = [(k[2], v) for v, k in enumerate(colStatus)
                       if k[2] >= 4 - k[0] and k[1] == 0]

        # get those cols which have 2 on top and are winnableCol
        losableCol = [(k[2], v) for v, k in enumerate(colStatus)
                      if k[2] >= 4 - k[1] and k[0] == 0]

        # From each losableCol and winnableCol, decide which to play
        # In each winnableCol and losableCol entry find the entry
        # which has the lowest p0
        minWinnable_P0 = min(winnableCol, key=lambda x: x[0])
        minLosable_P0 = min(losableCol, key=lambda x: x[0])

        colAns = 0
        if minWinnable_P0[0] < minLosable_P0[0]:
            colAns = minWinnable_P0
        else:
            colAns = minLosable_P0

        # Now find the best option for each row had there been only row moves
        # if chances of winning in row mode are


if __name__ == '__main__':
    solve()
