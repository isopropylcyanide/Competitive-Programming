def mean(A):
    return sum(A) / (len(A) * 1.0)


def median(A):
    B, n = sorted(A), len(A)
    return (B[n / 2] + B[(n - 1) / 2]) / 2.0


def mode(A):
    from collections import Counter as co
    lis = co(A).most_common()

    return min([lis[0][0]] + [i for i, j in lis[1:] if j == lis[0][1]])


def std_deviation(A):
    from math import sqrt
    m = mean(A)
    return sqrt(sum(map(lambda x: pow(x - m, 2), A)) / len(A))


def findlargestN():
    match = 0.816496580928
    N = 1
    from time import sleep
    while True:
        sleep(0.1)
        N += 0.01
        cur = std_deviation([1, 2, 3, N])
        print 'N: ', N, ' : ', cur
        if cur == match:
            break
    return N


def pearsonCoeff(A, B):
    sA, sB = std_deviation(A), std_deviation(B)
    mA, mB = mean(A), mean(B)
    exp = 0.0
    for i, j in zip(A, B):
        exp += (i - mA) * (j - mB)
    exp /= len(A)

    return exp / (sA * sB)


def regressAtY(X, Y, xSpec):
    sumXY = sum([i * j for i, j in zip(X, Y)])
    mX, mY, n = mean(X), mean(Y), len(X)
    sumXSq = sum([i ** 2 for i in X])

    b = (sumXY - n * mX * mY) / (sumXSq - n * mX * mX)
    a = mY - b * mX
    ySpec = a + b * xSpec
    return ySpec


def spearmanCoeff(A, B):
    C = sorted(zip(A, B), key=lambda x: x[0])
    D = sorted(zip(A, B), key=lambda x: x[1])

    C = {k: v for v, k in enumerate(C)}
    D = {k: v for v, k in enumerate(D)}
    sumD = sum([(C[i] - D[i]) ** 2.0 for i in C.iterkeys()])
    n = len(A)
    return 1 - (6 * sumD) / (n**3 - n)

if __name__ == '__main__':
    A = [95, 85, 80, 70, 60]
    B = [85,  95, 70, 65, 70]
    print regressAtY(A, B, 80)
