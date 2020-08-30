import sys

"""
For each test case, output a single line. It must contain -1, if
permutation Q can't be obtained from permutation P using
 allowed cyclic shifts. Otherwise, print its 1-based index in the
 list of all permutations from set S, ordered  lexicographically.
  Since the answer can be very large, print it modulo 10^9 + 7.
"""

mod = 10**9 + 7
mod_inv = 500000004
MAX = 10**5 + 5
fact_list, inv = [], []


def _form(a, v, size):
    while a < size:
        v[a] += 1
        a += a & -a


def _get(a, v):
    ans = 0
    while a:
        ans += v[a]
        a -= a & -a
    return ans


def get_rotate_(N, P, Q):
    stored = Q[0]
    ind = P.index(stored)

    a_count = ind
    equal = 1

    for i in xrange(N):
        if P[a_count] != Q[i]:
            equal = 0
            break
        a_count += 1

        if a_count == N:
            a_count = 0

    if equal:
        return stored
    else:
        return -1


def get_parity(lst, N):
    V = [0] * MAX
    inversions = __BIT__(V, lst, N)
    return inversions % 2 == 0


def __BIT__(V, P, N):
    _sum = 0

    for i in xrange(N - 1, -1, -1):
        _sum += get(P[i], V)
        form(P[i], V)

    return _sum


def form(a, V):
    while a < MAX:
        V[a] += 1
        a += a & -a


def get(a, V):
    _ans = 0
    while a:
        _ans += V[a]
        a -= a & -a

    return _ans


def pre_compute(N):
    global fact_list, inv
    inv = [0] * (N + 1)
    fact_list = [0] * (N + 1)
    fact_list[0], fact_list[1] = 1, 1
    inv[0], inv[1] = 1, 1

    for i in xrange(2, N + 1):
        fact_list[i] = (i * fact_list[i - 1]) % mod
        inv[i] = (fact_list[i] * mod_inv) % mod


def get_lexic_number(N, lis):
    global inv
    ans = mod_inv

    count, V = [0] * (N + 1), [0] * (N + 1)
    for i in xrange(N - 1, -1, -1):
        count[i] = _get(lis[i], V)
        _form(lis[i], V, N + 1)

    count[N - 2] = 0

    for index in xrange(N - 2):
        number_of_smaller = count[index]
        ans = (ans + (inv[N - index - 1] * number_of_smaller))

    return ans


def get_lexic_number_even(N, lis):
    global fact_list
    ans = 1

    count, V = [0] * (N + 1), [0] * (N + 1)
    for i in xrange(N - 1, -1, -1):
        count[i] = _get(lis[i], V)
        _form(lis[i], V, N + 1)

    for index in xrange(N):
        f = fact_list[N - index - 1]
        number_of_smaller = count[index]

        ans = (ans + (f * number_of_smaller) % mod) % mod

    return ans


def super_smart_work(P, Q, N):
    if get_parity(P, N) == get_parity(Q, N):
        base = get_lexic_number(N, Q)
        print (base + mod_inv) % mod

    else:
        print -1


def main():
    for _ in xrange(input()):
        N, K = map(int, sys.stdin.readline().split())
        P = map(int, sys.stdin.readline().split())
        Q = map(int, sys.stdin.readline().split())

        if K == N:
            print get_rotate_(N, P, Q)
            continue

        if K % 2 == 0:
            print get_lexic_number_even(N, Q) % mod
            continue

        else:
            super_smart_work(P, Q, N)

if __name__ == '__main__':
    pre_compute(MAX)
    main()
