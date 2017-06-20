
def isPrimitive(r, p):
    # Check if r is a primitive root of p
    L = []
    for i in xrange(p - 1):
        L.append(pow(r, i, p))
    if len(L) == len(set(L)):
        return True
    return False

if __name__ == '__main__':
    N = input()
    minm, tot = None, 0
    for i in xrange(1, N):
        if isPrimitive(i, N):
            if minm is None:
                minm = i
                tot += 1
            else:
                tot += 1
    print minm, tot
