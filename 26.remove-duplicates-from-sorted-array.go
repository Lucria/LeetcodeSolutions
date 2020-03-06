/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}
	count := 0
	for i := 1; i < length; i++ {
		if nums[i] != nums[count] {
			count++
			nums[count] = nums[i]
		}
	}
	return count + 1
}

// @lc code=end
