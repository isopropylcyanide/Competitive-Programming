"""
 Build a number with n digits. Start with a number without any digits. There will be n moves. In each move players append one digit to a number so a new digit will be the last digit after the move. The only rule is: after every appended digit, the number has to be divisible by this digit. It implies that they can never add a digit 0
"""

mod = 2 ** 32

from itertools import product

if __name__ == '__main__':
    for N in xrange(1, 100):

        count = 0
        A = range(1, 10)
        for i in product(A, repeat=N):
            a = ''.join([str(k) for k in i])
            last = int(a[-1])
            if int(a) % last == 0:
                count = (count + 1) % mod

        print 'i: ', N, ' - ', count
