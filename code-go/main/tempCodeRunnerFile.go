var head *ListNode = nil
	var ptr *ListNode = nil
	for _, val := range x {
		ptr = &ListNode{val, nil}
		if head != nil {
			head = ptr
		}
		ptr = ptr.Next
	}