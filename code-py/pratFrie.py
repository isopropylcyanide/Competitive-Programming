def solve(N, K, l):
        # Calculate prefix sum
    i, j = 0, 0
    cur = l[0]

    found = False
    while j < N:
        if cur > K:
            cur -= l[i]
            i += 1
        elif cur == K:
            found = True
            break
        else:
            j += 1
            cur += l[j]
        if i > j:
            j += 1
    return "YES" if found else "NO"


if __name__ == "__main__":
    for _ in xrange(input()):
        N, K = map(int, raw_input().split())
        l = []
        for i in xrange(N):
            l.append(input())

        print solve(N, K, l)
