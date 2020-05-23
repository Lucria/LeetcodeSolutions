/*
 * @lc app=leetcode id=55 lang=golang
 *
 * [55] Jump Game
 */

// @lc code=start
func canJump(nums []int) bool {
	size := len(nums)
	lastIndex := size - 1
	for i := size - 2; i >= 0; i-- {
		if i+nums[i] >= lastIndex {
			lastIndex = i
		}
	}
	return lastIndex <= 0
}

// @lc code=end
