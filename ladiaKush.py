
def solve(A, N):
    # substrings divisible by 8 and not by 3
    pres_8, res_8 = [0] * 8, [0] * 8
    pres_3, res_3 = [0] * 3, [0] * 3
    c_8, c_3 = 0, 0

    for i in A:
        mod_8 = int(i) % 8
        mod_3 = int(i) % 3
        for j in xrange(8):
            res_8[j] = pres_8[(8 - mod_8 + j) % 8]
        res_8[mod_8] += 1
        c_8 += res_8[0]
        pres_8 = res_8[:]

        for j in xrange(3):
            res_3[j] = pres_3[(3 - mod_3 + j) % 3]
        res_3[mod_3] += 1
        c_3 += res_3[0]
        pres_3 = res_3[:]

    print c_8, c_3


def solveAyush(A):
    a, b, c = 3, 5, 7
    allCount = 0
    curSum = 0

    for cur in A[::-1]:
        # print '\n for main digit: ', cur
        b, c = a, b
        a = int(cur)
        if c % 2 == 0:
            # even
            num = a * 10 + b
            num_3 = a * 100 + b * 10 + c

            if c in [0, 8]:
                # form 4k
                if num % 4 == 0:
                    summ = sum(map(int, str(num_3)))
                    curSum += summ
                    if curSum % 3 != 0:
                        allCount += 1
                else:
                    num_2 = b * 10 + c
                    if num_2 in [24, 32, 8, 16, 40, 64, 80, 88, 56]:
                        allCount += 1

            elif c == 2:
                # 4k + 3
                if num % 4 == 3:
                    summ = sum(map(int, str(num_3)))
                    curSum += summ
                    if curSum % 3 != 0:
                        allCount += 1
                else:
                    num_2 = b * 10 + c
                    if num_2 in [24, 32, 8, 16, 40, 64, 80, 88, 56]:
                        allCount += 1

            elif c == 4:
                # 4k + 2
                if num % 4 == 2:
                    summ = sum(map(int, str(num_3)))
                    curSum += summ
                    if curSum % 3 != 0:
                        allCount += 1
                else:
                    num_2 = b * 10 + c
                    if num_2 in [24, 32, 8, 16, 40, 64, 80, 88, 56]:
                        allCount += 1

            elif c == 6:
                # 4k + 1
                if num % 4 == 1:
                    summ = sum(map(int, str(num_3)))
                    curSum += summ
                    if curSum % 3 != 0:
                        allCount += 1
                else:
                    num_2 = b * 10 + c
                    if num_2 in [24, 32, 8, 16, 40, 64, 80, 88, 56]:
                        allCount += 1
        # print 'a: %d b: %d c: %d ' % (a, b, c)
    return allCount


if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = raw_input()
        print solveAyush(A)
