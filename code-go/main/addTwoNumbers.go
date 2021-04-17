package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoListsWithCarry(l1 *ListNode, l2 *ListNode, carry int, st *[]int) {
	if l1 != nil && l2 != nil {
		//both are non null
		num := l1.Val + l2.Val + carry
		carry = num / 10
		*st = append(*st, num%10)
		addTwoListsWithCarry(l1.Next, l2.Next, carry, st)

	} else if l2 != nil {
		//list l2 is non null
		num := l2.Val + carry
		carry = num / 10
		*st = append(*st, num%10)
		addTwoListsWithCarry(l1, l2.Next, carry, st)

	} else if l1 != nil {
		num := l1.Val + carry
		carry = num / 10
		*st = append(*st, num%10)
		addTwoListsWithCarry(l1.Next, l2, carry, st)

	} else {
		if carry == 1 {
			*st = append(*st, carry)
		}
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	//recur both lists, storing a carry variable
	x := []int{}
	addTwoListsWithCarry(l1, l2, 0, &x)

	ptr := &ListNode{-1, nil}
	head := ptr

	for _, val := range x {
		ptr.Next = &ListNode{val, nil}
		ptr = ptr.Next
	}

	return head.Next
}

func (l *ListNode) print() {
	copy := l
	for {
		if copy == nil {
			break
		}
		fmt.Printf(" %d ->", copy.Val)
		copy = copy.Next
	}
	fmt.Println()
}

func main() {
	listA := &ListNode{2, &ListNode{4, &ListNode{3, nil}}}
	listB := &ListNode{5, &ListNode{6, &ListNode{4, nil}}}

	// listA := &ListNode{0, nil}
	// listB := &ListNode{0, nil}

	// listA := &ListNode{9, &ListNode{9, &ListNode{9, &ListNode{9, &ListNode{9, &ListNode{9, &ListNode{9, nil}}}}}}}
	// listB := &ListNode{9, &ListNode{9, &ListNode{9, &ListNode{9, nil}}}}
	listC := addTwoNumbers(listA, listB)
	listC.print()
}
