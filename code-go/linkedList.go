package main

type MyLinkedList struct {
	head *mllEntry
	size int
}

type mllEntry struct {
	val  int
	prev *mllEntry
	next *mllEntry
}

func ConstructorLinkedList() MyLinkedList {
	return MyLinkedList{
		head: nil,
		size: 0,
	}
}

// Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (l *MyLinkedList) Get(index int) int {
	entry := l.getEntry(index)
	if entry == nil {
		return -1
	}
	return entry.val
}

// AddAtHead Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (l *MyLinkedList) AddAtHead(val int) {
	defer l.incrementSize()
	node := l.createEntry(val)
	if l.size == 0 {
		l.head = node
		return
	}
	tmp := l.head.next
	node.next = tmp
	if tmp.prev != nil {
		tmp.prev = node
	}
	l.head = node
}

// AddAtTail Append a node of value val to the last element of the linked list. */
func (l *MyLinkedList) AddAtTail(val int) {
	if l.size == 0 {
		l.AddAtHead(val)
		return
	}
	defer l.incrementSize()
	tail := l.getEntry(l.size - 1)
	node := l.createEntry(val)
	tail.next = node
	node.prev = tail
}

// AddAtIndex Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (l *MyLinkedList) AddAtIndex(index int, val int) {
	if index == 0 {
		l.AddAtHead(val)
		return
	}
	if index == l.size {
		l.AddAtTail(val)
		return
	}
	if index > l.size {
		return
	}
	defer l.incrementSize()
	//by now there's a prev entry for sure
	entry := l.getEntry(index)
	node := l.createEntry(val)
	entry.prev.next = node
	node.prev = entry.prev
	node.next = entry
	entry.prev = node
}

// DeleteAtIndex Delete the index-th node in the linked list, if the index is valid. */
func (l *MyLinkedList) DeleteAtIndex(index int) {
	defer l.decrementSize()
	if index < 0 || index >= l.size {
		return
	}
	if index == 0 {
		//remove at head..special case
		l.head = l.head.next
		if l.head != nil {
			l.head.prev = nil
		}
		return
	}
	//confirmed there will be a previous element
	entry := l.getEntry(index)
	entry.prev.next = entry.next
	if entry.next != nil {
		entry.next.prev = entry.prev
	}
	entry.prev = nil
	entry.next = nil
}

func (l MyLinkedList) getEntry(index int) *mllEntry {
	if index >= l.size {
		return nil
	}
	tmp, ctr := l.head, 0
	for tmp != nil {
		if ctr == index {
			return tmp
		}
		tmp = tmp.next
		ctr += 1
	}
	return nil
}

func (l *MyLinkedList) createEntry(val int) *mllEntry {
	return &mllEntry{
		val: val,
	}
}

func (l *MyLinkedList) incrementSize() {
	l.size += 1
}

func (l *MyLinkedList) decrementSize() {
	l.size -= 1
}

func main() {
	myLinkedList := ConstructorLinkedList()
	myLinkedList.AddAtTail(1)
	myLinkedList.AddAtTail(2)
	myLinkedList.AddAtTail(3)
	myLinkedList.DeleteAtIndex(2)
	myLinkedList.DeleteAtIndex(1)
	myLinkedList.DeleteAtIndex(0)
	//myLinkedList.DeleteAtIndex(0)
	//myLinkedList.DeleteAtIndex(0)
	//myLinkedList.AddAtIndex(1, 2)    // linked list becomes 1->2->
	//fmt.Println(myLinkedList.Get(1)) // return
	//myLinkedList.DeleteAtIndex(1)    // now the linked list is 1->
	//fmt.Println(myLinkedList.Get(1))
}
