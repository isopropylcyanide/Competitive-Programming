memo = {}
mod = 10**9 + 7


def C(n, r, p):
    ''' {n choose r} modulo p (p is prime) '''
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    if n >= p:  # Lucas theorem
        return C(n / p, r / p, p) * C(n % p, r % p, p) % p
    if (n, r, p) not in memo:
        memo[n, r, p] = (C(n - 1, r - 1, p) + C(n - 1, r, p)) % p
    return memo[n, r, p]


def longest_common_prefix(seq1, seq2):
    start = 0
    while start < min(len(seq1), len(seq2)):
        if seq1[start] != seq2[start]:
            break
        start += 1
    return start

if __name__ == '__main__':
    s = raw_input()
    s += s[::-1]
    n = len(s)
    # Construct suffix array
    L = []
    for i in xrange(n - 1, -1, -1):
        if i >= n / 2:
            L.append((s[i:], 'R'))
        else:
            L.append((s[i:], 'O'))

    L.sort()
    print L
    count, i = 0, 0
    while i < n - 1:
        if L[i][1] == 'R' and L[i + 1][1] == 'O':
            val = longest_common_prefix(L[i][0], L[i + 1][0])
            print 'For %s and %s lcp: %d' % (L[i][0], L[i + 1][0], val)
            if val >= 4:
                # count = (count + 1) % mod
                count = (count + C(val, 4, mod)) % mod
        i += 1
    print count
