
def maxStud(A, B):
    C = zip(A, B)
    C.sort(key=lambda x: x[0])

    prev, count = 0, 0
    for dead, time in C:
        if time <= dead - prev:
            count += 1
        prev = dead
    print count

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        B = map(int, raw_input().split())
        maxStud(A, B)
