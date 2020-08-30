import collections


def doc(s):
    if hasattr(s, '__call__'):
        s = s.__doc__

    def f(g):
        g.__doc__ = s
        return g
    return f


class heapdict(collections.MutableMapping):
    __marker = object()

    @staticmethod
    def _parent(i):
        return ((i - 1) >> 1)

    @staticmethod
    def _left(i):
        return ((i << 1) + 1)

    @staticmethod
    def _right(i):
        return ((i + 1) << 1)

    def __init__(self, *args, **kw):
        self.heap = []
        self.d = {}
        self.update(*args, **kw)

    @doc(dict.clear)
    def clear(self):
        del self.heap[:]
        self.d.clear()

    @doc(dict.__setitem__)
    def __setitem__(self, key, value):
        if key in self.d:
            self.pop(key)
        wrapper = [value, key, len(self)]
        self.d[key] = wrapper
        self.heap.append(wrapper)
        self._decrease_key(len(self.heap) - 1)

    def _min_heapify(self, i):
        l = self._left(i)
        r = self._right(i)
        n = len(self.heap)
        if l < n and self.heap[l][0] < self.heap[i][0]:
            low = l
        else:
            low = i
        if r < n and self.heap[r][0] < self.heap[low][0]:
            low = r

        if low != i:
            self._swap(i, low)
            self._min_heapify(low)

    def _decrease_key(self, i):
        while i:
            parent = self._parent(i)
            if self.heap[parent][0] < self.heap[i][0]:
                break
            self._swap(i, parent)
            i = parent

    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
        self.heap[i][2] = i
        self.heap[j][2] = j

    @doc(dict.__delitem__)
    def __delitem__(self, key):
        wrapper = self.d[key]
        while wrapper[2]:
            parentpos = self._parent(wrapper[2])
            parent = self.heap[parentpos]
            self._swap(wrapper[2], parent[2])
        self.popitem()

    @doc(dict.__getitem__)
    def __getitem__(self, key):
        return self.d[key][0]

    @doc(dict.__iter__)
    def __iter__(self):
        return iter(self.d)

    def popitem(self):
        """D.popitem() -> (k, v), remove and return the (key, value) pair with
        lowest\value; but raise KeyError if D is empty."""
        wrapper = self.heap[0]
        if len(self.heap) == 1:
            self.heap.pop()
        else:
            self.heap[0] = self.heap.pop(-1)
            self.heap[0][2] = 0
            self._min_heapify(0)
        del self.d[wrapper[1]]
        return wrapper[1], wrapper[0]

    @doc(dict.__len__)
    def __len__(self):
        return len(self.d)

    def peekitem(self):
        """D.peekitem() -> (k, v), return the (key, value) pair with lowest value;
        \n but raise KeyError if D is empty."""
        return (self.heap[0][1], self.heap[0][0])


class Solution:
    # @param A : list of integers
    # @param B : list of list of integers
    # @return a list of integers

    def getMode(self, A, B):
        d = collections.Counter(A)
        hp = heapdict()

        for a, b in d.iteritems():
            hp[a] = -b
        l = []
        # print hp.items()
        # print

        for x, v in B:
            hp[A[x - 1]] += 1
            A[x - 1] = v
            # print x - 1, v, A,
            try:
                hp[v] -= 1
            except KeyError:
                hp[v] = -1
            l.append(hp.peekitem()[0])
            # print hp.items()
        return l

if __name__ == '__main__':
    S = Solution()
    A = [2, 2, 2, 3, 3]
    B = [
        [1, 3],
        [5, 4],
        [2, 4]]
    print S.getMode(A, B)
