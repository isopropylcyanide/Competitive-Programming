
def solve(N, B):
    if sum(B) % 2 == 1:
        return 'NO'
    a = map(lambda x: x % 2, B)
    lA = a.count(1)
    lB = ''.join([str(i) for i in a]).count('11')
    return 2 * lA - lB

if __name__ == "__main__":
    N = int(raw_input().strip())
    B = map(int, raw_input().strip().split(' '))
    print solve(N, B)
