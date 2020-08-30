K = input()
A = list(raw_input())
N = len(A)
count = 0

for i in xrange(N - K + 1):
    m = set()
    m.add(A[i])
    extra = 0
    for j in xrange(i + 1, N):
        if len(m) == K:
            if A[j] in m:
                extra += 1
                continue
            else:
                break
        else:
            m.add(A[j])

    if len(m) == K:
        count += (1 + extra)

print count
