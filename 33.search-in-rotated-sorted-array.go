/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
func search(nums []int, target int) int {
	low := 0
	high := len(nums) - 1
	n := len(nums)
	for low < high {
		var middle int = (low + high) / 2
		if nums[middle] > nums[high] {
			low = middle + 1
		} else {
			high = middle
		}
	}

	point := low
	low, high = 0, len(nums)-1
	for low <= high {
		var middle int = (low + high) / 2
		var realMiddle int = (middle + point) % n
		if nums[realMiddle] == target {
			return realMiddle
		}
		if nums[realMiddle] < target {
			low = middle + 1
		} else {
			high = middle - 1
		}
	}
	return -1
}

// @lc code=end
