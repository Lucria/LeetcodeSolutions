/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */

// @lc code=start
func climbStairs(n int) int {
	// Basically fibonacci sequene
	if n <= 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	if n == 2 {
		return 2
	}
	answer := 0
	temp1 := 1
	temp2 := 2
	for i := 2; i < n; i++ {
		answer = temp1 + temp2
		temp1 = temp2
		temp2 = answer
	}
	return answer
}

// @lc code=end
