
if __name__ == '__main__':
    for _ in xrange(input()):
        s = raw_input()
        M = input()
        h = {}
        L = []
        for _ in xrange(M):
            char, point = map(str, raw_input().split())
            L.append([char, point])
        L = L[::-1]
        flag = True
        for i in L:
            orig, trans = i
            if s.count(trans) == 0:
                flag = False
                break
            else:
                s = s.replace(trans, orig)
        print 'Yes' if flag else 'No'
