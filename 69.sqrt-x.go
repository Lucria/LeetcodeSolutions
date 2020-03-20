/*
 * @lc app=leetcode id=69 lang=golang
 *
 * [69] Sqrt(x)
 */

// @lc code=start
func mySqrt(x int) int {
	if x == 0 {
		return 0
	}
	var left int = 1
	var right int = x
	var mid int = 0

	for {
		mid = (right + left) / 2
		if mid*mid == x {
			return mid
		} else if mid*mid > x {
			right = mid - 1
		} else {
			if (mid+1)*(mid+1) <= x {
				left = mid + 1
			} else {
				return mid
			}
		}
	}
	return -1
}

// @lc code=end
