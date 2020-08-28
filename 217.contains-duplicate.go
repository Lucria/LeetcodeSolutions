/*
 * @lc app=leetcode id=217 lang=golang
 *
 * [217] Contains Duplicate
 */

// @lc code=start
func containsDuplicate(nums []int) bool {
	storage := make(map[int]int)

	for _, num := range nums {
		if storage[num] == 0 {
			storage[num] = 1
		} else {
			return true
		}
	}
	return false

	// Alternate approach is to sort it and look for duplicates side by side
}

// @lc code=end
