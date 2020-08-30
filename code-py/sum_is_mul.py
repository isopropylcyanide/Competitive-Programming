

def main():
    for _ in xrange(input()):
        N = input()
        A = map(int, raw_input().split())
        count = 0

        for i in xrange(N):
            for j in xrange(i, N):
                mul = reduce(lambda x, y: x * y, A[i:j + 1])
                if mul == sum(A[i:j + 1]):
                    count += 1

        print count

if __name__ == '__main__':
    main()
