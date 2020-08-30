
def distance(p1, p2):
    return pow((p2[0] - p1[0])**2.0 + (p2[1] - p1[1])**2.0, 0.5)


def main():
    lis = []
    for i in xrange(input()):
        a, b = map(int, raw_input().split())
        lis.append((a, b))

    max_l = min(lis, key=lambda x: x[0])
    max_r = max(lis, key=lambda x: x[0])
    max_t = max(lis, key=lambda x: x[1])
    max_b = min(lis, key=lambda x: x[1])

    lis = []
    lis.append(distance(max_l, max_r))
    lis.append(distance(max_l, max_t))
    lis.append(distance(max_l, max_b))
    lis.append(distance(max_t, max_b))
    lis.append(distance(max_b, max_r))
    lis.append(distance(max_t, max_r))

    print "%6f" % max(lis)

if __name__ == '__main__':
    main()
