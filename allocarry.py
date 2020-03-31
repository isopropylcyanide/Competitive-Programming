
def main():
    N = int(input())
    _odd_sum = _even_sum = 0
    _sub_allocarry = []

    for _ in range(N):
        num = list(map(int, input()))
        # _odd_sum = _even_sum = 0
        for ind, i in enumerate(num):
            if ind % 2 == 0:
                _even_sum += i
            else:
                _odd_sum += i

        _sub_allocarry.append(_even_sum - _odd_sum)

    # print (_odd_sum, _even_sum, abs(_even_sum - _odd_sum))
    # print (_sub_allocarry)
    _odd_alloc = _even_alloc = 0

    for ind, i in enumerate(_sub_allocarry):
        if ind % 2 == 0:
            _even_alloc += i
        else:
            _odd_alloc += i

    # print (_even_alloc, _odd_alloc)
    print (_even_alloc - _odd_alloc)


if __name__ == "__main__":
    main()
