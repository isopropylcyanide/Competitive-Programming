from itertools import combinations, cycle


class Node:
    """A basic tree node"""

    def __init__(self, data):
        self.key = data
        self.left = self.right = None


def insertRec(i, tree, N):
    if i < N:
        if tree is None:
            tree = Node(A[i])
        tree.left = insertRec(i * 2 + 1, tree.left, N)
        tree.right = insertRec(i * 2 + 2, tree.right, N)
        return tree


def __inorder(root, P):
    if root is not None:
        __inorder(root.left, P)
        P.append(root.key)
        __inorder(root.right, P)


def solve(word, cmpr):

    swaps = 0

    # 1)
    chars = {c: [] for c in word}
    [chars[c].append(i) for i, c in enumerate(word)]
    for k in chars.keys():
        chars[k] = cycle(chars[k])

    # 2)
    idxs = [next(chars[c]) for c in cmpr]

    # 3)
    for cmb in combinations(idxs, 2):
        if cmb[0] > cmb[1]:
            swaps += 1

    return swaps

if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    root = insertRec(0, None, N)
    P = []
    __inorder(root, P)
    Q = P[:]
    Q.sort()
    print solve(P, Q)
