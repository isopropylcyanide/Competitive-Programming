""" Chef and his best friend Aleksa are into mathematical games these days. Today, they have some ( >= 0 ) black cells
represented as B, and a white cell represented as W, lying randomly in a straight line. They have decided to play with
these cells. In a move, a player chooses some ( > 0 ) black cells lying on any one side of the white cell and remove
them. It should be noted that a player is not allowed to choose black cells from both side of the given white cell. Both
the players alternate their moves, and play optimally. The player who is unable to move in his respective turn will lose
the game. """


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
