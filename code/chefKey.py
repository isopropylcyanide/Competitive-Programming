def solve():
    i, j, k = map(lambda x: x.count('1'), [L1, L2, L3])
    ways = i + j * n + k
    if L3[-1] == '0':
        ways += 1
    else:
        i, j, k = 0, 0, 0
        while i < c - 1:
            if L3[c - i - 2] == '0':
                break
            ways -= 1
            i += 1

        if i == c - 1:
            while j < b:
                if L2[b - j - 1] == '0':
                    break
                ways -= 1
                j += 1

        if j == b:
            ways -= (n - 1) * b
            while k < a:
                if L1[a - k - 1] == '0':
                    break
                ways -= 1
                k += 1
        if k == a and ways != 1:
            ways = 0
    return ways

if __name__ == '__main__':
    for _ in xrange(input()):
        L1, L2, L3, n = map(str, raw_input().split())
        n = int(n)
        a, b, c = map(len, [L1, L2, L3])
        print solve()
