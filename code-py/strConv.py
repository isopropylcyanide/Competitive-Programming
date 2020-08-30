# Two strings A and B. Do  minimum conversions to make A = B. You can,
# Replace a curacter(except 'J') by next curacter from the set. i.e
# "ABE" to "ACE"# Replace a curacter(except 'A') by previous curacter
# from the set. i.e "ABE" to "ABD" Swap any two curacters. i.e "ABE" to "EBA"


def minConv(A, B):
    mySet = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J']
    view = set()
    import sys

    def minConvUtil(c, S, minE):
        print 'Cur S: ', S, ' c: ', c
        if tuple(S) in view:
            return
        else:
            view.add(tuple())

        if S == list(B):
            print 'finally B: ', B
            minE = min(minE, c)
            return

        C = S[:]
        # either replaceNext replacePrev or swap

        for i in xrange(len(B) - 1):
            for j in xrange(i + 1, len(B)):
                D = C[:]
                E = C[:]
                F = C[:]
                D[i], D[j] = D[j], D[i]
                nextVal = mySet[(1 + mySet.index(C[i])) % len(mySet)]
                prevVal = mySet[(mySet.index(C[i]) - 1) % len(mySet)]
                print 'For cur: ', C[i], ' next: ', nextVal, ' prev: ', prevVal

                repNext, repPrev = True, True
                if C[i] == 'J':
                    repNext = False
                else:
                    E[i] = nextVal
                    print 'next E: ', E

                if C[i] == 'A':
                    repPrev = False
                else:
                    F[i] = prevVal
                    print 'prev F: ', F

                print 'and swap: ', D

                if repNext and repPrev:
                    min(minConvUtil(c + 1, D, minE), minConvUtil(c + 1, E, minE),
                        minConvUtil(c + 1, F, minE))

                elif repNext:
                    min(minConvUtil(c + 1, D, minE),
                        minConvUtil(c + 1, E, minE))

                elif repPrev:
                    min(minConvUtil(c + 1, D, minE),
                        minConvUtil(c + 1, F, minE))

    minE = sys.maxint
    minConvUtil(0, list(A), minE)
    print minE

if __name__ == '__main__':
    for _ in xrange(input()):
        minConv(raw_input(), raw_input())
