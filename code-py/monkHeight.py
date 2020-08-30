class Node:
    """A basic tree node"""

    def __init__(self, data):
        self.key = data
        self.left = self.right = None


class BST:
    """A bst class"""

    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self.__insert(self.root, key)

    def height(self):
        return self.__height(self.root)

    def __height(self, root):
        if root is not None:
            return 1 + max(self.__height(root.left),  self.__height(root.right))
        else:
            return 0

    def __insert(self, root, key):
        if root is None:
            return Node(key)

        if root.key < key:
            root.right = self.__insert(root.right, key)
        else:
            root.left = self.__insert(root.left, key)

        return root


if __name__ == '__main__':
    N = input()
    A = map(int, raw_input().split())
    tree = BST()
    for i in A:
        tree.insert(i)
    print tree.height()
