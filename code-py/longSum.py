
def add(A, B):
    n, m = len(A), len(B)
    m = max(n, m)
    A = A.rjust(m, '0')
    B = B.rjust(m, '0')
    carry, res = 0, ''

    for a, b in zip(A[::-1], B[::-1]):
        sum_m = int(a) + int(b) + carry
        res = str(sum_m % 10) + res
        carry = sum_m / 10
    if carry != 0:
        res = str(carry) + res
    return res

if __name__ == '__main__':
    for _ in xrange(input()):
        A = raw_input()
        B = raw_input()
        print add(A, B)
