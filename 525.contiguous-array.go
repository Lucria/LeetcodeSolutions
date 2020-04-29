/*
 * @lc app=leetcode id=525 lang=golang
 *
 * [525] Contiguous Array
 */

// @lc code=start
func findMaxLength(nums []int) int {
	answer := 0
	count := 0
	counts := make(map[int]int)
	counts[0] = -1
	for i, s := range nums {
		if s == 1 {
			count++
		} else {
			count--
		}

		if val, ok := counts[count]; ok {
			if answer > i-val {
				answer = answer
			} else {
				answer = i - val
			}
		} else {
			counts[count] = i
		}
	}
	return answer
}

// @lc code=end
