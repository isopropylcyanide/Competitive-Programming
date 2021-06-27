package main

import "fmt"

type LRUCache struct {
	capacity        int
	size            int
	_keyEntryLookUp map[int]*lruEntry
	entries         *linkedList
}

type lruEntry struct {
	key  int
	val  int
	prev *lruEntry
	next *lruEntry
}

type linkedList struct {
	head   *lruEntry
	length int
}

func ConstructorLRUCache(capacity int) LRUCache {
	return LRUCache{
		capacity:        capacity,
		size:            0,
		_keyEntryLookUp: make(map[int]*lruEntry),
		entries:         &linkedList{},
	}
}

func (list *linkedList) insertAtBeginning(entry *lruEntry) {
	if list.head == nil {
		//first item in the list
		list.head = entry
		return
	}
	//need to update head accordingly
	entry.next = list.head
	list.head.prev = entry
	entry.prev = nil
	list.head = entry
}

func (list *linkedList) removeFromTail() *lruEntry {
	if list.head == nil {
		return nil
	}
	tmp := list.head
	for tmp.next != nil {
		tmp = tmp.next
	}
	if tmp.prev != nil {
		tmp.prev.next = nil
	}
	tmp.prev = nil
	return tmp
}

// Moves entry
func (list *linkedList) moveEntryToBeginning(entry *lruEntry) {
	//Case 1: head = tail = entry
	if list.head == nil || entry == nil {
		return
	}
	if list.head == entry {
		//nothing to do
		return
	}
	//first fix the middle pointers
	entry.prev.next = entry.next
	if entry.next != nil {
		entry.next.prev = entry.prev
	}
	list.insertAtBeginning(entry)
}

// Get gets the value in the cache specified by the key and marks it as the most
// recently used
func (l *LRUCache) Get(key int) int {
	entry, ok := l._keyEntryLookUp[key]
	if !ok || entry == nil {
		return -1
	}
	if entry != l.entries.head {
		//if this is already at the top, why bother
		l.entries.moveEntryToBeginning(entry)
	}
	return entry.val
}

// Put checks if the key exists. If yes, it moves it to the front
// If key doesn't exist and there's no capacity, it removes the front and adds it
// Else, it creates a new lfu_entry and moves it to the front of the list
func (l *LRUCache) Put(key, val int) {
	if entry, ok := l._keyEntryLookUp[key]; !ok || entry == nil {
		if l.size == l.capacity {
			//gotta remove the tail node
			tailEntry := l.entries.removeFromTail()
			l._keyEntryLookUp[tailEntry.key] = nil
			l.size -= 1
		}
		//add the new lfu_entry to the first o
		l.addNewEntry(key, val)
		l.size += 1

	} else {
		//entry already exists, we just need to move it to the front
		l.entries.moveEntryToBeginning(entry)
		entry.val = val
	}
}

func (l *LRUCache) addNewEntry(key int, val int) {
	newEntry := &lruEntry{
		key:  key,
		val:  val,
		prev: nil,
		next: nil,
	}
	l.entries.insertAtBeginning(newEntry)
	l._keyEntryLookUp[key] = newEntry
}

func main() {
	lRUCache := ConstructorLRUCache(2)
	lRUCache.Put(1, 1)           // cache is {1=1}
	lRUCache.Put(2, 2)           // cache is {1=1, 2=2}
	fmt.Println(lRUCache.Get(1)) // return 1
	lRUCache.Put(3, 3)           // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	fmt.Println(lRUCache.Get(2)) // returns -1 (not found)
	lRUCache.Put(4, 4)           // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	fmt.Println(lRUCache.Get(1)) // return -1 (not found)
	fmt.Println(lRUCache.Get(3)) // return 3
	fmt.Println(lRUCache.Get(4)) // return 4
}
