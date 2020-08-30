

def dio(N, C):
    if N % 2 == 0:
        t = (2 * C) / N
        if (2 * C) % N != 0:
            return "No"
        elif t >= 2 * N:
            return "Yes"
        elif t >= N + 1 and t % 2 != 0:
            return "Yes"
        else:
            return "No"
    else:
        t = C / N
        if C % N != 0:
            return "No"
        elif t >= (N + 1) / 2:
            return "Yes"
        else:
            return "No"

if __name__ == '__main__':
    for _ in xrange(input()):
        N, C = map(int, raw_input().split())
        print dio(N, C)
