/*
 * @lc app=leetcode id=27 lang=golang
 *
 * [27] Remove Element
 */

// @lc code=start
func removeElement(nums []int, val int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	counter := 0
	for i := 0; i < length; i++ {
		if nums[i] != val {
			nums[counter] = nums[i]
			counter++
		}
	}
	return counter
}

// @lc code=end
