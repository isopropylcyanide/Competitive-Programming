
def main():
    A = input().split()
    N = int(A[0])
    attendees = list(map(lambda x: (x[0]).upper(), A[1:]))
    attendeeOrder = {k + 1: v for k, v in enumerate(attendees)}
    attendeeOrder[0] = 'X'

    maxWidth = maxDepth = 2 * N + 1

    for i in range(1, maxDepth + 1):
        for j in range(1, maxWidth + 1):
            print (nationThatBelongsHere(i, j, N, attendeeOrder), end=' ')
        print ()


def nationThatBelongsHere(i, j, N, attendeeOrder):
    max_X_dist = absHorizontalDistanceFromX(j, N)
    max_Y_dist = absVerticalDistanceFromX(i, N)
    return attendeeOrder[max(max_X_dist, max_Y_dist)]


def absVerticalDistanceFromX(i, N):
    y_coord_Center = N + 1
    return abs(y_coord_Center - i)


def absHorizontalDistanceFromX(j, N):
    x_coord_Center = N + 1
    return abs(x_coord_Center - j)


if __name__ == "__main__":
    main()
