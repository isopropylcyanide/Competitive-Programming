
from collections import Counter

if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    D = Counter(A)
    print N - D.most_common(1)[0][1]
