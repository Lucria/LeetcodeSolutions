/*
 * @lc app=leetcode id=124 lang=golang
 *
 * [124] Binary Tree Maximum Path Sum
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
func maxPathSum(root *TreeNode) int {
	if root == nil {
		return 0
	}

	answer := root.Val
	maxPathBranch(root, &answer)
	return answer
}

func maxPathBranch(node *TreeNode, value *int) int {
	if node == nil {
		return 0
	}

	leftMax := max(0, maxPathBranch(node.Left, value))
	rightMax := max(0, maxPathBranch(node.Right, value))
	*value = max(*value, leftMax+rightMax+node.Val)
	return max(leftMax, rightMax) + node.Val

}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end
