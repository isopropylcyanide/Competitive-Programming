
def bo(row, col):
    if 1 <= row <= 8 and 1 <= col <= 8:
        return True
    return False

dirs = [[1, 0], [-1, 0], [0, 1], [0, -1], [-1, 1], [-1, -1], [1, 1], [1, -1]]

if __name__ == '__main__':
    s = raw_input()
    row = ord(s[0]) - 96
    col = int(s[1])
    print sum(1 for i in map(lambda x: bo(x[0] + row, x[1] + col), dirs) if i)
