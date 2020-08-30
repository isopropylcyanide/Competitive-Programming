
from collections import Counter


def lcs_length(a, b):
    table = [[0] * (len(b) + 1) for _ in xrange(len(a) + 1)]
    for i, ca in enumerate(a, 1):
        for j, cb in enumerate(b, 1):
            table[i][j] = (
                table[i - 1][j - 1] + 1 if ca == cb else
                max(table[i][j - 1], table[i - 1][j]))
    return table[-1][-1]

if __name__ == '__main__':
    for _ in xrange(input()):
        lenLcs = lcs_length(raw_input(), 'milly')
        if lenLcs == 5:
            print 'Milly is Intelligent'
        else:
            print 'Milly is not Intelligent'
