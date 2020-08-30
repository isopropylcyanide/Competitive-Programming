if __name__ == '__main__':
    for _ in xrange(input()):
        s = raw_input()
        s = s.split('e')
        n, m = s[0].split('.')
        power = int(s[1])

        if power == 0:
            if len(m) == 1 and m[0] == '0':
                print n
            else:
                print n + '.' + m

        elif power >= len(m):
            m += '0' * (power - len(m))
            st = n + m
            print st.lstrip('0').zfill(1)
        else:
            m = list(m)
            m.insert(power, '.')
            m = ''.join(m)
            st = n + m
            l, r = st.split('.')
            print l.lstrip('0').zfill(1) + '.' + r
