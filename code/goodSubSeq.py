
if __name__ == '__main__':
    S = raw_input()
    try:
        a = S.index('a')
        S = S[a:]
        S_ = S[::-1]
        c = len(S) - S_.index('c')
        S = S[:c]
        print S


    except ValueError:
        print 0
