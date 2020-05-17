/*
 * @lc app=leetcode id=201 lang=golang
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
func rangeBitwiseAnd(m int, n int) int {
	if m == 0 {
		return 0
	}
	var backZeros int = 0
	for m != n {
		m >>= 1
		n >>= 1
		backZeros++
	}
	return m << backZeros
}

// @lc code=end
