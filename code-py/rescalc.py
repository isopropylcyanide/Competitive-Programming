from collections import defaultdict as dd


def scoreType(box):
    if len(box) == 4:
        return 1
    elif len(box) == 5:
        return 2
    elif len(box) == 6:
        return 4
    return 0

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        maxScore, maxPeople = -1, []
        for __ in xrange(N):
            A = map(int, raw_input().split())
            curScore = A[0]
            m = dd(int)
            for i in A[1:]:
                m[i] += 1

            d = sorted(m.itervalues())
            while len(d) >= 4:
                curScore += scoreType(d) * d[0]
                d = [i - d[0] for i in d if i - d[0] != 0]
                # print 'curScore: ', curScore, ' d: ', d

            if curScore > maxScore:
                maxScore, maxPeople = curScore, [__ + 1]
            elif curScore == maxScore:
                maxPeople.append(__ + 1)
        if len(maxPeople) > 1:
            print 'tie'
        else:
            print 'chef' if maxPeople[0] == 1 else maxPeople[0]
