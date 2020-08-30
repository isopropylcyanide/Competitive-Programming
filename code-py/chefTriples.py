from itertools import combinations as ce


def main():
    N = input()
    a = zip(xrange(3 * N), map(int, raw_input().split()))

    a.sort(key=lambda x: x[1])
    print a


if __name__ == '__main__':
    main()
