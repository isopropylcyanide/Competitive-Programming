
if __name__ == '__main__':
    P, X = map(int, raw_input().split())
    exact_at = (P / X) - 1
    cess_at = 1 if P % X != 0 else 0
    _time = exact_at + cess_at

    if cess_at == 0:
        exact_at -= 1
    _time += (exact_at) * (exact_at + 1) / 2
    print _time
