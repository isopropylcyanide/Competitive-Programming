def mapper(i):
    a = bin(ord(i))[2:]
    return a.zfill(7)


def solveR(i, val, delimit):
    l.append(delimit)
    j = i + 1
    zeroCount = 1
    while j < len(m) and m[j] == val:
        zeroCount += 1
        j += 1
    l.append('0' * zeroCount)
    return j

m = ''.join(map(lambda x: mapper(x), raw_input()))
i, l = 0, []
while i < len(m):
    if m[i] == '0':
        i = solveR(i, '0', '00')
    else:
        i = solveR(i, '1', '0')

print ' '.join(l)
