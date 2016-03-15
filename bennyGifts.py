

if __name__ == '__main__':
    S = raw_input()
    V = set()
    x, y = 0, 0
    V.add((x, y))
    icyFall = 0

    for i in S:
        if i == 'L':
            x, y = x, y - 1
            if (x, y) in V:
                icyFall += 1
            V.add((x, y))

        elif i == 'R':
            x, y = x, y + 1
            if (x, y) in V:
                icyFall += 1
            V.add((x, y))

        elif i == 'U':
            x, y = x - 1, y
            if (x, y) in V:
                icyFall += 1
            V.add((x, y))

        elif i == 'D':
            x, y = x + 1, y
            if (x, y) in V:
                icyFall += 1
            V.add((x, y))
    print icyFall
