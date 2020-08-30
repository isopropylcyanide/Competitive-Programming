
""" There is a N*N square matrix. You have been given N specifications, one per row of the matrix. The ith
specifications is represented by a pair of integers L[i] and R[i], denoting that all element belonging to columns
between L[i] and R[i] (both inclusive) in row i are 1, while the rest of the elements of the ith row are 0. Now you will
be given an integer Q, followed by Q operations: Each query is described by two integers x and y, which asks what will
be the parity of the sum of the matrix if the xth row and the yth column are removed from the matrix. """


def main():
    N = input()
    one_in_row = {}
    one_in_col = [0 for i in xrange(N + 1)]
    total_1 = 0

    for i in xrange(N):
        L = map(int, raw_input().split())
        one_in_row[i + 1] = [L[0], L[1], L[1] - L[0] + 1]

        for j in xrange(1, N + 1):
            if L[0] <= j <= L[1]:
                one_in_col[j] += 1

        total_1 += L[1] - L[0] + 1

    query = input()
    for _ in xrange(query):
        row, col = map(int, raw_input().split())

        in_row = one_in_row[row][2]
        in_col = one_in_col[col]

        ans = total_1 - (in_col + in_row)
        if one_in_row[row][0] <= col <= one_in_row[row][1]:
            ans -= 1

        if ans & 1:
            print 'O'
        else:
            print 'E'

if __name__ == '__main__':
    main()

uraneja@
