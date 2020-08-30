
MAX = 100005
G_MAX = 66540

rect = [
    1,    2,    3,    4,    6,    7,    8,   12,   14,   15,
    16,   17,   32,   34,   48,   51,   64,   68,   96,  102,
    112,  119,  128,  136,  192,  204,  224,  238,  240,  255,
    256,  272,  273,  512,  544,  546,  768,  816,  819, 1024,
    1088, 1092, 1536, 1632, 1638, 1792, 1904, 1911, 2048, 2176,
    2184, 3072, 3264, 3276, 3584, 3808, 3822, 3840, 4080, 4095,
    4096, 4352, 4368, 4369, 8192, 8704, 8736, 8738, 12288, 13056,
    13104, 13107, 16384, 17408, 17472, 17476, 24576, 26112, 26208, 26214,
    28672, 30464, 30576, 30583, 32768, 34816, 34944, 34952, 49152, 52224,
    52416, 52428, 57344, 60928, 61152, 61166, 61440, 65280, 65520, 65535
]


def mex(n):
    m = 0
    while n[m]:
        m += 1
    return m


def nim(cur, dp):
    if dp[cur] != -1:
        return dp[cur]

    exclude = [0 for i in xrange(G_MAX)]
    for i in rect:
        if (cur & i) == i:
            # this rectangle is a valid move
            next_mat = cur & ~i
            exclude[nim(next_mat, dp)] = 1
    dp[cur] = mex(exclude)
    return dp[cur]


def nimber(matrix, dp):
    if matrix == 65535:
        dp[matrix] = 3
        return 3

    try:
        return nim(matrix, dp)
    except Exception:
        return 0


def readBinaryMatrix(newline=True):
    matrixBinary = 0
    for i in xrange(4):
        S = map(int, raw_input().strip())
        for j in xrange(4):
            matrixBinary += int(S[j]) * pow(2, 15 - (4 * i + j))
    S = raw_input().strip() if newline else ''
    return matrixBinary


def solve(L, R, grundy):
    xorRes = 0
    for i in xrange(L, R + 1):
        xorRes ^= grundy[i]

    return 'Lotsy' if xorRes == 0 else "Pishty"

if __name__ == '__main__':
    for _ in xrange(input()):
        global grundy
        dp = [-1 for i in xrange(G_MAX)]
        dp[0] = 0

        N, M = map(int, raw_input().split())
        grundy = [0 for i in xrange(MAX)]
        for x in xrange(N):
            matrixBinary = readBinaryMatrix()
            grundy[x] = nimber(matrixBinary, dp)

        for x in xrange(M):
            inp = map(int, raw_input().split())
            if inp[0] == 1:
                L, R = inp[1] - 1, inp[2] - 1
                print solve(L, R, grundy)
            else:
                pos = inp[1] - 1
                matrixBinary = readBinaryMatrix(False)
                grundy[pos] = nimber(matrixBinary, dp)
