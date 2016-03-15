
if __name__ == '__main__':
    from math import sqrt
    a, b, p = map(int, raw_input().split())
    val = b * (1 - (sqrt(p)) / 10.)
    print("%.2f" % val)
