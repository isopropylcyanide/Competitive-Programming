N, M = map(int, raw_input().split())
A = map(int, raw_input().split())

m = sum(A) * 1.0 / M
i = 0
T = []
while i < len(A):
    c = A[i]
    g = [A[i]]
    i += 1
    while i < len(A) and c + A[i] <= m:
        c += A[i]
        g.append(A[i])
        i += 1
    T.append(g)
print T
print max([sum(x) for x in T])
