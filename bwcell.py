

def main():
    for _ in xrange(input()):
        S = raw_input()

        W_index = S.index('W')
        S_left = S[:W_index]
        S_right = S[W_index + 1:]

        # print S_left, S_right
        len_l = len(S_left)
        len_r = len(S_right)

        if len_l == 0 and len_r == 0:
            print 'Chef'

        elif (len_l == 0 and len_r != 0) or (len_l != 0 and len_r == 0):
            print 'Aleksa'

        elif len_r == len_l:
            print 'Chef'

        else:
            print 'Aleksa'

if __name__ == '__main__':
    main()
