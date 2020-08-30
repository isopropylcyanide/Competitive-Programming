
def main():
    for _ in range(int(input())):
        print (decode(input()))


def decode(string):
    result = ''
    for ind, i in enumerate(string):
        result += chr(ord(i) + ind + 1)
    return result


if __name__ == "__main__":
    main()
