
def solver(A, B):
    hamming = sum([1 for i, j in zip(A, B) if i != j])
    count_1_a = A.count('1')
    count_0_a = A.count('0')
    count_0_b = B.count('0')
    count_1_b = B.count('1')

    if count_0_a == len(A) or count_1_a == len(A):
        return "Unlucky Chef"

    ans = 0
    minDist = min(abs(count_0_a - count_0_b), abs(count_1_a - count_1_b))
    ans += minDist
    hamming -= minDist
    ans += hamming / 2

    return "Lucky Chef\n%d" % (ans)

if __name__ == '__main__':
    for _ in xrange(input()):
        A = raw_input()
        B = raw_input()
        print solver(A, B)
