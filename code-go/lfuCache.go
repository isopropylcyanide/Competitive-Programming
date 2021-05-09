package main

import (
	list "container/list"
	"fmt"
)

/**
Design and implement a data structure for a Least Frequently Used (LFU) cache.
When the cache reaches its capacity, it should invalidate and remove the least frequently
used key before inserting a new item. For this problem, when there is a tie (i.e., two or
more keys with the same frequency), the least recently used key would be invalidated.
*/
type LFUCache struct {
	capacity           int
	size               int
	_keyEntryLookup    map[int]*entry
	_freqListLookup    map[int]*list.List
	minActiveFrequency int
}

type entry struct {
	key       int
	val       int
	frequency int
	prev      *entry
	next      *entry
}

func Constructor(capacity int) LFUCache {
	return LFUCache{
		capacity:           capacity,
		size:               0,
		_keyEntryLookup:    make(map[int]*entry),
		_freqListLookup:    make(map[int]*list.List),
		minActiveFrequency: 0,
	}
}

func (cache *LFUCache) Get(key int) int {
	if _entry, ok := cache._keyEntryLookup[key]; !ok {
		return -1
	} else {
		cache.updateEntryStats(_entry)
		return _entry.val
	}
}

func (cache *LFUCache) updateEntryStats(entry *entry) {
	nodeFreq := entry.frequency
	//decrement the node from the freq (always exists) and add it to freq + 1 list (create if exists)
	if oldList, ok := cache._freqListLookup[nodeFreq]; ok {
		//if the entry in the old freq list, exists, remove it
		oldList.Remove(&list.Element{
			Value: *entry,
		})
		//reset frequency old list if its size is 0
		if cache.minActiveFrequency == nodeFreq && oldList.Len() == 0 {
			cache.minActiveFrequency = nodeFreq + 1
		}
	}
	entry.frequency += 1
	cache.addEntryToListSafe(entry, entry.frequency)
}

func (cache *LFUCache) addEntryToListSafe(entry *entry, nodeFreq int) {
	//checks if the list exists before calling methods on it
	newFreqList, ok := cache._freqListLookup[nodeFreq]
	if !ok {
		//create the list for the first time
		cache._freqListLookup[nodeFreq] = list.New()
		cache._freqListLookup[nodeFreq].PushFront(entry)

	} else {
		//it already exists, simply append entry
		newFreqList.PushFront(entry)
	}
}

func (cache *LFUCache) Put(key, val int) {
	//if key exists, we need to update it
	if cache.capacity == 0 {
		return
	}
	if _entry, ok := cache._keyEntryLookup[key]; ok {
		//update old _entry by "touching" it so that frequencies are now updated
		cache.updateEntryStats(_entry)
		_entry.val = val

	} else {
		//we need to add it, its like a new element for us
		if len(cache._keyEntryLookup) == cache.capacity {
			//need to evict the last element of the list denoted by "minActiveFrequency"
			mostInactiveList := cache._freqListLookup[cache.minActiveFrequency]
			if poppedNode := mostInactiveList.Remove(mostInactiveList.Back()); poppedNode != nil {
				delete(cache._keyEntryLookup, poppedNode.(*entry).key)
			}
			cache.size -= 1
		}
		newEntry := &entry{
			key:       key,
			val:       val,
			frequency: 1,
			prev:      nil,
			next:      nil,
		}
		cache._keyEntryLookup[key] = newEntry
		cache.addEntryToListSafe(newEntry, 1)
		cache.minActiveFrequency = 1
		cache.size += 1
	}
}

func main() {
	lfu := Constructor(2)
	lfu.Put(1, 1)           // cache=[1,_], cnt(1)=1
	lfu.Put(2, 2)           // cache=[2,1], cnt(2)=1, cnt(1)=1
	fmt.Println(lfu.Get(1)) // return 1
	lfu.Put(3, 3)           // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.

	fmt.Println(lfu.Get(2)) // return -1 (not found)
	fmt.Println(lfu.Get(3)) // return 3

	lfu.Put(4, 4) // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
	// cache=[4,3], cnt(4)=1, cnt(3)=2
	fmt.Println(lfu.Get(1)) // return -1 (not found)
	fmt.Println(lfu.Get(3)) // return 3
	fmt.Println(lfu.Get(4)) //
}
