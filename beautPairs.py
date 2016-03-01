
def intersect(A, B):
    i, j, ans = 0, 0, 0

    while i < len(A) and j < len(B):
        if A[i] == B[j]:
            ans += 1
            i += 1
            j += 1

        else:
            if A[i] < B[j]:
                i += 1
            else:
                j += 1

    return ans


def main():
    N = input()
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())

    A.sort()
    B.sort()
    pair = intersect(A, B)
    if pair == N:
        print pair - 1
    elif pair < N:
        print pair + 1

if __name__ == '__main__':
    main()

    #
