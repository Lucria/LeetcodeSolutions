/*
 * @lc app=leetcode id=560 lang=golang
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
func subarraySum(nums []int, k int) int {
	allSums := map[int]int{0: 1}
	sum := 0
	count := 0

	for _, num := range nums {
		sum += num
		count += allSums[sum-k]
		allSums[sum]++
	}

	return count
}

// @lc code=end
