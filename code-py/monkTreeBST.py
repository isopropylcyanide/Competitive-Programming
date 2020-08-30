

class Node:
    """A basic tree node"""

    def __init__(self, data):
        self.key = data
        self.left = self.right = None
        self.parent = None


class BST:
    """A bst class"""

    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self.__insert(self.root, key)

    def __insert(self, root, key):
        if root is None:
            return Node(key)

        if root.key > key:
            root.right = self.__insert(root.right, key)
            root.right.parent = root
        else:
            root.left = self.__insert(root.left, key)
            root.left.parent = root

        return root

    def storePath(self, node, upto):
        if node is None:
            return []
        P = [node.key]
        while node.parent != upto:
            node = node.parent
            P.append(node.key)

        return P

    def findLCA(self, a, b):
        return self.__lca(self.root, a, b)

    def __lca(self, root, a, b):
        if root is None:
            return None
        if root.key in [a, b]:
            return root

        l = self.__lca(root.left, a, b)
        r = self.__lca(root.right, a, b)
        if l and r:
            return root
        return l if l else r

    def search(self, key):
        return self.__search(self.root, key)

    def __search(self, root, key):
        if root is None:
            return
        elif root.key == key:
            return root
        elif root.key < key:
            return self.__search(root.left, key)
        else:
            return self.__search(root.right, key)


if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    tree = BST()
    map(lambda x: tree.insert(x), A)

    L, R = map(int, raw_input().split())
    LCA = tree.findLCA(L, R)
    A = tree.search(L)
    B = tree.search(R)

    C = tree.storePath(A, LCA)
    D = tree.storePath(B, LCA)
    LCA = L if LCA is None else LCA.key
    print max(LCA, max(max(C + [0]), max(D + [0])))
