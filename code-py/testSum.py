import string
MAX = 800000

g = set()

digs = string.digits + string.letters


def int2base(x, base):
    if x == 0:
        return digs[0]
    else:
        sign = 1
    x *= sign
    digits = []
    while x:
        digits.append(digs[x % base])
        x /= base
    digits.reverse()
    return ''.join(digits)


def sieve():
    global g
    P = [1 for i in xrange(MAX + 5)]
    P[0], P[1] = 0, 0
    for i in xrange(2, MAX):
        if P[i]:
            g.add(int2base(i, 36))
            for j in xrange(i * i, MAX, i):
                P[j] = 0


def solve(N, iters):
    global g
    limit = min(N, MAX)
    for dig in xrange(2, limit):
        i = int2base(dig, 36)
        if i not in g:
            continue
        else:
            allFound, j, iterations = True, int(i, 36), iters
            while iterations:
                j = 2 * j + 1
                if int2base(j, 36) not in g:
                    allFound = False
                    break
                iterations -= 1
            if allFound:
                print int(i, 36),


if __name__ == "__main__":
    sieve()
    print 'done'
    N = input()
    i = input()
    solve(N, i)
