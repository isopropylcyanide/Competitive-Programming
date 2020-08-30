

def sleepBleatrix(N, inp):
    digits = set(list(str(N)))
    sleep = False

    for i in xrange(2, 100):
        for k in str(N * i):
            digits.add(str(k))
        if len(digits) == 10:
            sleep = True
            N = N * i
            break

    if sleep:
        print 'CASE #%d: %d' % (inp + 1, N)
    else:
        print 'CASE #%d: %s' % (inp + 1, 'INSOMNIA')

if __name__ == '__main__':
    for i in xrange(input()):
        N = input()
        sleepBleatrix(N, i)
