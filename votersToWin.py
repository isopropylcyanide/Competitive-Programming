
def main():
    for _ in range(int(input())):
        A = list(map(int, input().split()))[1:]
        minPostsNeeded = len(A) - 1

        for i in range(len(A) - 2, -1, -1):
            if A[i] != 0:
                minPostsNeeded -= A[i]
            if minPostsNeeded <= 0:
                print ('Able to satisfy in front. Setting min to ', i)
                minPostsNeeded = i
            print ('minPosts ', minPostsNeeded, ' i ', i, ' A[i] ', A[i])
        print (minPostsNeeded)


if __name__ == "__main__":
    main()
