type ListNode struct {
	Val  int
	Next *ListNode
}

func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	cur := head.Next
	prev := head
	for cur != nil {
		gcdVal := gcd(prev.Val, cur.Val)
		newNode := &ListNode{Val: gcdVal, Next: cur}
		prev.Next = newNode
		prev = cur
		cur = cur.Next
	}

	return head
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
