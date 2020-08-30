import heapq


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None

    def __lt__(self, other):
    return self.val < other.val


class Solution:
    # @param A : list of linked list
    # @return the head node in the linked list

    def mergeKLists(self, A):
        head = ListNode(0)
        minHeap = []
        for node in A:
            if node is not None:
                heapq.heappush(minHeap, node)

        p = head
        while minHeap:
            temp = heapq.heappop(minHeap)
            p.next = temp
            if temp.next:
                heapq.heappush(minHeap, temp.next)
            p = p.next

        return head.next

if __name__ == '__main__':
    a = ListNode(1)
    a.next = ListNode(10)
    a.next.next = ListNode(20)

    b = ListNode(4)
    b.next = ListNode(11)
    b.next.next = ListNode(13)

    c = ListNode(3)
    c.next = ListNode(8)
    c.next.next = ListNode(9)

    d = Solution().mergeKLists([a, b, c])
    while d:
        print " ", d.val,
        d = d.next
