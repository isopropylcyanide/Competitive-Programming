from collections import Counter

s = map(str.upper, raw_input().split())
d = Counter(s)
for i in s:
    if d[i] != -1:
        print i, d[i]
        d[i] = -1
