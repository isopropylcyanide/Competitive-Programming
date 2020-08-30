import sys
import math

# Don't let the machines win. You are humanity's last hope...

width = int(raw_input())  # the number of cells on the X axis
height = int(raw_input())  # the number of cells on the Y axis
L = []
for i in xrange(height):
    L.append(map(str, raw_input()))  # width characters, each either 0 or .

V = [[0 for i in xrange(width)] for j in xrange(height)]

for i in L:
    print >> sys.stderr, i
print >> sys.stderr

for i in xrange(height):
    for j in xrange(width):
        # Consider only power nodes that are unvisited
        if L[i][j] != '0' or L[i][j] == '0' and V[i][j] == 1:
            continue
        # else look right and bottom

        right, bottom = j + 1, i + 1
        rightNode, bottomNode = (-1, -1), (-1, -1)

        rightPower, bottomPower = False, False

        while right < width:
            if L[i][right] == '.':
                right += 1
            else:
                if V[i][right] == 1:
                    break
                else:
                    rightPower = True
                    break

        if rightPower:
            rightNode = (i, right)

        while bottom < height:
            if L[bottom][j] == '.':
                bottom += 1
            else:
                if V[bottom][j] == 1:
                    break
                else:
                    bottomPower = True
                    break

        if bottomPower:
            bottomNode = (bottom, j)

        V[i][j] = 1  # mark as visited
        print j, i, rightNode[1], rightNode[0], bottomNode[1], bottomNode[0]

# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

# Three coordinates: a node, its right neighbor, its bottom neighbor
