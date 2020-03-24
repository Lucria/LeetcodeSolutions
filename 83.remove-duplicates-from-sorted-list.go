/*
 * @lc app=leetcode id=83 lang=golang
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if (head == nil) || (head.Next == nil) {
		return head
	}

	temp := head

	for temp != nil {
		next := temp.Next
		for next != nil && (next.Val == temp.Val) {
			next = next.Next
		}

		temp.Next = next
		temp = next
	}
	return head
}

// @lc code=end
