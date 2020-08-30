

def main():
    for _ in xrange(input()):
        N = input()
        A = sorted(map(int, raw_input().split()))
        maxMove = 0

        if N % 2 == 0:
            left, right = N / 2 - 1, N / 2
            while left >= 0 and right < N:
                if A[left] != A[right]:
                    maxMove += 1
                    left, right = left - 1, right + 1
                else:
                    if left == 0 or right == N - 1:
                        left -= 2
                        maxMove += 2

                    else:
                        if A[left - 1] == A[left] and A[right] == A[right + 1]:
                            maxMove += 2
                            left, right = left - 1, right - 1
                        else:
                            if A[left - 1] == A[left]:
                                maxMove += 2
                                left -= 2
                            else:
                                maxMove += 1
                                left -= 2

                            if A[right + 1] == A[right]:
                                maxMove += 2
                                right += 2

                            else:
                                maxMove += 1
                                right += 2

        else:
            cent = N / 2
            maxMove += 1
            left, right = cent - 1, cent + 1
            while left >= 0 and right < N:
                if A[left] != A[right]:
                    maxMove += 1
                    left, right = left - 1, right + 1
                else:
                    if left == 0 or right == N - 1:
                        left -= 2
                        maxMove += 2

                    else:
                        if A[left - 1] == A[left] and A[right] == A[right + 1]:
                            maxMove += 2
                            left, right = left - 1, right - 1
                        else:
                            if A[left - 1] == A[left]:
                                maxMove += 2
                                left -= 2
                            else:
                                maxMove += 1
                                left -= 2

                            if A[right + 1] == A[right]:
                                maxMove += 2
                                right += 2

                            else:
                                maxMove += 1
                                right += 2

        print maxMove

if __name__ == '__main__':
    main()
