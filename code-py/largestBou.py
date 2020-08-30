if __name__ == '__main__':
    for _ in xrange(input()):
        r1, g1, b1 = map(int, raw_input().split())
        r2, g2, b2 = map(int, raw_input().split())
        r3, g3, b3 = map(int, raw_input().split())
        sg1 = r1 + g1 + b1
        sg2 = r2 + g2 + b2
        sg3 = r3 + g3 + b3

        if sg1 % 2 == 0:
            sg1 -= 1
        if sg2 % 2 == 0:
            sg2 -= 1
        if sg3 % 2 == 0:
            sg3 -= 1

        ss1 = r1 + r2 + r3
        ss2 = g1 + g2 + g3
        ss3 = b1 + b2 + b3
        if ss1 % 2 == 0:
            ss1 -= 1
        if ss2 % 2 == 0:
            ss2 -= 1
        if ss3 % 2 == 0:
            ss3 -= 1
        # print 'max: ', [sg1, sg2, sg3, ss1, ss2, ss3]
        maxm = max(0, max([sg1, sg2, sg3, ss1, ss2, ss3]))
        print maxm
