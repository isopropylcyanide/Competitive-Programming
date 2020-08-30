from itertools import *


def powerset(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s) + 1))

for _ in xrange(input()):
    n = input()
    lis = map(int, raw_input().split())
    ans = 0

    for i in powerset(lis):
        if i == ():
            continue
        pro = reduce(lambda x, y: x * y, i)
        root = pro ** 0.5
        if root == int(root):
            ans += 1

    print ans
