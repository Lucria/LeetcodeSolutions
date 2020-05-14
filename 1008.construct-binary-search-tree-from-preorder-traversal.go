/*
 * @lc app=leetcode id=1008 lang=golang
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func bstFromPreorder(preorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	idx := 1
	for idx < len(preorder) && preorder[idx] < preorder[0] {
		idx++
	}

	result := TreeNode{
		Val:   preorder[0],
		Left:  bstFromPreorder(preorder[1:idx]),
		Right: bstFromPreorder(preorder[idx:]),
	}

	return &result
	// worst O(N^2) solution
}

// @lc code=end
