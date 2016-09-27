
# Check if A represents a rangeMinimum Seg tree
# All leaves should be distinct
from collections import Counter


def build(st, pos, l, r, L):
    if l > r:
        return
    if l == r:
        st[pos] = L[l]
        return
    m = l + ((r - l) >> 1)
    build(st, pos * 2 + 1, l, m, L)
    build(st, pos * 2 + 2, m + 1, r, L)
    st[pos] = min(st[pos * 2 + 1], st[pos * 2 + 2])


def solve(L, C, keys, N):
    # L: leaf nodes of actual array
    # C: Counter values of keys not in leaf. Useful for swap
    # keys: what actual keys should be

    if len(keys) != N:
        # there aren't N distinct keys
        return 'NO'

    avail = {j: i for i, j in enumerate(L)}

    for l in xrange(N):
        if L[l] == keys[l]:
            avail.pop(L[l])

        elif C[keys[l]] > 0:
            C[keys[l]] -= 1
            if C[keys[l]] == 0:
                C.pop(keys[l])
            C[L[l]] += 1
            L[l] = keys[l]

        elif keys[l] in avail:
            temp = L[l]
            L[l] = keys[l]
            L[avail[keys[l]]] = temp
            avail.pop(keys[l])

        # there's no way we can swap something
        else:
            return 'NO'

    # If we are here, then we are through the first stage
    # Build a st out of L and check if the counter of st[:-N] == C
    st = [0] * (2 * N - 1)
    build(st, 0, 0, N - 1, L)
    _c = Counter(st[:-N])
    if _c == C:
        return 'YES\n' + ' '.join(map(str, st))
    return 'NO'


if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    C = Counter(A[:-N])

    keys = sorted(Counter(A).iterkeys())
    L = A[-N:]  # all leaf nodes
    print solve(L, C, keys, N)
