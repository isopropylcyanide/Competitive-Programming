class heap:

    def __init__(self, array):
        self.arr = array
        self.heapSize = len(self.arr)

    def parent(self, i):
        return i >> 1

    def left(self, i):
        return i << 1 | 1

    def right(self, i):
        return (i + 1) << 1

    def maxHeapify(self, i):
        # Restore heapify property
        l, r = self.left(i), self.right(i)
        largest = i

        if l < self.heapSize and self.arr[l] > self.arr[i]:
            largest = l
        if r < self.heapSize and self.arr[r] > self.arr[largest]:
            largest = r

        if i == largest:
            return
        self.arr[i], self.arr[largest] = self.arr[largest], self.arr[i]
        self.maxHeapify(largest)

    def buildHeap(self):
        # Build a heap from the mid down to 1
        # Call maxHeapify on each
        mid = len(self.arr) / 2
        for i in xrange(mid, -1, -1):
            self.maxHeapify(i)

    def heapsort(self):
        # Build a heap
        # Exchange the top with the last
        self.buildHeap()
        for i in xrange(len(self.arr) - 1, 0, -1):
            self.arr[i], self.arr[0] = self.arr[0], self.arr[i]
            self.heapSize -= 1
            self.maxHeapify(0)

    def display(self):
        print ' '.join([str(i) for i in self.arr])


def main():
    arr = [10, 6, 3, 12, -1, 7, 4, 20]
    print arr
    h = heap(arr)
    h.heapsort()
    h.display()

if __name__ == '__main__':
    main()
