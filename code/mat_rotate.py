"""
    You are given a 2D matrix, a, of dimension MxN and a positive integer R. You have to rotate the matrix R times and print the resultant matrix. Rotation should be in anti-clockwise direction.

    Test:
        5 4 7
        1 2 3 4
        7 8 9 10
        13 14 15 16
        19 20 21 22
        25 26 27 28

    Output:
        28 27 26 25
        22 9 15 19
        16 8 21 13
        10 14 20 7
        4 3 2 1
"""

from collections import deque
from itertools import islice

M, N, R = map(int, raw_input().split())

mat = []
for _ in xrange(M):
    mat.append(map(int, raw_input().split()))

row, col = M, N
row_counter, col_counter = 0, 0

while row > 0 and col > 0:

    mod = R % ((row - 2) * 2 + col * 2)
    # print '\nTo rotate %dx%d %d times' % (row, col, mod)

    # Read the values and put them into a deque for easy rotation

    top = mat[row_counter][col_counter:col_counter + col]

    bottom = mat[row_counter + row - 1][col_counter:col_counter + col]

    left, right = [], []
    for sc in xrange(row_counter + 1, row_counter + row - 1):
        left.append(mat[sc][row_counter])
        right.append(mat[sc][row_counter + col - 1])

    # Rotate the deque so formed
    my_deque = deque(top + right + bottom[::-1] + left[::-1])
    my_deque.rotate(-1 * mod)

    # Top is now the first col values
    mat[row_counter][
        col_counter:col_counter + col] = list(islice(my_deque, 0, col))
    deque_point = col

    # Now add right back
    for sc in xrange(row_counter + 1, row_counter + row - 1):
        mat[sc][row_counter + col - 1] = my_deque[deque_point]
        deque_point += 1

    # Now add bottom back(remember: reverse)
    mat[row_counter + row -
        1][col_counter:col_counter + col] = list(islice(my_deque, deque_point, deque_point + col))[::-1]

    deque_point = 1

    # Now add left back(remember: reverse)
    for sc in xrange(row_counter + 1, row_counter + row - 1):
        mat[sc][row_counter] = my_deque[len(my_deque) - deque_point]
        deque_point += 1

    row -= 2
    col -= 2
    row_counter += 1
    col_counter += 1

# print
for i in mat:
    print ' '.join([str(j) for j in i])



