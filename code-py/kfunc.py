import numpy

"""
f a sequence of numbers A1, A2, ... , AN form an arithmetic progression A, he was asked to calculate sum of F(Ai),
for L <= i <= R. F(X) is defined as: If X < 10 then F(X) = X. Else F(X) = F(sum_of_digits(X)).
"""
TAB = [[]] * 10
TSUM = 45

TAB[1] = [1, 2, 3, 4, 5, 6, 7, 8, 9]
TAB[2] = [2, 4, 6, 8, 1, 3, 5, 7, 9]
TAB[3] = [3, 6, 9, 3, 6, 9, 3, 6, 9]
TAB[4] = [4, 8, 3, 7, 2, 6, 1, 5, 9]
TAB[5] = [5, 1, 6, 2, 7, 3, 8, 4, 9]
TAB[6] = [6, 3, 9, 6, 3, 9, 6, 3, 9]
TAB[7] = [7, 5, 3, 1, 8, 6, 4, 2, 9]
TAB[8] = [8, 7, 6, 5, 4, 3, 2, 1, 9]
TAB[9] = [9, 9, 9, 9, 9, 9, 9, 9, 9]


def brute():
    for _ in xrange(input()):
        A1, D, L, R = map(int, raw_input().split())

        A = range(A1 + D * (L - 1), A1 + D * (R), D)
        print sum(map(lambda x: 1 + (x - 1) % 9, A))


def smart():
    for _ in xrange(input()):
        A1, D, L, R = map(int, raw_input().split())

        n = R - L + 1
        D = D % 9
        A1 = A1 + D * (L - 1)

        if D == 0:
            sum_of_first = 1 + (A1 - 1) % 9
            print sum_of_first * n

        elif D == 3:
            first = 1 + (A1 - 1) % 9
            second = 1 + (first + 3 - 1) % 9
            third = 1 + (second + 3 - 1) % 9

            ans = 0
            quo, mod = divmod(n, 3)

            ans += quo * (first + second + third)
            if mod == 1:
                ans += first
            elif mod == 2:
                ans += first + second

            print ans

        elif D == 6:
            first = 1 + (A1 - 1) % 9
            second = 1 + (first + 6 - 1) % 9
            third = 1 + (second + 6 - 1) % 9

            ans = 0
            quo, mod = divmod(n, 3)

            ans += quo * (first + second + third)
            if mod == 1:
                ans += first
            elif mod == 2:
                ans += first + second

            print ans

        else:
            first_in_table = 1 + (A1 - 1) % 9

            first_in_table_index = TAB[D].index(first_in_table)

            if n <= 9 - first_in_table_index:
                print sum(TAB[D][first_in_table_index:first_in_table_index + n])

            else:
                ans = 0
                offset = 9 - first_in_table_index
                ans += sum(TAB[D][first_in_table_index:])

                n -= offset
                Mult, mod = divmod(n, 9)

                ans += TSUM * Mult
                ans += sum(TAB[D][:mod])

                print ans


if __name__ == '__main__':
    # brute()
    smart()
