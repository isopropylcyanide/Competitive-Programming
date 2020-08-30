import string
from itertools import combinations as ce

BASE_LIST = string.digits + string.letters + '_@'
BASE_DICT = dict((c, i) for i, c in enumerate(BASE_LIST))


def base_decode(string, reverse_base=BASE_DICT):
    length = len(reverse_base)
    ret = 0
    for i, c in enumerate(string[::-1]):
        ret += (length ** i) * reverse_base[c]

    return ret


def get_divs(l):
    divs = set([1])
    for i in xrange(1, len(l) + 1):
        for j in list(ce(l, i)):
            divs.add(reduce(lambda x, y: x * y, j))
    for i in divs:
        print i,


def base_encode(integer, base=BASE_LIST):
    length = len(base)
    ret = ''
    while integer != 0:
        ret = base[integer % length] + ret
        integer /= length

    return ret


fi = open("t1.txt", "r")
fo = open("t2.txt", 'w')

for i in fi:
    lis = i.split(',')

for i in lis:
    fo.write(base_encode(int(i)) + ',')

fi.close()
fo.close()
