
# prime power predicate

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        if N <= 10:
            if N == 6:
                print "Misha"
            else:
                print "Chef"
        else:
            if N % 6 == 0:
                print "Misha"
            else:
                print "Chef"
