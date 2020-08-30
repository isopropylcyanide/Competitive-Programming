
def solve(N, K):
    if N == 1:
        return 'a' if K == 1 else 'No'
    elif K == N:
        return 'a' * N
    elif K == N + 1 and N == 2:
        return 'ab'
    else:
        return 'No'

if __name__ == '__main__':
    N, K = map(int, raw_input().split())
    print solve(N, K)
