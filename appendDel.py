
def solve(S, T, K):
    n, m = len(S), len(T)
    firstMis = -1
    maxLen = max(n, m)
    S = S.ljust(maxLen, '!')
    T = T.ljust(maxLen, '!')

    for ind, i in enumerate(S):
        if i != T[ind]:
            firstMis = ind
            break
    # Strings are equal
    if firstMis == -1:
        if K % 2 == 0 or K > 2 * n:
            # yes we can always make it equal
            # notice we can delete first string any number of times
            return True
        else:
            return False

    # else strings aren't equal
    dist = n - firstMis + m - firstMis
    if K < dist:
        # hamming dist is atleast = dist
        return False
    elif K >= dist and (K - dist) % 2 == 0:
        # notice we can always add/delete one char
        # print 'idhar: ', K, dist, K - dist
        return True

    elif K > 2 * firstMis:
        # or if K - dist is odd, we check if it's > 2 * (firstMis -1)
        # print 'idhar behnchod', K, firstMis, 2 * (firstMis - 1)
        return True
    return False

if __name__ == '__main__':
    S = raw_input()
    T = raw_input()
    K = input()
    print 'Yes' if solve(S, T, K) else 'No'
