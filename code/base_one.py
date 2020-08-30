

def base10conv(n, b):
    if n < b:
        return str(n)
    else:
        rem = n % b
        return base10conv(n / b, b) + str(rem)


def numBasesStartWithOne(N):
    count = 0
    for i in xrange(2, N + 1):
        co = base10conv(N, i)
        if co[0] == '1':
            count += 1
            # print '%d starts with 1 in base %d : %s' % (N, i, co)
    return count

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        if str(N)[0] == '1':
            print 'INFINITY'
        else:
            print numBasesStartWithOne(N)
