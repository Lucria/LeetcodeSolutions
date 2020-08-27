/*
 * @lc app=leetcode id=189 lang=golang
 *
 * [189] Rotate Array
 */

// @lc code=start
func rotate(nums []int, k int) {
	length := len(nums)
	new := nums[length-k%length:]
	copy(nums, append(new, nums[:length-k%length]...))

	// This is not memory efficient
	// If truly want O(1) space then need iterate through and swap each element
	// Go to correct position of element
	// Store previous value as temp variable and swap to new value
	// Search for correct position of previous value
}

// @lc code=end
