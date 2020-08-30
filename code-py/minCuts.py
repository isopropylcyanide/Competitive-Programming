
if __name__ == '__main__':
    N = input()
    X = sorted(map(int, raw_input().split()))
    Y = sorted(map(int, raw_input().split()))
    possible, ops = True, 0
    i, j = 0, N - 1

    while i <= j:
        # print '\n start i: ', i, ' j: ', j
        _i, _j, no_op = i, j, True

        if X[i] == Y[i] and X[j] == Y[j]:
            # print "Perfect pair. Move on"
            i += 1
            j -= 1

        elif X[i] == Y[i] and X[j] > Y[j]:
            # no way X[j] can be further decremented
            possible = False
            break

        elif X[i] == Y[i] and X[j] < Y[j]:
            # print "We cant decrement here. Dont touch this X[i]"
            i += 1

        elif X[i] < Y[i] and X[j] == Y[j]:
            # no way X[i] can be further incremented
            possible = False
            break

        elif X[i] > Y[i] and X[j] == Y[j]:
            # print "we cant increment j here. Dont touch this x[j]"
            j -= 1

        elif X[i] > Y[i] and X[j] < Y[j]:
            # print "We need to operate. Dec X[i] and inc X[j]"
            no_op = False
            dA, dB = X[i] - Y[i], Y[j] - X[j]
            ops += min(dA, dB)
            X[i] -= min(dA, dB)
            X[j] += min(dA, dB)

        elif X[i] < Y[i]:
            # print "We need to operate. Dec X[i] and inc X[j]"
            ops += 1
            X[i] -= 1
            X[j] += 1

        elif X[j] > Y[j]:
            # print "There's no way as we had to increment X[j]"
            possible = False
            break

        # print '\n end i: ', i, ' j: ', j
        if i == _i and j == _j and no_op:
            possible = False
            break

    print ops if possible else -1
