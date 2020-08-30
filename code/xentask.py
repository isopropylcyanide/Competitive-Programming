

if __name__ == '__main__':
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        B = map(int, raw_input().split())
        a, b = 0, 0
        switch = 0
        for i, j in zip(A, B):
            if switch:
                a, b = a + j, b + i
            else:
                a, b = a + i, b + j
            switch ^= 1
        print min(a, b)
