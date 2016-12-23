import sys  # make Chef's Mom win anyhow

t = int(sys.stdin.readline())


def can_be_formed(x, n, on_table):
    sol = sum(on_table)

    if x > sol:
        return 0

    subset = [[0 for i in xrange(n + 1)] for j in xrange(sol + 1)]

    for i in xrange(n + 1):
        subset[0][i] = True

    for i in xrange(x + 1):
        subset[i][0] = False

    for i in xrange(sol + 1):
        for j in xrange(n + 1):
            subset[i][j] = subset[i][j - 1]
            if i >= on_table[j - 1]:
                subset[i][j] = subset[i][j] or subset[
                    i - on_table[j - 1]][j - 1]
    return subset[x][n]


def check_onTable(on_table, n):

    game_count = 1
    i = 1
    inf = 1

    while i:
        if can_be_formed(i, len(on_table), on_table):
            game_count += 1
        else:
            inf = 0
            break
        if not inf:
            break
        i += 1

    return game_count


while t:
    n, k = map(int, raw_input().split())

    if k == 0:
        if (n * (n + 1) / 2) % 2 == 0:
            print "Chef"
        else:
            print "Mom"
    else:

        missing = map(int, raw_input().split())

        # if 1 is in the missing array then Chef anyhow has to play first

        if 1 in missing:
            print "Chef"
        else:
            # create an array which consists of numbers on the table

            on_table = []
            on_table = [x for x in xrange(1, n + 1) if x not in missing]
            # print on_table

            # now for each number on the given table, check if it can be
            # calculated somehow(subset sum problem)

            if check_onTable(on_table, n) % 2 == 0:
                print "Mom"
            else:
                print "Chef"

    t -= 1
