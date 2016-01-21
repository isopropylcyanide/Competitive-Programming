
from collections import Counter

lis = []
for i in xrange(input()):
    lis.append(raw_input())

dic = Counter(lis)

for i in xrange(input()):
    print dic[raw_input()]
