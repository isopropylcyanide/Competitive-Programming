# Enter your code here. Read input from STDIN. Print output to STDOUT


def minComb(s, t):
    count = 0
    for i, j in zip(s, t):
        a, b = int(i), int(j)
        a, b = min(a, b), max(a, b)
        count += min(a - b, abs(a - b - 10))
    return count

if __name__ == "__main__":
    _ = input()
    print minComb(raw_input(), raw_input())
