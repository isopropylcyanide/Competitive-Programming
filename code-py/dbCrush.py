
def replace(s, fro, to, times, back):
    st, en, sp = (len(s) - 1, -1, -1) if back else (0, len(s), 1)
    for i in xrange(st, en, sp):
        if times <= 0:
            break
        elif s[i] == fro:
            s[i] = to
            times -= 1
    return s

if __name__ == '__main__':
    s = list(raw_input())
    n = len(s)
    c1, c2 = s.count('1'), s.count('2')
    diff = abs(c1 - c2)

    if c1 > c2:
        # ones are more
        if diff % 2 != 0:
            s.append('1')
            diff += 1
        # start replacing diff/2 1 to 2's
        s = replace(s, fro='1', to='2', times=diff / 2, back=True)

    elif c2 > c1:
        # two's are more
        if s[0] == '1':
            s = s + ['1']
        else:
            s = ['1'] + s

        diff -= 1
        # print 'or: ', ''.join(s)
        if diff % 2 != 0:
            s = ['1'] + s
            diff -= 1
        # print 'af: ', ''.join(s)
        s = replace(s, fro='2', to='1', times=diff / 2, back=False)

    print ''.join(s)
