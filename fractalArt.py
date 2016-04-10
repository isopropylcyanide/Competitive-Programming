
def fractalArt(K, C, S, inp):

    if S == K:
        print 'Case #%d:' % (inp + 1),
        for i in xrange(1, S + 1):
            print i,
        print

    elif 2 * S <= K:
        print 'Case #%d:' % (inp + 1), 'IMPOSSIBLE'

    else:
        print 'Case #%d:' % (inp + 1),
        for i in xrange(2, 2 + S):
            print i,
        print


if __name__ == '__main__':
    for i in xrange(input()):
        K, C, S = map(int, raw_input().split())
        fractalArt(K, C, S, i)
