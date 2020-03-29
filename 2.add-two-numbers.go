/*
 * @lc app=leetcode id=2 lang=golang
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	result, carryOver := 0, 0
	var headNode, currentNode *ListNode
	currNode1 := l1
	currNode2 := l2
	for (currNode1 != nil) && (currNode2 != nil) {
		result = (currNode1.Val + currNode2.Val + carryOver) % 10
		carryOver = (currNode1.Val + currNode2.Val + carryOver) / 10

		if headNode == nil {
			headNode = &ListNode{result, nil}
			currentNode = headNode
		} else {
			currentNode.Next = &ListNode{result, nil}
			currentNode = currentNode.Next
		}

		currNode1 = currNode1.Next
		currNode2 = currNode2.Next
	}

	for currNode1 != nil {
		result = (currNode1.Val + carryOver) % 10
		carryOver = (currNode1.Val + carryOver) / 10
		currentNode.Next = &ListNode{result, nil}

		currNode1 = currNode1.Next
		currentNode = currentNode.Next
	}

	for currNode2 != nil {
		result = (currNode2.Val + carryOver) % 10
		carryOver = (currNode2.Val + carryOver) / 10
		currentNode.Next = &ListNode{result, nil}

		currNode2 = currNode2.Next
		currentNode = currentNode.Next
	}

	if carryOver != 0 {
		currentNode.Next = &ListNode{1, nil}
		carryOver = 0
	}

	return headNode
}

// @lc code=end
