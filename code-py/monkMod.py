from math import ceil

if __name__ == '__main__':
    N = input()
    A = map(str, raw_input().split())
    max_i = int(ceil(len(str(max(A))) * 1.0 / 5))
    A = map(lambda x: x.zfill(max_i * 5), A)
    A = [[i, 0] for i in A]

    B = A[:]
    for i in xrange(1, max_i + 1):
        l, r = 1 + 5 * (i - 1), 5 * i
        for _j in xrange(len(B)):
            j = B[_j][0]
            val = j[-r:-l + 1] if i != 1 else j[-r:]
            val = int(val)
            B[_j][1] = (str(val))
        B.sort(key=lambda x: x[1])
        for i in B:
            print i[0].lstrip('0'),
        print
