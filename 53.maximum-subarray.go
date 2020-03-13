/*
 * @lc app=leetcode id=53 lang=golang
 *
 * [53] Maximum Subsumsay
 */

// @lc code=start
func maxSubArray(nums []int) int {
	length := len(nums)
	sums := nums[0]
	currentMax := nums[0]

	for i := 1; i < length; i++ {
		if sums < 0 {
			sums = nums[i]
		} else {
			sums += nums[i]
		}

		if currentMax < sums {
			currentMax = sums
		}
	}

	return currentMax

}

// @lc code=end
