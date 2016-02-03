
def main():
    for _ in xrange(input()):
        X = input()
        if X == 0:
            print 3

        else:
            if X == 1:
                print 1
            else:
                if X % 4 == 0:
                    print X
                elif (X - 3) % 4 == 0:
                    print X - 1
                else:
                    print -1

if __name__ == '__main__':
    main()
