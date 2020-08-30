
def main(n):
    def drawFractal(x, y, dp, ht):
        if dp == 0:
            return
        inc = ht / 2
        for i in xrange(1, inc + 1):
            mat[y + i][x] = "1"
            mat[y + inc + i][x - i] = "1"
            mat[y + inc + i][x + i] = "1"

        drawFractal(x - inc, y + ht, dp - 1, inc)
        drawFractal(x + inc, y + ht, dp - 1, inc)

    rows, cols = 63, 100
    mat = [['_' for i in xrange(1, cols + 1)] for i in xrange(1, rows + 1)]

    drawFractal(50, 0, n, 32)
    for i in mat[::-1]:
        print ''.join(i)
        print

if __name__ == '__main__':
    iterationFractal = input()
    main(iterationFractal)
