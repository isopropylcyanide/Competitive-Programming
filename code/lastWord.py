from collections import deque


def printLastWord(S, inp):
    T = deque()
    for i in S:
        if not T:
            T.append(i)
        else:
            if ord(i) >= ord(T[0]):
                T.appendleft(i)
            else:
                T.append(i)
    print 'Case #%d:' % (inp + 1), ''.join(T)


if __name__ == '__main__':
    for i in xrange(input()):
        S = raw_input()
        printLastWord(S, i)
