/*
 * @lc app=leetcode id=7 lang=golang
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.63%)
 * Likes:    2916
 * Dislikes: 4573
 * Total Accepted:    968.4K
 * Total Submissions: 3.8M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 *
 */
import {
	"math"
}

// @lc code=start
func reverse(x int) int {
	var newInt int = 0
	for x != 0 {
		remainder := x % 10
		newInt *= 10
		newInt += remainder
		x /= 10
	}
	if newInt > int(math.Pow(2, 31)-1) || newInt < int(math.Pow(-2, 31)) {
		return 0
	}
	return newInt
}

// @lc code=end
