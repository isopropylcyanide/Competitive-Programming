def palin(s, K):
    n = len(s)
    s = list(s)
    disp, i, j = 0, 0, n - 1
    while i < j:
        if s[i] != s[j]:
            disp += 1
        i += 1
        j -= 1

    if disp > K:  # can't make it a palindrome
        return -1
    # else We can somehow convert it into a palindrome. Start by changing the
    # largest digits first
    i, j = 0, n - 1
    while disp:
        if s[i] != s[j]:
            big = max(s[i], s[j])
            s[i] = s[j] = big
            disp -= 1
            K -= 1

            # disparity removed. But can we change both to 9 by using one more
            # change
            if big != '9' and disp + 1 <= K:
                s[i] = s[j] = '9'
                K -= 1
        else:
            if s[i] != '9' and disp + 2 <= K:
                s[i] = s[j] = '9'
                K -= 2

        i += 1
        j -= 1

    i, j = 0, n - 1

    # if there's still space left for K
    while K > 0 and i <= j:
        if i == j:
            # last stage doesn't matter if you change or not
            if K >= 1 and s[i] != '9':
                s[i] = '9'
                K -= 1
            break

        elif i < j:
            # choose wisely s[i] is always equal to s[j]. Have to change in
            # pairs
            if s[i] != '9' and K >= 2:
                # can we take a risk? Yeah baby
                s[i] = s[j] = '9'
                K -= 2

        i += 1
        j -= 1

    return ''.join(s)


if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    s = raw_input()

    print palin(s, K)
